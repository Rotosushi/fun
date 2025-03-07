// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file instruction_tests.hpp
 * @brief Defines tests for [Instruction](@ref Instruction)
 */

#pragma once

#include <boost/test/unit_test.hpp>

#include "IR/instruction.hpp"

BOOST_AUTO_TEST_SUITE(instruction_tests)

BOOST_AUTO_TEST_CASE(instruction_ret) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Ret,
                           fun::IR::Scalar{1}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Ret);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Unary);
    BOOST_TEST(I.A().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.A().as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(I.B().is<fun::IR::Scalar::Nil>());
    BOOST_TEST(I.C().is<fun::IR::Scalar::Nil>());
}

BOOST_AUTO_TEST_CASE(instruction_call) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Call,
                           fun::IR::Local{0},
                           fun::IR::Local{1},
                           fun::IR::Local{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Call);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Local>());
    BOOST_TEST(I.B().as<fun::IR::Local>().index == 1);
    BOOST_TEST(I.C().is<fun::IR::Local>());
    BOOST_TEST(I.C().as<fun::IR::Local>().index == 2);
}

BOOST_AUTO_TEST_CASE(instruction_load) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Load,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{1}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Load);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Binary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(I.C().is<fun::IR::Scalar::Nil>());
}

BOOST_AUTO_TEST_CASE(instruction_neg) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Neg,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{1}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Neg);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Binary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(I.C().is<fun::IR::Scalar::Nil>());
}

BOOST_AUTO_TEST_CASE(instruction_add) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Add,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{2},
                           fun::IR::Scalar::i32{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Add);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 2);
    BOOST_TEST(I.C().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.C().as<fun::IR::Scalar::i32>() == 2);
}

BOOST_AUTO_TEST_CASE(instruction_sub) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Sub,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{2},
                           fun::IR::Scalar::i32{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Sub);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 2);
    BOOST_TEST(I.C().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.C().as<fun::IR::Scalar::i32>() == 2);
}

BOOST_AUTO_TEST_CASE(instruction_mul) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Mul,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{2},
                           fun::IR::Scalar::i32{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Mul);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 2);
    BOOST_TEST(I.C().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.C().as<fun::IR::Scalar::i32>() == 2);
}

BOOST_AUTO_TEST_CASE(instruction_div) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Div,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{2},
                           fun::IR::Scalar::i32{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Div);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 2);
    BOOST_TEST(I.C().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.C().as<fun::IR::Scalar::i32>() == 2);
}

BOOST_AUTO_TEST_CASE(instruction_rem) {
    fun::IR::Instruction I{fun::IR::Instruction::Opcode::Rem,
                           fun::IR::Local{0},
                           fun::IR::Scalar::i32{2},
                           fun::IR::Scalar::i32{2}};
    BOOST_TEST(I.opcode() == fun::IR::Instruction::Opcode::Rem);
    BOOST_TEST(I.format() == fun::IR::Instruction::Format::Ternary);
    BOOST_TEST(I.A().is<fun::IR::Local>());
    BOOST_TEST(I.A().as<fun::IR::Local>().index == 0);
    BOOST_TEST(I.B().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.B().as<fun::IR::Scalar::i32>() == 2);
    BOOST_TEST(I.C().is<fun::IR::Scalar::i32>());
    BOOST_TEST(I.C().as<fun::IR::Scalar::i32>() == 2);
}

BOOST_AUTO_TEST_SUITE_END()