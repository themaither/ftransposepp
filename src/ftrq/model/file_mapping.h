#pragma once

#include <cstddef>
#include <filesystem>
#include <functional>
namespace ftrq::model {
struct file_mapping {
  std::filesystem::path from;
  std::filesystem::path to;
};
} // namespace ftrq::model

template <> struct std::hash<ftrq::model::file_mapping> {
  size_t operator()(const ftrq::model::file_mapping &file_mapping) {
    return std::hash<std::filesystem::path>()(file_mapping.from);
  }
};