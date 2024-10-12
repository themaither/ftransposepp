#pragma once
#include "../debug.h"
namespace ftrq::commands {
template <typename T> inline void export_commands(T &target) {
  target[".exit"] = {.argument_count = 0, .execute = [](auto, auto) {
                       ftrq::debug::trace("Exiting");
                       exit(0);
                     }};
  target[".echo"] = {.argument_count = 1, .execute = [](auto, auto args) {
                       ftrq::debug::trace(args[0].c_str());
                     }};
}
} // namespace ftrq::commands