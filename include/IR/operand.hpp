// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file operand.hpp
 * @brief Defines [Operand](@ref Operand)
 */

#pragma once

#include <string_view>

#include "IR/local.hpp"
#include "IR/scalar.hpp"

namespace fun::IR {

/**
 * @class Operand
 * @brief Represents an operand to an Instruction
 */
class Operand {

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
                              Scalar::f64,
                              Label,
                              LocalHandle>;
    Data data_;

public:
    constexpr Operand() noexcept : data_{Scalar::Nil{}} {}
    constexpr Operand(Scalar::Nil) noexcept : data_{Scalar::Nil{}} {}
    constexpr Operand(Scalar::Bool value) noexcept : data_{value} {}
    constexpr Operand(Scalar::u8 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::u16 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::u32 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::u64 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::i8 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::i16 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::i32 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::i64 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::f32 value) noexcept : data_{value} {}
    constexpr Operand(Scalar::f64 value) noexcept : data_{value} {}
    constexpr Operand(Scalar scalar) noexcept {
        switch (scalar.index()) {
        case 0:  data_ = Scalar::Nil{}; break;
        case 1:  data_ = scalar.as<Scalar::Bool>(); break;
        case 2:  data_ = scalar.as<Scalar::u8>(); break;
        case 3:  data_ = scalar.as<Scalar::u16>(); break;
        case 4:  data_ = scalar.as<Scalar::u32>(); break;
        case 5:  data_ = scalar.as<Scalar::u64>(); break;
        case 6:  data_ = scalar.as<Scalar::i8>(); break;
        case 7:  data_ = scalar.as<Scalar::i16>(); break;
        case 8:  data_ = scalar.as<Scalar::i32>(); break;
        case 9:  data_ = scalar.as<Scalar::i64>(); break;
        case 10: data_ = scalar.as<Scalar::f32>(); break;
        case 11: data_ = scalar.as<Scalar::f64>(); break;
        default: std::unreachable();
        }
    }
    constexpr Operand(Label value) noexcept : data_{value} {}
    constexpr Operand(LocalHandle value) noexcept : data_{value} {}

    template <class T>
    constexpr Operand &operator=(T const &value) noexcept
        requires std::is_assignable<Data &, T const &>::value
    {
        data_ = value;
        return *this;
    }

    constexpr Operand &operator=(Scalar const &scalar) noexcept {
        switch (scalar.index()) {
        case 0:  data_ = Scalar::Nil{}; break;
        case 1:  data_ = scalar.as<Scalar::Bool>(); break;
        case 2:  data_ = scalar.as<Scalar::u8>(); break;
        case 3:  data_ = scalar.as<Scalar::u16>(); break;
        case 4:  data_ = scalar.as<Scalar::u32>(); break;
        case 5:  data_ = scalar.as<Scalar::u64>(); break;
        case 6:  data_ = scalar.as<Scalar::i8>(); break;
        case 7:  data_ = scalar.as<Scalar::i16>(); break;
        case 8:  data_ = scalar.as<Scalar::i32>(); break;
        case 9:  data_ = scalar.as<Scalar::i64>(); break;
        case 10: data_ = scalar.as<Scalar::f32>(); break;
        case 11: data_ = scalar.as<Scalar::f64>(); break;
        default: std::unreachable();
        }
        return *this;
    }

