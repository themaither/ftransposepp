#pragma once

#include <filesystem>
#include <ftr/database.h>
#include <ftrq/model/file_mapping.h>
#include <ftrq/query.h>
#include <unordered_set>

namespace ftrq {

struct context {
  ftr::database &db;

  std::unordered_set<std::filesystem::path> selection;
  std::unordered_set<ftrq::model::file_mapping> target;

  context(ftr::database &db) : db(db){};

  void select(std::filesystem::path path) {
    std::filesystem::recursive_directory_iterator iter{path};
    for (auto node : iter) {
      selection.emplace(node.path());
    };
  };

  void apply_query(ftrq::query &&query) { target = std::move(query.result); }
};
} // namespace ftrq