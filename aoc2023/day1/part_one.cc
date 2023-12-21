module;

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string_view>

export module part_one;

export namespace part_one {
auto correct_calibration_value(std::string_view input) -> int64_t {
  // drop characters that are not digits
  constexpr auto not_digit = [](char c) { return !std::isdigit(c); };
  constexpr auto fst = std::views::drop_while(not_digit);
  constexpr auto reverse_fst = std::views::reverse | fst;

  constexpr auto to_decimal = [](auto &&rng) -> int64_t {
    return *rng.begin() - '0';
  };

  return std::ranges::fold_left(input | std::views::split('\n'), 0z,
                                [&](int64_t acc, auto &&line) {
                                  auto digit = to_decimal(line | fst) * 10 +
                                               to_decimal(line | reverse_fst);
                                  return acc + digit;
                                });
}
} // namespace part_one