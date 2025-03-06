// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

#pragma once

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_suite.hpp>

#include "IR/scalar.hpp"
#include "IR/value.hpp"

BOOST_AUTO_TEST_SUITE(value_tests)

BOOST_AUTO_TEST_CASE(value_nil) {
    fun::IR::Value A{};
    BOOST_TEST(A.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::Nil>());

    A = fun::IR::Value{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Nil>());

    A = fun::IR::Scalar::Nil{};
    fun::IR::Value B{};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::Nil>() && B.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(A == B);
    BOOST_TEST(A == A);
    BOOST_TEST(A <= B);
    BOOST_TEST(A >= B);
    BOOST_TEST(!(A != B));
    BOOST_TEST(!(A < B));
    BOOST_TEST(!(A > B));
}

BOOST_AUTO_TEST_CASE(value_bool) {
    fun::IR::Value A{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::Bool>());

    A = fun::IR::Value{false};
    BOOST_TEST(!A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = 0;
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == 0);

    A = false;

    fun::IR::Value B{false};
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

BOOST_AUTO_TEST_CASE(value_u8) {
    fun::IR::Value A{(fun::IR::Scalar::u8)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::u8>());

    A.get<fun::IR::Scalar::u8>() = (fun::IR::Scalar::u8)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)1u);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());

    A = (fun::IR::Scalar::u8)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::u8)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u8>() && B.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_u16) {
    fun::IR::Value A{(fun::IR::Scalar::u16)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::u16>());

    A.get<fun::IR::Scalar::u16>() = (fun::IR::Scalar::u16)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)1u);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u16>());

    A = (fun::IR::Scalar::u16)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::u16)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u16>() && B.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_u32) {
    fun::IR::Value A{(fun::IR::Scalar::u32)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::u32>());

    A.get<fun::IR::Scalar::u32>() = (fun::IR::Scalar::u32)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)1u);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u32>());

    A = (fun::IR::Scalar::u32)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::u32)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u32>() && B.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_u64) {
    fun::IR::Value A{(fun::IR::Scalar::u64)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::u64>());

    A.get<fun::IR::Scalar::u64>() = (fun::IR::Scalar::u64)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)1u);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u64>());

    A = (fun::IR::Scalar::u64)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::u64)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u64>() && B.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_i8) {
    fun::IR::Value A{(fun::IR::Scalar::i8)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::i8>());

    A.get<fun::IR::Scalar::i8>() = (fun::IR::Scalar::i8)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)1);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i8>());

    A = (fun::IR::Scalar::i8)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::i8)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i8>() && B.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_i16) {
    fun::IR::Value A{(fun::IR::Scalar::i16)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::i16>());

    A.get<fun::IR::Scalar::i16>() = (fun::IR::Scalar::i16)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)1);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i16>());

    A = (fun::IR::Scalar::i16)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::i16)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i16>() && B.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_i32) {
    fun::IR::Value A{(fun::IR::Scalar::i32)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::i32>());

    A.get<fun::IR::Scalar::i32>() = (fun::IR::Scalar::i32)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)1);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i32>());

    A = (fun::IR::Scalar::i32)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::i32)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i32>() && B.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_i64) {
    fun::IR::Value A{(fun::IR::Scalar::i64)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::i64>());

    A.get<fun::IR::Scalar::i64>() = (fun::IR::Scalar::i64)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)1);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i64>());

    A = (fun::IR::Scalar::i64)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{(fun::IR::Scalar::i64)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i64>() && B.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_f32) {
    fun::IR::Value A{0.0f};
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::f32>() = 1.0f;
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 1.0f);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = 0.0f;
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Value B{1.0f};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f32>() && B.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(value_f64) {
    fun::IR::Value A{0.0};
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.is<fun::IR::Scalar>());
    fun::IR::Scalar S = A.as<fun::IR::Scalar>();
    BOOST_TEST(S.is<fun::IR::Scalar::f64>());

    A.get<fun::IR::Scalar::f64>() = 1.0;
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 1.0);

    A = fun::IR::Value{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = 0.0;
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Value B{1.0};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f64>() && B.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_SUITE_END()
