# fun (c) by Cade Weinberg
# 
# To the extent possible under law, the person who associated CC0 with
# fun has waived all copyright and related or neighboring rights
# to fun.
# 
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

cmake_minimum_required(VERSION 3.5...3.16)

add_executable(fun 
    ${FUN_SOURCE_DIR}/main.cpp
)
target_compile_options(fun PRIVATE ${FUN_COMPILE_FLAGS})
target_include_directories(fun PRIVATE ${FUN_INCLUDES})
target_link_libraries(fun PRIVATE llvm)
