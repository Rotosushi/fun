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

using namespace fun::IR;

BOOST_AUTO_TEST_SUITE(scalar_tests)

BOOST_AUTO_TEST_CASE(scalar_nil) {
    Scalar A{};
    BOOST_TEST(A.is<Scalar::Nil>());
    BOOST_TEST(!A.is<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::u8>());
    BOOST_TEST(!A.is<Scalar::u16>());
    BOOST_TEST(!A.is<Scalar::u32>());
    BOOST_TEST(!A.is<Scalar::u64>());
    BOOST_TEST(!A.is<Scalar::i8>());
    BOOST_TEST(!A.is<Scalar::i16>());
    BOOST_TEST(!A.is<Scalar::i32>());
    BOOST_TEST(!A.is<Scalar::i64>());
    BOOST_TEST(!A.is<Scalar::f32>());
    BOOST_TEST(!A.is<Scalar::f64>());

    A = Scalar{1};
    BOOST_TEST(A.is<Scalar::i32>());
    BOOST_TEST(!A.is<Scalar::Nil>());
    BOOST_TEST(!A.is<Scalar::f32>());

    A = Scalar::Nil{};

    Scalar B{};
    BOOST_REQUIRE(A.is<Scalar::Nil>() && B.is<Scalar::Nil>());
    BOOST_TEST(A == B);
    BOOST_TEST(A == A);
    BOOST_TEST(A <= B);
    BOOST_TEST(A >= B);
    BOOST_TEST(!(A != B));
    BOOST_TEST(!(A < B));
    BOOST_TEST(!(A > B));
}

