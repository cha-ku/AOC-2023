#include <iostream>

import input;
import part_one;
import part_two;

int main() {
  std::cout << "[test] The sum of all calibration values: "
            << part_one::correct_calibration_value(input::test_part1) << "\n";
  std::cout << "The sum of all calibration values: "
            << part_one::correct_calibration_value(input::day01) << "\n";
  std::cout << "[test] Sum of all calibration values spelled out: "
            << part_two::calibration_with_all_digits(input::test_part2) << "\n";
  std::cout << "Sum of all calibration values spelled out: "
            << part_two::calibration_with_all_digits(input::day01) << "\n";
}