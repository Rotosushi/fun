// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file scalar.hpp
 * @brief Defines [Scalar](@ref Scalar)
 */

#pragma once

#include <cassert>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <ostream>
#include <utility>
#include <variant>

namespace fun::IR {

namespace detail {
/**
 * @brief Compares two floating point numbers for equality within epsilon.
 *
 * @note based on the answer https://stackoverflow.com/a/32334103
 */
template <class T>
bool epsilon_equality(T const &X, T const &Y)
    requires std::floating_point<T>
{
    if (X == Y) { return true; }

    T difference = std::fabs(X - Y);
    T normalized =
        std::min(std::fabs(X) + std::fabs(Y), std::numeric_limits<T>::max());
    return difference <
           std::max(std::numeric_limits<T>::min(),
                    std::numeric_limits<T>::epsilon() * normalized);
}
} // namespace detail

/**
 * @class Scalar
 * @brief Represents a scalar value at compile time.
 *
 * A scalar value is a single value that can be represented by a single
 * primitive type.
 * We support [nil, bool, u8, u16, u32, u64, i8, i16, i32, i64, f32, f64]
 * @note Composite types are not Scalar
 */
class Scalar {
  public:
    using Nil  = std::monostate;
    using Bool = bool;
    using u8   = std::uint8_t;
    using u16  = std::uint16_t;
    using u32  = std::uint32_t;
    using u64  = std::uint64_t;
    using i8   = std::int8_t;
    using i16  = std::int16_t;
    using i32  = std::int32_t;
    using i64  = std::int64_t;
    using f32  = float;
    using f64  = double;

  private:
    using Data =
        std::variant<Nil, Bool, u8, u16, u32, u64, i8, i16, i32, i64, f32, f64>;

    Data data_;

  public:
    constexpr Scalar() noexcept : data_{Nil{}} {}
    constexpr Scalar(Bool value) noexcept : data_{value} {}
    constexpr Scalar(u8 value) noexcept : data_{value} {}
    constexpr Scalar(u16 value) noexcept : data_{value} {}
    constexpr Scalar(u32 value) noexcept : data_{value} {}
    constexpr Scalar(u64 value) noexcept : data_{value} {}
    constexpr Scalar(i8 value) noexcept : data_{value} {}
    constexpr Scalar(i16 value) noexcept : data_{value} {}
    constexpr Scalar(i32 value) noexcept : data_{value} {}
    constexpr Scalar(i64 value) noexcept : data_{value} {}
    constexpr Scalar(f32 value) noexcept : data_{value} {}
    constexpr Scalar(f64 value) noexcept : data_{value} {}

    template <class T>
    constexpr Scalar &operator=(T const &value) noexcept
        requires std::is_assignable<Data &, T const &>::value
    {
        data_ = value;
        return *this;
    }

    constexpr std::partial_ordering
    operator<=>(Scalar const &other) const noexcept {
        assert(data_.index() == other.data_.index());
        switch (data_.index()) {
        case 0:  return std::partial_ordering::equivalent;
        case 1:  return as<Bool>() <=> other.as<Bool>();
        case 2:  return as<u8>() <=> other.as<u8>();
        case 3:  return as<u16>() <=> other.as<u16>();
        case 4:  return as<u32>() <=> other.as<u32>();
        case 5:  return as<u64>() <=> other.as<u64>();
        case 6:  return as<i8>() <=> other.as<i8>();
        case 7:  return as<i16>() <=> other.as<i16>();
        case 8:  return as<i32>() <=> other.as<i32>();
        case 9:  return as<i64>() <=> other.as<i64>();
        case 10: return as<f32>() <=> other.as<f32>();
        case 11: return as<f64>() <=> other.as<f64>();
        default: std::unreachable();
        }
    }

    constexpr bool operator==(Scalar const &other) const noexcept {
        assert(data_.index() == other.data_.index());
        switch (data_.index()) {
        case 0:  return true;
        case 1:  return as<Bool>() == other.as<Bool>();
        case 2:  return as<u8>() == other.as<u8>();
        case 3:  return as<u16>() == other.as<u16>();
        case 4:  return as<u32>() == other.as<u32>();
        case 5:  return as<u64>() == other.as<u64>();
        case 6:  return as<i8>() == other.as<i8>();
        case 7:  return as<i16>() == other.as<i16>();
        case 8:  return as<i32>() == other.as<i32>();
        case 9:  return as<i64>() == other.as<i64>();
        case 10: return detail::epsilon_equality(as<f32>(), other.as<f32>());
        case 11: return detail::epsilon_equality(as<f64>(), other.as<f64>());
        default: std::unreachable();
        }
    }

    template <class T> constexpr bool is() const noexcept {
        return std::holds_alternative<T>(data_);
    }

    template <class T> constexpr T as() const noexcept {
        assert(is<T>());
        return std::get<T>(data_);
    }

    template <class T> constexpr T &get() noexcept {
        assert(is<T>());
        return std::get<T>(data_);
    }

    friend class Value;
    friend std::ostream &operator<<(std::ostream &out, const Scalar &scalar);
};

inline std::ostream &operator<<(std::ostream &out, const Scalar &scalar) {
    switch (scalar.data_.index()) {
    case 0:  out << "nil"; break;
    case 1:  out << (scalar.as<Scalar::Bool>() ? "true" : "false"); break;
    case 2:  out << scalar.as<Scalar::u8>(); break;
    case 3:  out << scalar.as<Scalar::u16>(); break;
    case 4:  out << scalar.as<Scalar::u32>(); break;
    case 5:  out << scalar.as<Scalar::u64>(); break;
    case 6:  out << scalar.as<Scalar::i8>(); break;
    case 7:  out << scalar.as<Scalar::i16>(); break;
    case 8:  out << scalar.as<Scalar::i32>(); break;
    case 9:  out << scalar.as<Scalar::i64>(); break;
    case 10: out << scalar.as<Scalar::f32>(); break;
    case 11: out << scalar.as<Scalar::f64>(); break;
    default: std::unreachable();
    }
    return out;
}

} // namespace fun::IR
