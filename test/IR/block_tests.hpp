// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file block_tests.hpp
 * @brief Defines tests for [Block](@ref Block)
 */

#pragma once

#include <boost/test/unit_test.hpp>

#include "IR/block.hpp"

BOOST_AUTO_TEST_SUITE(block_tests)

BOOST_AUTO_TEST_CASE(block_append) {
    fun::IR::Block B;
    B.append(fun::IR::Instruction::Opcode::Ret, fun::IR::Scalar{1});
    BOOST_TEST(B.size() == 1);
    BOOST_TEST(B[0].opcode() == fun::IR::Instruction::Opcode::Ret);
    BOOST_TEST(B[0].format() == fun::IR::Instruction::Format::Unary);
    BOOST_TEST(B[0].A().is<fun::IR::Scalar::i32>());
    BOOST_TEST(B[0].A().as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(B[0].B().is<fun::IR::Scalar::Nil>());
    BOOST_TEST(B[0].C().is<fun::IR::Scalar::Nil>());
}

BOOST_AUTO_TEST_SUITE_END()