#include <iostream>
#include <limits>

template <typename T> T getValidInput(const std::string &prompt) {
  T input;
  std::cout << prompt;

  while (!(std::cin >> input)) {
    std::cout << "Invalid input. Please enter a valid value: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return input;
}