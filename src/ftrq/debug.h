#pragma once

#include <format>
#include <print>
namespace ftrq {

struct debug {
  static void trace(const char *message) {
    std::println("\e[2;3m[TRACE] {}\e[0m", message);
  }

  static void debug_msg(const char *message) {
    std::println("\e[2;3m[DEBUG] {}\e[0m", message);
  }

  static void error(const char *message) {
    std::println("\e[1;3;31m[ERROR] {}\e[0m", message);
  }
};
} // namespace ftrq