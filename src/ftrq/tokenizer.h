#pragma once

#include <functional>
#include <string>
namespace ftrq {

struct tokenizer {
  std::string token;
  bool quoted = false;

  std::function<void(std::string)> on_token_accepted;

  void provide(char c) {
    if (c == '"') {
      quoted = not quoted;
    }

    if (isspace(c) and not quoted) {
      on_token_accepted(std::move(token));
      token.clear();
      return;
    }

    token += c;
  }
};

} // namespace ftrq