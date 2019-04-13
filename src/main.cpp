#include "error.hpp"
#include <algorithm>
#include <iostream>
#include <outcome/outcome.hpp>
#include <string>

namespace lib {
using namespace tezt;

outcome::result<int> convert(std::string str) {
  if (str.empty())
    return ConversionErrc::EmptyString;

  if (!std::all_of(str.begin(), str.end(), ::isdigit))
    return ConversionErrc::IllegalChar;

  if (str.length() > 9)
    return ConversionErrc::TooLong;

  return atoi(str.c_str());
}

} // namespace lib

int main() {
  if (auto r = lib::convert("500")) {
    std::cout << "success " << r.value() << "\n";
  } else {
    std::cout << "error " << r.error() << "\n";
  }

  if (auto r = lib::convert("a")) {
    std::cout << "success " << r.value() << "\n";
  } else {
    std::cout << "error " << r.error() << "\n";
  }

  return 0;
}
