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

BOOST_AUTO_TEST_SUITE(scalar_tests)

BOOST_AUTO_TEST_CASE(scalar_nil) {
    fun::IR::Scalar A{};
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

    A = fun::IR::Scalar{1};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(!A.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = fun::IR::Scalar::Nil{};

    fun::IR::Scalar B{};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::Nil>() && B.is<fun::IR::Scalar::Nil>());
    BOOST_TEST(A == B);
    BOOST_TEST(A == A);
    BOOST_TEST(A <= B);
    BOOST_TEST(A >= B);
    BOOST_TEST(!(A != B));
    BOOST_TEST(!(A < B));
    BOOST_TEST(!(A > B));
}

BOOST_AUTO_TEST_CASE(scalar_bool) {
    fun::IR::Scalar A{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = fun::IR::Scalar{false};
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>() == false);

    A = fun::IR::Scalar{0.0f};
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::Bool>());

    A = false;
    fun::IR::Scalar B{true};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::Bool>() &&
                  B.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u8) {
    fun::IR::Scalar A{(fun::IR::Scalar::u8)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::u8>() = (fun::IR::Scalar::u8)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)1u);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u8>());

    A = (fun::IR::Scalar::u8)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A.as<fun::IR::Scalar::u8>() == (fun::IR::Scalar::u8)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::u8)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u8>() && B.is<fun::IR::Scalar::u8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u16) {
    fun::IR::Scalar A{(fun::IR::Scalar::u16)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::u16>() = (fun::IR::Scalar::u16)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)1u);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u16>());

    A = (fun::IR::Scalar::u16)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A.as<fun::IR::Scalar::u16>() == (fun::IR::Scalar::u16)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::u16)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u16>() && B.is<fun::IR::Scalar::u16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u32) {
    fun::IR::Scalar A{(fun::IR::Scalar::u32)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::u32>() = (fun::IR::Scalar::u32)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)1u);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u32>());

    A = (fun::IR::Scalar::u32)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A.as<fun::IR::Scalar::u32>() == (fun::IR::Scalar::u32)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::u32)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u32>() && B.is<fun::IR::Scalar::u32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u64) {
    fun::IR::Scalar A{(fun::IR::Scalar::u64)0u};
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::u64>() = (fun::IR::Scalar::u64)1u;
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)1u);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::u64>());

    A = (fun::IR::Scalar::u64)0u;
    BOOST_TEST(A.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A.as<fun::IR::Scalar::u64>() == (fun::IR::Scalar::u64)0u);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::u64)1u};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::u64>() && B.is<fun::IR::Scalar::u64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i8) {
    fun::IR::Scalar A{(fun::IR::Scalar::i8)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::i8>() = (fun::IR::Scalar::i8)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)1);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i8>());

    A = (fun::IR::Scalar::i8)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A.as<fun::IR::Scalar::i8>() == (fun::IR::Scalar::i8)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::i8)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i8>() && B.is<fun::IR::Scalar::i8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i16) {
    fun::IR::Scalar A{(fun::IR::Scalar::i16)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::i16>() = (fun::IR::Scalar::i16)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)1);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i16>());

    A = (fun::IR::Scalar::i16)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A.as<fun::IR::Scalar::i16>() == (fun::IR::Scalar::i16)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::i16)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i16>() && B.is<fun::IR::Scalar::i16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i32) {
    fun::IR::Scalar A{(fun::IR::Scalar::i32)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::i32>() = (fun::IR::Scalar::i32)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)1);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i32>());

    A = (fun::IR::Scalar::i32)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A.as<fun::IR::Scalar::i32>() == (fun::IR::Scalar::i32)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::i32)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i32>() && B.is<fun::IR::Scalar::i32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i64) {
    fun::IR::Scalar A{(fun::IR::Scalar::i64)0};
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::i64>() = (fun::IR::Scalar::i64)1;
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)1);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::i64>());

    A = (fun::IR::Scalar::i64)0;
    BOOST_TEST(A.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A.as<fun::IR::Scalar::i64>() == (fun::IR::Scalar::i64)0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{(fun::IR::Scalar::i64)1};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::i64>() && B.is<fun::IR::Scalar::i64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_f32) {
    fun::IR::Scalar A{0.0f};
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A.get<fun::IR::Scalar::f32>() = 1.0f;
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 1.0f);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A = 0.0f;
    BOOST_TEST(A.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A.as<fun::IR::Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    fun::IR::Scalar B{1.0f};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f32>() && B.is<fun::IR::Scalar::f32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_f64) {
    fun::IR::Scalar A{0.0};
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    A.get<fun::IR::Scalar::f64>() = 1.0;
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 1.0);

    A = fun::IR::Scalar{true};
    BOOST_TEST(A.is<fun::IR::Scalar::Bool>());
    BOOST_TEST(A.as<fun::IR::Scalar::Bool>());
    BOOST_TEST(!A.is<fun::IR::Scalar::f64>());

    A = 0.0;
    BOOST_TEST(A.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A.as<fun::IR::Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<fun::IR::Scalar::f32>());

    fun::IR::Scalar B{1.0};
    BOOST_REQUIRE(A.is<fun::IR::Scalar::f64>() && B.is<fun::IR::Scalar::f64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_SUITE_END()