#pragma once

#include "../ftr/context.h"
#include "commands/list.h"
#include <cstdlib>
#include <functional>
#include <span>
#include <string>
#include <unordered_map>
namespace ftrq {

struct command_info {
  size_t argument_count;
  std::function<void(ftr::context &, std::span<std::string>)> execute;
};

struct command_list
    : public std::unordered_map<std::string, ftrq::command_info> {
  static ftrq::command_list get_default_commands() {
    ftrq::command_list commands;
    commands::export_commands(commands);
    return commands;
  }
};

} // namespace ftrq