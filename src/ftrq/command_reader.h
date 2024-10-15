#pragma once

#include <cstddef>
#include <ftrq/command.h>
#include <ftrq/command_list.h>
#include <print>
#include <string>
#include <vector>
namespace ftrq {
struct command_reader {
  const ftrq::command_list &command_list;
  ftrq::model::command command;
  bool done = false;

  command_reader(const ftrq::command_list &command_list)
      : command_list(command_list){};

  void accept(std::string &&token) {
    if (done) {
      return;
    }

    if (argument_count == -1) {
      set_command(std::move(token));
      if (argument_count == 0) {
        done = true;
      }
      return;
    }
    push_argument(std::move(token));
    if (--argument_count == 0) {
      done = true;
    }
  }

private:
  size_t argument_count = -1;

  void set_command(std::string &&token) {
    argument_count = get_argument_count(token);
    command.name = std::move(token);
  }

  void push_argument(std::string &&argument) {
    command.args.emplace_back(std::move(argument));
  }

  size_t get_argument_count(std::string &token) {
    return command_list.at(token).argument_count;
  }
};
} // namespace ftrq