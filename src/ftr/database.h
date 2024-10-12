#pragma once

#include <filesystem>
#include <fstream>
#include <string>
namespace ftr {
struct database {
  std::filesystem::path dbpath;
  std::filesystem::path sourcepath;

  static ftr::database open(std::filesystem::path &&path) {
    ftr::database database;
    std::filesystem::path &&absolute = std::filesystem::absolute(path);
    database.dbpath = path / ".trdb";

    std::fstream source{path / ".trdb/config/source"};
    std::string source_str;
    std::getline(source, source_str);
    database.sourcepath = {std::move(source_str)};
    return database;
  }
};
} // namespace ftr
