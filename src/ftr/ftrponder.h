#pragma once

#include <array>
#include <filesystem>
#include <string>
#include <sys/types.h>
#include <unistd.h>
namespace ftr {

inline std::filesystem::path ponder() {
  std::string ftrponder = "ftrponder";
  std::string null = "\0";
  auto args = std::array<char *, 2>{ftrponder.data(), null.data()};
  std::array<int, 2> pipev;
  pipe(pipev.data());
  pid_t pid = fork();
  if (pid == 0) { // Child
    dup2(pipev[1], 1);
    execvpe("ftrponder", args.data(), environ);
  }
  std::string s;
  while (not s.ends_with('\n')) {
    s.append(1, '\0');
    read(pipev[0], (s.end() - 1).base(), 1);
  }
  return {s};
}

} // namespace ftr