// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file operand.hpp
 * @brief Defines [Operand](@ref Operand)
 */

#pragma once

#include "IR/scalar.hpp"

namespace fun::IR {

/**
 * @class Operand
 * @brief Represents an operand to an Instruction
 */
class Operand {
  public:
    using Label = Scalar::u32;
    using Local = Scalar::u32;

  private:
};

} // namespace fun::IR