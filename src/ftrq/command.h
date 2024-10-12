#pragma once

#include <string>
#include <vector>
namespace ftrq::model {
struct command {
  std::string name;
  std::vector<std::string> args;
};
} // namespace ftrq::model