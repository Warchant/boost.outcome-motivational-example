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

outcome::result<void> try_(std::string str) {
  // just to demonstrate that OUTCOME_TRY is used
  OUTCOME_TRY(val, lib::convert(str));
  std::cout << "result: " << val << "\n";

  return outcome::success();
}

} // namespace lib

int main() {
  if (auto r = lib::try_("500"); !r) {
    std::cout << "error " << r.error() << "\n";
  }

  if (auto r = lib::try_("a"); !r) {
    std::cout << "error " << r.error() << "\n";
  }

  return 0;
}
