#pragma once

#include <filesystem>
#include <fstream>
#include <ios>
#include <string>
namespace ftr {
struct database {
  std::filesystem::path dbpath;
  std::filesystem::path sourcepath;

  database(std::filesystem::path &&path) {
    std::filesystem::path &&absolute = std::filesystem::absolute(path);
    dbpath = absolute / ".trdb";
    auto sourcetarget = dbpath / "config/source";
    std::ifstream source(sourcetarget, std::ios_base::in);
    std::string source_str;

    while (source.good()) {
      source_str += source.get();
    }

    sourcepath = {std::move(source_str)};
  }
};
} // namespace ftr
