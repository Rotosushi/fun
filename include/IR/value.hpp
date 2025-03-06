// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file value.hpp
 * @brief Defines [Value](@ref Value)
 */

#pragma once

#include "IR/scalar.hpp"
#include <utility>
#include <variant>

namespace fun::IR {

/**
 * @class Value
 * @brief Represents a value at compile time.
 * @todo reference, slice, array, tuple, struct, union, lambda, vector, matrix
 */
class Value {
  private:
    using Data = std::variant<Scalar::Nil,
                              Scalar::Bool,
                              Scalar::u8,
                              Scalar::u16,
                              Scalar::u32,
                              Scalar::u64,
                              Scalar::i8,
                              Scalar::i16,
                              Scalar::i32,
                              Scalar::i64,
                              Scalar::f32,
                              Scalar::f64>;
    Data data_;

  public:
    constexpr Value() noexcept : data_{Scalar::Nil{}} {}
    constexpr Value(Scalar::Bool value) noexcept : data_{value} {}
    constexpr Value(Scalar::u8 value) noexcept : data_{value} {}
    constexpr Value(Scalar::u16 value) noexcept : data_{value} {}
    constexpr Value(Scalar::u32 value) noexcept : data_{value} {}
    constexpr Value(Scalar::u64 value) noexcept : data_{value} {}
    constexpr Value(Scalar::i8 value) noexcept : data_{value} {}
    constexpr Value(Scalar::i16 value) noexcept : data_{value} {}
    constexpr Value(Scalar::i32 value) noexcept : data_{value} {}
    constexpr Value(Scalar::i64 value) noexcept : data_{value} {}
    constexpr Value(Scalar::f32 value) noexcept : data_{value} {}
    constexpr Value(Scalar::f64 value) noexcept : data_{value} {}

    template <class T> constexpr bool is() const noexcept {
        return std::holds_alternative<T>(data_);
    }

    template <> constexpr bool is<Scalar>() const noexcept {
        switch (data_.index()) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11: return true;
        default: return false;
        }
    }

    template <class T> constexpr T as() const noexcept {
        assert(is<T>());
        return std::get<T>(data_);
    }

    template <> constexpr Scalar as<Scalar>() const noexcept {
        assert(is<Scalar>());
        switch (data_.index()) {
        case 0:  return Scalar{};
        case 1:  return Scalar{as<Scalar::Bool>()};
        case 2:  return Scalar{as<Scalar::u8>()};
        case 3:  return Scalar{as<Scalar::u16>()};
        case 4:  return Scalar{as<Scalar::u32>()};
        case 5:  return Scalar{as<Scalar::u64>()};
        case 6:  return Scalar{as<Scalar::i8>()};
        case 7:  return Scalar{as<Scalar::i16>()};
        case 8:  return Scalar{as<Scalar::i32>()};
        case 9:  return Scalar{as<Scalar::i64>()};
        case 10: return Scalar{as<Scalar::f32>()};
        case 11: return Scalar{as<Scalar::f64>()};
        default: std::unreachable();
        }
    }
};
} // namespace fun::IR
