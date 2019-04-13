/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef EXAMPLE_ERROR_HPP
#define EXAMPLE_ERROR_HPP

#include <outcome/outcome.hpp>

namespace tezt {

enum class ConversionErrc {
  Success = 0,
  EmptyString,
  IllegalChar,
  TooLong,
};

} // namespace tezt

OUTCOME_HPP_DECLARE_ERROR(tezt, ConversionErrc);

#endif // EXAMPLE_ERROR_HPP
