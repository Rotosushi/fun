# fun (c) by Cade Weinberg
# 
# To the extent possible under law, the person who associated CC0 with
# fun has waived all copyright and related or neighboring rights
# to fun.
# 
# You should have received a copy of the CC0 legalcode along with this
# work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.
cmake_minimum_required(VERSION 3.5...3.16)

add_executable(fun_tests
    test_main.cpp 
)
target_compile_options(fun_tests PRIVATE ${FUN_COMPILE_FLAGS})
target_include_directories(fun_tests PRIVATE 
    ${FUN_INCLUDES}
    ${FUN_TEST_DIR}
)
target_link_libraries(fun_tests PRIVATE Boost::unit_test_framework)

