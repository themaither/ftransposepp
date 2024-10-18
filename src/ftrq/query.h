#pragma once

#include <filesystem>
#include <unordered_map>
#include <unordered_set>
namespace ftrq {
struct query {
  const std::unordered_set<std::filesystem::path> &input;
  std::unordered_map<std::filesystem::path, std::filesystem::path> result;

  void all() {
    for (const auto &path : input) {
      result[path] = path;
    }
  }

  void contains(const char *part) {}
};
} // namespace ftrq