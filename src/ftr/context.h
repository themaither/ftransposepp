#pragma once

#include "../utils/conserve.h"
#include "database.h"
#include <filesystem>
#include <system_error>
#include <unordered_set>
#include <vector>

namespace ftr {

struct context {
  ftr::database &db;

  std::unordered_set<std::filesystem::path> selection;

  context(ftr::database &db) : db(db){};

  void select(std::filesystem::path path) {
    std::filesystem::recursive_directory_iterator iter{path};
    for (auto node : iter) {
      selection.emplace(node.path());
    };
  };
};
} // namespace ftr