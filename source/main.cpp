// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

#include <iostream>

#include "llvm/Support/InitLLVM.h"

int main(int argc, char **argv) {
  llvm::InitLLVM llvm{argc, argv};

  std::cout << "Hello, World!" << std::endl;
  return 0;
}