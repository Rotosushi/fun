// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file main.cpp
 * @brief defines the entry point for the program.
 */

#include <iostream>

#include "llvm/Support/InitLLVM.h"

#include "IR/scalar.hpp"
#include "config/config.hpp"

int main(int argc, char **argv) {
  llvm::InitLLVM llvm{argc, argv};

  std::cout << fun::config::version << std::endl;

  fun::IR::Scalar scalar{0.0};

  return 0;
}