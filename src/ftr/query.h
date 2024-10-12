#pragma once

#include <filesystem>
#include <ranges>
#include <unordered_set>
namespace ftr {
template <typename Range>
  requires std::ranges::view<Range> &&
           std::same_as<std::ranges::range_value_t<Range>,
                        std::filesystem::path>
struct query {
  const Range input;
  using Path = std::filesystem::path;
  using Set = std::unordered_set<std::filesystem::path>;
  Set result;

  void all() { result = std::ranges::to<Set>(input); }

  void contains(const char *part) {
    result =
        std::ranges::to<Set>(input | std::ranges::views::filter([&](auto node) {
                               return node.string().contains(part);
                             }));
  }
};
} // namespace ftr