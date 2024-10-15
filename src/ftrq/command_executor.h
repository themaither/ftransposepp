#pragma once

#include <ftrq/command_list.h>
#include <ftrq/context.h>
#include <ftrq/model/command.h>
namespace ftrq {

struct command_executor {
  const ftrq::command_list &command_list;
  ftrq::context &context;

  enum class error { NONE, COMMAND_NOT_FOUND } error = error::NONE;

  void execute(ftrq::model::command &&command) {
    if (not command_list.contains(command.name)) {
      error = error::COMMAND_NOT_FOUND;
      return;
    }
    command_list.at(command.name).execute(context, command.args);
  }
};
} // namespace ftrq