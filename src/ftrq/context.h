#pragma once

#include <filesystem>
#include <ftr/database.h>
#include <ftrq/query.h>
#include <ranges>
#include <unordered_set>

namespace ftrq {

struct context {
  ftr::database &db;

  std::unordered_set<std::filesystem::path> selection;
  std::unordered_set<std::filesystem::path> target;

  context(ftr::database &db) : db(db){};

  void select(std::filesystem::path path) {
    std::filesystem::recursive_directory_iterator iter{path};
    for (auto node : iter) {
      selection.emplace(node.path());
    };
  };

  void apply_query(ftrq::query<std::ranges::ref_view<
                       std::unordered_set<std::filesystem::path>>> &&query) {
    target = std::move(query.result);
  }
};
} // namespace ftrq