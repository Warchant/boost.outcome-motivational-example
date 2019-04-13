/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "error.hpp"

OUTCOME_CPP_DEFINE_CATEGORY(tezt, ConversionErrc, e) {
  using namespace tezt;
  switch (e) {
  case ConversionErrc::EmptyString:
    return "empty string";
  case ConversionErrc::IllegalChar:
    return "illegal char";
  case ConversionErrc::TooLong:
    return "too long";
  default:
    return "undefined";
  }
}
