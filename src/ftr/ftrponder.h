#pragma once

#include <array>
#include <filesystem>
#include <ftrq/debug.h>
#include <optional>
#include <poll.h>
#include <string>
#include <sys/poll.h>
#include <sys/types.h>
#include <unistd.h>
namespace ftr {

inline std::optional<std::filesystem::path> ponder() {
  std::string ftrponder = "ftrponder";
  std::string null = "\0";
  auto args = std::array<char *, 2>{ftrponder.data(), null.data()};
  std::array<int, 2> pipeexec;
  pipe(pipeexec.data());

  pid_t pidexec = fork();
  if (pidexec == 0) { // Child
    dup2(pipeexec[1], 1);
    execvpe("ftrponder", args.data(), environ);
  }

  pollfd pollfd;
  pollfd.fd = pipeexec[0];
  pollfd.events = POLLIN;
  poll(&pollfd, 1, 200);

  if (pollfd.revents == 0) {
    return {};
  }

  std::array<char, 257> data;

  read(pipeexec[0], data.data(), 256);

  ftrq::debug::debug_msg("Done!");
  return std::filesystem::path{data.data()};
}

} // namespace ftr