BOOST_AUTO_TEST_CASE(scalar_bool) {
    Scalar A{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::f32>());

    A = Scalar{false};
    BOOST_TEST(A.as<Scalar::Bool>() == false);

    A = Scalar{0.0f};
    BOOST_TEST(A.is<Scalar::f32>());
    BOOST_TEST(A.as<Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<Scalar::Bool>());

    A = false;
    Scalar B{true};
    BOOST_REQUIRE(A.is<Scalar::Bool>() && B.is<Scalar::Bool>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u8) {
    Scalar A{(Scalar::u8)0u};
    BOOST_TEST(A.is<Scalar::u8>());
    BOOST_TEST(A.as<Scalar::u8>() == (Scalar::u8)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::u8>() = (Scalar::u8)1u;
    BOOST_TEST(A.as<Scalar::u8>() == (Scalar::u8)1u);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::u8>());

    A = (Scalar::u8)0u;
    BOOST_TEST(A.is<Scalar::u8>());
    BOOST_TEST(A.as<Scalar::u8>() == (Scalar::u8)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::u8)1u};
    BOOST_REQUIRE(A.is<Scalar::u8>() && B.is<Scalar::u8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u16) {
    Scalar A{(Scalar::u16)0u};
    BOOST_TEST(A.is<Scalar::u16>());
    BOOST_TEST(A.as<Scalar::u16>() == (Scalar::u16)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::u16>() = (Scalar::u16)1u;
    BOOST_TEST(A.as<Scalar::u16>() == (Scalar::u16)1u);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::u16>());

    A = (Scalar::u16)0u;
    BOOST_TEST(A.is<Scalar::u16>());
    BOOST_TEST(A.as<Scalar::u16>() == (Scalar::u16)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::u16)1u};
    BOOST_REQUIRE(A.is<Scalar::u16>() && B.is<Scalar::u16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u32) {
    Scalar A{(Scalar::u32)0u};
    BOOST_TEST(A.is<Scalar::u32>());
    BOOST_TEST(A.as<Scalar::u32>() == (Scalar::u32)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::u32>() = (Scalar::u32)1u;
    BOOST_TEST(A.as<Scalar::u32>() == (Scalar::u32)1u);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::u32>());

    A = (Scalar::u32)0u;
    BOOST_TEST(A.is<Scalar::u32>());
    BOOST_TEST(A.as<Scalar::u32>() == (Scalar::u32)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::u32)1u};
    BOOST_REQUIRE(A.is<Scalar::u32>() && B.is<Scalar::u32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_u64) {
    Scalar A{(Scalar::u64)0u};
    BOOST_TEST(A.is<Scalar::u64>());
    BOOST_TEST(A.as<Scalar::u64>() == (Scalar::u64)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::u64>() = (Scalar::u64)1u;
    BOOST_TEST(A.as<Scalar::u64>() == (Scalar::u64)1u);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::u64>());

    A = (Scalar::u64)0u;
    BOOST_TEST(A.is<Scalar::u64>());
    BOOST_TEST(A.as<Scalar::u64>() == (Scalar::u64)0u);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::u64)1u};
    BOOST_REQUIRE(A.is<Scalar::u64>() && B.is<Scalar::u64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i8) {
    Scalar A{(Scalar::i8)0};
    BOOST_TEST(A.is<Scalar::i8>());
    BOOST_TEST(A.as<Scalar::i8>() == (Scalar::i8)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::i8>() = (Scalar::i8)1;
    BOOST_TEST(A.as<Scalar::i8>() == (Scalar::i8)1);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::i8>());

    A = (Scalar::i8)0;
    BOOST_TEST(A.is<Scalar::i8>());
    BOOST_TEST(A.as<Scalar::i8>() == (Scalar::i8)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::i8)1};
    BOOST_REQUIRE(A.is<Scalar::i8>() && B.is<Scalar::i8>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i16) {
    Scalar A{(Scalar::i16)0};
    BOOST_TEST(A.is<Scalar::i16>());
    BOOST_TEST(A.as<Scalar::i16>() == (Scalar::i16)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::i16>() = (Scalar::i16)1;
    BOOST_TEST(A.as<Scalar::i16>() == (Scalar::i16)1);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::i16>());

    A = (Scalar::i16)0;
    BOOST_TEST(A.is<Scalar::i16>());
    BOOST_TEST(A.as<Scalar::i16>() == (Scalar::i16)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::i16)1};
    BOOST_REQUIRE(A.is<Scalar::i16>() && B.is<Scalar::i16>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i32) {
    Scalar A{(Scalar::i32)0};
    BOOST_TEST(A.is<Scalar::i32>());
    BOOST_TEST(A.as<Scalar::i32>() == (Scalar::i32)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::i32>() = (Scalar::i32)1;
    BOOST_TEST(A.as<Scalar::i32>() == (Scalar::i32)1);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::i32>());

    A = (Scalar::i32)0;
    BOOST_TEST(A.is<Scalar::i32>());
    BOOST_TEST(A.as<Scalar::i32>() == (Scalar::i32)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::i32)1};
    BOOST_REQUIRE(A.is<Scalar::i32>() && B.is<Scalar::i32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_i64) {
    Scalar A{(Scalar::i64)0};
    BOOST_TEST(A.is<Scalar::i64>());
    BOOST_TEST(A.as<Scalar::i64>() == (Scalar::i64)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::i64>() = (Scalar::i64)1;
    BOOST_TEST(A.as<Scalar::i64>() == (Scalar::i64)1);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::i64>());

    A = (Scalar::i64)0;
    BOOST_TEST(A.is<Scalar::i64>());
    BOOST_TEST(A.as<Scalar::i64>() == (Scalar::i64)0);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{(Scalar::i64)1};
    BOOST_REQUIRE(A.is<Scalar::i64>() && B.is<Scalar::i64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_f32) {
    Scalar A{0.0f};
    BOOST_TEST(A.is<Scalar::f32>());
    BOOST_TEST(A.as<Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<Scalar::f64>());

    A.get<Scalar::f32>() = 1.0f;
    BOOST_TEST(A.as<Scalar::f32>() == 1.0f);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::f32>());

    A = 0.0f;
    BOOST_TEST(A.is<Scalar::f32>());
    BOOST_TEST(A.as<Scalar::f32>() == 0.0f);
    BOOST_TEST(!A.is<Scalar::f64>());

    Scalar B{1.0f};
    BOOST_REQUIRE(A.is<Scalar::f32>() && B.is<Scalar::f32>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_CASE(scalar_f64) {
    Scalar A{0.0};
    BOOST_TEST(A.is<Scalar::f64>());
    BOOST_TEST(A.as<Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<Scalar::f32>());

    A.get<Scalar::f64>() = 1.0;
    BOOST_TEST(A.as<Scalar::f64>() == 1.0);

    A = Scalar{true};
    BOOST_TEST(A.is<Scalar::Bool>());
    BOOST_TEST(A.as<Scalar::Bool>());
    BOOST_TEST(!A.is<Scalar::f64>());

    A = 0.0;
    BOOST_TEST(A.is<Scalar::f64>());
    BOOST_TEST(A.as<Scalar::f64>() == 0.0);
    BOOST_TEST(!A.is<Scalar::f32>());

    Scalar B{1.0};
    BOOST_REQUIRE(A.is<Scalar::f64>() && B.is<Scalar::f64>());
    BOOST_TEST(A != B);
    BOOST_TEST(A < B);
    BOOST_TEST(A <= B);
    BOOST_TEST(B > A);
    BOOST_TEST(B >= A);
    BOOST_TEST(A == A);
}

BOOST_AUTO_TEST_SUITE_END()