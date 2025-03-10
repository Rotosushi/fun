# fun (c) by Cade Weinberg
# 
# To the extent possible under law, the person who associated CC0 with
# fun has waived all copyright and related or neighboring rights
# to fun.
# 
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.
cmake_minimum_required(VERSION 3.5...3.16)

execute_process(
  COMMAND git rev-parse --short HEAD 
  OUTPUT_VARIABLE FUN_GIT_REVISION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(TIMESTAMP FUN_BUILD_TIME "%Y-%m-%d %H:%M:%S")

set(FUN_VERSION_STRING "")
string(APPEND FUN_VERSION_STRING 
"fun version ("
${FUN_VERSION_MAJOR}
"."
${FUN_VERSION_MINOR}
"."
${FUN_VERSION_PATCH}
") built at ("
${FUN_BUILD_TIME}
") git revision ("
${FUN_GIT_REVISION}
")"
)

configure_file(
    ${FUN_INCLUDE_DIR}/config/config.hpp.in
    ${FUN_INCLUDE_DIR}/config/config.hpp
)

add_executable(fun 
  ${FUN_SOURCE_DIR}/codegen/to_llvm.cpp

  ${FUN_SOURCE_DIR}/main.cpp
)
target_compile_options(fun PRIVATE ${FUN_COMPILE_FLAGS})
target_include_directories(fun PRIVATE ${FUN_INCLUDES})
target_link_libraries(fun PRIVATE LLVM)
