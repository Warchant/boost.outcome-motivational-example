/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef OUTCOME_HPP
#define OUTCOME_HPP

#include <boost/outcome.hpp>
//#include "outcome-single-header.hpp"
#include "outcome-register.hpp"

namespace outcome = BOOST_OUTCOME_V2_NAMESPACE;  // required to be here

#define OUTCOME_TRY(...) BOOST_OUTCOME_TRY(__VA_ARGS__)

#endif  // OUTCOME_HPP
