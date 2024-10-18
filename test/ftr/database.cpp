#include <ftr/database.h>
#include <stdexcept>
#include <unistd.h>

int main(int argc, char **argv) {
  ftr::database db("test_db");
  if (db.dbpath.empty()) {
    throw std::runtime_error("dbpath is not set");
  }
  if (db.sourcepath.empty()) {
    throw std::runtime_error("sourcepath is not set");
  }
}