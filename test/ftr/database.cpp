#include <ftr/database.h>
#include <stdexcept>
#include <unistd.h>

int main() {
  ftr::database db("test/test_db");
  if (db.dbpath.empty()) {
    throw std::runtime_error("dbpath is not set");
  }
  if (db.sourcepath.empty()) {
    throw std::runtime_error("sourcepath is not set");
  }
}