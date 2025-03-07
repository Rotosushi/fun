// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file operand_tests.hpp
 * @brief Tests for [Operand](@ref Operand)
 */

#pragma once

#include <boost/test/unit_test.hpp>

#include "IR/operand.hpp"

BOOST_AUTO_TEST_SUITE(operand_tests)

BOOST_AUTO_TEST_CASE(operand_nil) {
    fun::IR::Operand A{};
    BOOST_TEST(A.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());

    A = fun::IR::Scalar::u8{0};
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{};
    fun::IR::Operand B{};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::Nil>() && B.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(A == B);
    BOOST_TEST(A == A);
    BOOST_TEST(A <= B);
    BOOST_TEST(A >= B);
    BOOST_TEST(!(A != B));
    BOOST_TEST(!(A < B));
    BOOST_TEST(!(A > B));
}

BOOST_AUTO_TEST_CASE(operand_bool) {
    fun::IR::Operand A{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());

    A = true;
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{true};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::Bool>() &&
                  B.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A == B);
    BOOST_TEST(A == A);
    BOOST_TEST(A <= B);
    BOOST_TEST(A >= B);
    BOOST_TEST(!(A != B));
    BOOST_TEST(!(A < B));
    BOOST_TEST(!(A > B));
}

BOOST_AUTO_TEST_CASE(operand_u8) {
    fun::IR::Operand A{fun::IR::Scalar::u8{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());

    A = fun::IR::Scalar::u8{0};
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::u8{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u8>() && B.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_u16) {
    fun::IR::Operand A{fun::IR::Scalar::u16{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::u16>());

    A = fun::IR::Scalar::u16{0};
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::u16{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u16>() && B.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_u32) {
    fun::IR::Operand A{fun::IR::Scalar::u32{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::u32>());

    A = fun::IR::Scalar::u32{0};
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::u32{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u32>() && B.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_u64) {
    fun::IR::Operand A{fun::IR::Scalar::u64{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::u64>());

    A = fun::IR::Scalar::u64{0};
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::u64{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u64>() && B.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_i8) {
    fun::IR::Operand A{fun::IR::Scalar::i8{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::i8>());

    A = fun::IR::Scalar::i8{0};
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::i8{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i8>() && B.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_i16) {
    fun::IR::Operand A{fun::IR::Scalar::i16{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::i16>());

    A = fun::IR::Scalar::i16{0};
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::i16{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i16>() && B.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_i32) {
    fun::IR::Operand A{fun::IR::Scalar::i32{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());

    A = fun::IR::Scalar::i32{0};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::i32{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i32>() && B.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_i64) {
    fun::IR::Operand A{fun::IR::Scalar::i64{0}};
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::i64>());

    A = fun::IR::Scalar::i64{0};
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::i64{1}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i64>() && B.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_f32) {
    fun::IR::Operand A{fun::IR::Scalar::f32{0.0f}};
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = fun::IR::Scalar::f32{0.0f};
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Scalar::f32{1.0f}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f32>() && B.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_f64) {
    fun::IR::Operand A{fun::IR::Scalar::f64{0.0}};
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar::f64{0.0};
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Operand B{fun::IR::Scalar::f64{1.0}};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f64>() && B.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_label) {
    fun::IR::Operand A{fun::IR::Label{0}};
    BOOST_TEST(A.is<fun::IR::Label>());
    BOOST_TEST(A.as<fun::IR::Label>().index == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Label>());

    A = fun::IR::Label{0};
    BOOST_TEST(A.is<fun::IR::Label>());
    BOOST_TEST(A.as<fun::IR::Label>().index == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Label{1}};
    BOOST_REQUIRE(A.is<fun::IR::Label>() && B.is<fun::IR::Label>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(operand_local) {
    fun::IR::Operand A{fun::IR::Local{0}};
    BOOST_TEST(A.is<fun::IR::Local>());
    BOOST_TEST(A.as<fun::IR::Local>().index == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 1);
    BOOST_TEST(!A.is<fun::IR::Local>());

    A = fun::IR::Local{0};
    BOOST_TEST(A.is<fun::IR::Local>());
    BOOST_TEST(A.as<fun::IR::Local>().index == 0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Operand B{fun::IR::Local{1}};
    BOOST_REQUIRE(A.is<fun::IR::Local>() && B.is<fun::IR::Local>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_SUITE_END()