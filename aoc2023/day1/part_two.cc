module;

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string_view>

export module part_two;

namespace {
constexpr std::array<std::string_view, 20> all_digits = {
    "0",    "1",    "2",   "3",     "4",     "5",   "6",
    "7",    "8",    "9",   "zero",  "one",   "two", "three",
    "four", "five", "six", "seven", "eight", "nine"};

auto to_digit(std::string_view line) -> int64_t {
  auto match = std::ranges::find_if(
      all_digits, [&](auto &&digit) { return line.starts_with(digit); });
  if (match == all_digits.end()) {
    return -1;
  };
  auto digit = std::distance(all_digits.begin(), match);
  if (digit >= 10)
    return digit - 10;
  return digit;
}
} // namespace

export namespace part_two {
auto calibration_with_all_digits(std::string_view input) -> int64_t {
  return std::ranges::fold_left(
      input | std::views::split('\n'), 0z, [&](int64_t acc, auto &&line) {
        int64_t fst = -1;
        int64_t snd = -1;

        for (auto pos : std::views::iota(line.begin(), line.end())) {
          auto substring = std::string_view(pos, line.end());

          if (int64_t digit = to_digit(substring); digit != -1) {
            if (fst == -1) {
              fst = digit;
            }
            snd = digit;
          }
        }
        // std::cout << std::string_view(line) << " - " << fst << " , " << snd
        //<< std::endl;
        return acc + fst * 10 + snd;
      });
}
} // namespace part_two