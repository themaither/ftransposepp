#include <ftr/database.h>
#include <ftr/ftrponder.h>
#include <ftrq/command_executor.h>
#include <ftrq/command_list.h>
#include <ftrq/command_reader.h>
#include <ftrq/context.h>
#include <ftrq/debug.h>
#include <ftrq/tokenizer.h>
#include <iostream>
#include <optional>
#include <utility>

void handle_error(enum ftrq::command_executor::error &error) {
  using type = ftrq::command_executor;
  switch (error) {
  default:
    return;
  case type::error::COMMAND_NOT_FOUND:
    ftrq::debug::error("Command not found");
    error = type::error::NONE;
    return;
  }
}

struct pondererror_t {};
[[noreturn]] void handle_error(pondererror_t) {
  ftrq::debug::error("Not inside valid database");
  exit(1);
}

ftr::database open_database() {
  auto &&a = ftr::ponder();
  if (not a) {
    handle_error(pondererror_t{});
  }
  return ftr::database{a.value()};
}

int main() {
  ftr::database database = open_database();
  ftrq::context context{database};
  ftrq::tokenizer tokenizer;
  ftrq::command_list list = ftrq::command_list::get_default_commands();
  ftrq::command_executor command_executor{list, context};
  ftrq::command_reader command_reader{list};

  tokenizer.on_token_accepted = [&](std::string &&token) {
    command_reader.accept(std::move(token));
    if (command_reader.done) {
      command_executor.execute(std::move(command_reader.command));
      handle_error(command_executor.error);
      command_reader.~command_reader();
      new (&command_reader) ftrq::command_reader{list};
    }
  };

  while (std::cin.good()) {
    char c = std::cin.get();
    tokenizer.provide(c);
  }
}