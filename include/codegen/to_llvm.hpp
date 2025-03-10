// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file to_llvm.hpp
 * @brief Defines functions which convert fun IR to LLVM IR
 */

#pragma once

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

#include "env/context.hpp"

#include "IR/scalar.hpp"
#include "IR/type.hpp"

namespace fun::codegen {

llvm::Type *to_llvm(IR::Type::Ptr const &type, env::Context &ctx);

llvm::Constant *to_llvm(IR::Scalar const &scalar, env::Context &ctx);

} // namespace fun::codegen
