#pragma once

#include <filesystem>
namespace ftrq::model {
struct file_mapping {
  std::filesystem::path from;
  std::filesystem::path to;
};
} // namespace ftrq::model