    constexpr std::partial_ordering
    operator<=>(Operand const &other) const noexcept {
        assert(data_.index() == other.data_.index());
        switch (data_.index()) {
        case 0:  return std::partial_ordering::equivalent;
        case 1:  return as<Scalar::Bool>() <=> other.as<Scalar::Bool>();
        case 2:  return as<Scalar::u8>() <=> other.as<Scalar::u8>();
        case 3:  return as<Scalar::u16>() <=> other.as<Scalar::u16>();
        case 4:  return as<Scalar::u32>() <=> other.as<Scalar::u32>();
        case 5:  return as<Scalar::u64>() <=> other.as<Scalar::u64>();
        case 6:  return as<Scalar::i8>() <=> other.as<Scalar::i8>();
        case 7:  return as<Scalar::i16>() <=> other.as<Scalar::i16>();
        case 8:  return as<Scalar::i32>() <=> other.as<Scalar::i32>();
        case 9:  return as<Scalar::i64>() <=> other.as<Scalar::i64>();
        case 10: return as<Scalar::f32>() <=> other.as<Scalar::f32>();
        case 11: return as<Scalar::f64>() <=> other.as<Scalar::f64>();
        case 12: return as<Label>() <=> other.as<Label>();
        case 13: return as<LocalHandle>() <=> other.as<LocalHandle>();
        default: std::unreachable();
        }
    }

    constexpr bool operator==(Operand const &other) const noexcept {
        assert(data_.index() == other.data_.index());
        switch (data_.index()) {
        case 0:  return true;
        case 1:  return as<Scalar::Bool>() == other.as<Scalar::Bool>();
        case 2:  return as<Scalar::u8>() == other.as<Scalar::u8>();
        case 3:  return as<Scalar::u16>() == other.as<Scalar::u16>();
        case 4:  return as<Scalar::u32>() == other.as<Scalar::u32>();
        case 5:  return as<Scalar::u64>() == other.as<Scalar::u64>();
        case 6:  return as<Scalar::i8>() == other.as<Scalar::i8>();
        case 7:  return as<Scalar::i16>() == other.as<Scalar::i16>();
        case 8:  return as<Scalar::i32>() == other.as<Scalar::i32>();
        case 9:  return as<Scalar::i64>() == other.as<Scalar::i64>();
        case 10: return as<Scalar::f32>() == other.as<Scalar::f32>();
        case 11: return as<Scalar::f64>() == other.as<Scalar::f64>();
        case 12: return as<Label>() == other.as<Label>();
        case 13: return as<LocalHandle>() == other.as<LocalHandle>();
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

    friend std::ostream &operator<<(std::ostream &out, Operand const &operand);
};

template <> inline constexpr bool Operand::is<Scalar>() const noexcept {
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

template <> inline constexpr Scalar Operand::as<Scalar>() const noexcept {
    assert(is<Scalar>());
    switch (data_.index()) {
    case 0:  return Scalar::Nil{};
    case 1:  return as<Scalar::Bool>();
    case 2:  return as<Scalar::u8>();
    case 3:  return as<Scalar::u16>();
    case 4:  return as<Scalar::u32>();
    case 5:  return as<Scalar::u64>();
    case 6:  return as<Scalar::i8>();
    case 7:  return as<Scalar::i16>();
    case 8:  return as<Scalar::i32>();
    case 9:  return as<Scalar::i64>();
    case 10: return as<Scalar::f32>();
    case 11: return as<Scalar::f64>();
    default: std::unreachable();
    }
}

inline std::ostream &operator<<(std::ostream &out, Operand const &operand) {
    switch (operand.data_.index()) {
    case 0:  return out << "nil";
    case 1:  return out << operand.as<Scalar::Bool>();
    case 2:  return out << operand.as<Scalar::u8>();
    case 3:  return out << operand.as<Scalar::u16>();
    case 4:  return out << operand.as<Scalar::u32>();
    case 5:  return out << operand.as<Scalar::u64>();
    case 6:  return out << operand.as<Scalar::i8>();
    case 7:  return out << operand.as<Scalar::i16>();
    case 8:  return out << operand.as<Scalar::i32>();
    case 9:  return out << operand.as<Scalar::i64>();
    case 10: return out << operand.as<Scalar::f32>();
    case 11: return out << operand.as<Scalar::f64>();
    case 12: return out << "@" << operand.as<Label>().name;
    case 13: return out << "%" << operand.as<LocalHandle>().index;
    default: std::unreachable();
    }
}

} // namespace fun::IR