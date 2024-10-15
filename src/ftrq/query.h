#pragma once

#include "ftrq/model/file_mapping.h"
#include <filesystem>
#include <ranges>
#include <unordered_set>
namespace ftrq {
struct query {
  const std::unordered_set<std::filesystem::path> &input;
  using Path = std::filesystem::path;
  using Set = std::unordered_set<ftrq::model::file_mapping>;
  Set result;

  void all() { result = std::ranges::to<Set>(input); }

  void contains(const char *part) {
    auto range = input | std::ranges::views::filter([&](auto node) {
                   return node.string().contains(part);
                 });

    result.insert(range.begin(), range.end());
  }
};
} // namespace ftrq