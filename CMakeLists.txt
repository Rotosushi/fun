# fun (c) by Cade Weinberg
# 
# To the extent possible under law, the person who associated CC0 with
# fun has waived all copyright and related or neighboring rights
# to fun.
# 
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

cmake_minimum_required(VERSION 3.5...3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CMAKE_C_STANDARD: ${CMAKE_C_STANDARD}")
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

project(FUN 
    VERSION 0.0.0 
    LANGUAGES C CXX
    DESCRIPTION "A toy compiler for a toy language, for fun!"
)

find_package(LLVM REQUIRED CONFIG 20.1.0)
find_package(Boost REQUIRED CONFIG)

if (MSVC)
    set(FUN_WARNINGS /W4 /WX)
    set(FUN_SANITIZE /fsanitize=address)
else() # assume GCC or Clang. This is fragile.
    set(FUN_WARNINGS -Wall -Wdeprecated -Wextra -Wpedantic -Wconversion)
    set(FUN_SANITIZE -fsanitize=address,undefined,leak)
endif()

set(FUN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(FUN_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)

set(FUN_COMPILE_FLAGS ${FUN_WARNINGS})

set(FUN_INCLUDES 
    ${FUN_INCLUDE_DIR}
    ${LLVM_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_subdirectory(${FUN_SOURCE_DIR})
