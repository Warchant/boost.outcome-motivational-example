#include "outcome-helper.hpp"
#include <iostream>
#include <outcome.hpp>
#include <string>

namespace outcome = OUTCOME_V2_NAMESPACE;

enum class ConversionErrc {
  Success = 0,     // 0 should not represent an error
  EmptyString = 1, // (for rationale, see tutorial on error codes)
  IllegalChar = 2,
  TooLong = 3,
};

enum class DivisionErrc {
  DivisionByZero = 1,
};

// clang-format off
OUTCOME_REGISTER_ERROR(DivisionErrc,
    (DivisionErrc::DivisionByZero, "we can't divide by 0")
);

OUTCOME_REGISTER_ERROR(ConversionErrc,
    (ConversionErrc::Success, "success")
    (ConversionErrc::EmptyString, "empty string")
    (ConversionErrc::IllegalChar, "illegal char")
    (ConversionErrc::TooLong, "too long")
);
// clang-format on

outcome::result<int> convert(std::string str) {
  if (str.empty())
    return ConversionErrc::EmptyString;

  if (!std::all_of(str.begin(), str.end(), ::isdigit))
    return ConversionErrc::IllegalChar;

  if (str.length() > 9)
    return ConversionErrc::TooLong;

  return atoi(str.c_str());
}

outcome::result<int> divide(int a, int b) {
  if (b == 0)
    return DivisionErrc::DivisionByZero;

  return a / b;
}

outcome::result<int> convert_and_divide(std::string a, std::string b) {
  OUTCOME_TRY(valA, convert(a));
  OUTCOME_TRY(valB, convert(b));
  OUTCOME_TRY(valDiv, divide(valA, valB));
  return valDiv;
}

template <typename T> void check(T &&f) {
  if (auto r = f()) {
    auto val = r.value();
    std::cout << val << std::endl;
  } else {
    auto e = r.error();
    std::cout << e.category().name() << " | " << e.message() << std::endl;
  }
}

int main() {
  // prints 250
  check([]() { return convert_and_divide("500", "2"); });

  // prints DivisionErrc | we can't divide by 0
  check([]() { return convert_and_divide("500", "0"); });

  // prints ConversionErrc | illegal char
  check([]() { return convert_and_divide("a", "0"); });

  /// produces warning:
  //  /Users/bogdan/tools/boost.outcome-motivational-example/main.cpp:76:3:
  //  warning: ignoring return value of function declared with 'nodiscard'
  //  attribute [-Wunused-result] convert("s");
  //  ^~~~~~~ ~~~

  convert("s");

  return 0;
}
