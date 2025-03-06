# fun (c) by Cade Weinberg
# 
# To the extent possible under law, the person who associated CC0 with
# fun has waived all copyright and related or neighboring rights
# to fun.
# 
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

cmake_minimum_required(VERSION 3.5...3.16)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(FUN 
    VERSION 0.0.0 
    LANGUAGES CXX
    DESCRIPTION "A toy compiler for a toy language, for fun!"
)

set(FUN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(FUN_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)
set(FUN_DEPS_DIR ${PROJECT_SOURCE_DIR}/deps)

set(FUN_CACHED_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE Release)

set(LLVM_ENABLE_PROJECTS lld)
set(LLVM_USE_LINKER mold)
set(LLVM_TARGETS_TO_BUILD X86)
add_subdirectory(${FUN_DEPS_DIR}/llvm-project/llvm)

set(CMAKE_BUILD_TYPE ${FUN_CACHED_BUILD_TYPE})

find_package(Boost REQUIRED)

if (MSVC)
    set(FUN_WARNINGS /W4 /WX)
    set(FUN_SANITIZE /fsanitize=address)
else() # assume GCC or Clang. This is fragile.
    set(FUN_WARNINGS -Wall -Wdeprecated -Wextra -Wpedantic -Wconversion -Werror)
    set(FUN_SANITIZE -fsanitize=address,undefined,leak)
endif()

set(FUN_COMPILE_FLAGS ${FUN_WARNINGS})

set(FUN_INCLUDES 
    ${FUN_INCLUDE_DIR}
    ${FUN_DEPS_DIR}/llvm-project/llvm/include
)

add_subdirectory(${FUN_SOURCE_DIR})
