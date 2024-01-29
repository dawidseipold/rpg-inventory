#include "../includes/getValidInput.h"

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

template int getValidInput<int>(const std::string &prompt);
template float getValidInput<float>(const std::string &prompt);
template double getValidInput<double>(const std::string &prompt);
template std::string getValidInput<std::string>(const std::string &prompt);