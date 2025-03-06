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
 */

#pragma once

#include <cassert>
#include <cstdint>

namespace fun::IR {
class Scalar {
public:
  enum class Type {
    u8_,
    u16_,
    u32_,
    u64_,
    i8_,
    i16_,
    i32_,
    i64_,
    f32_,
    f64_,
    nil_,
    bool_,
  };

  union Data {
    std::uint8_t u8_;
    std::uint16_t u16_;
    std::uint32_t u32_;
    std::uint64_t u64_;
    std::int8_t i8_;
    std::int16_t i16_;
    std::int32_t i32_;
    std::int64_t i64_;
    float f32_;
    double f64_;
    bool bool_;

    constexpr Data() : u8_{0} {}
    constexpr Data(std::uint8_t value) : u8_{value} {}
    constexpr Data(std::uint16_t value) : u16_{value} {}
    constexpr Data(std::uint32_t value) : u32_{value} {}
    constexpr Data(std::uint64_t value) : u64_{value} {}
    constexpr Data(std::int8_t value) : i8_{value} {}
    constexpr Data(std::int16_t value) : i16_{value} {}
    constexpr Data(std::int32_t value) : i32_{value} {}
    constexpr Data(std::int64_t value) : i64_{value} {}
    constexpr Data(float value) : f32_{value} {}
    constexpr Data(double value) : f64_{value} {}
    constexpr Data(bool value) : bool_{value} {}
  };

private:
  Type type_;
  Data data_;

public:
  constexpr Scalar() : type_{Type::nil_} {}
  constexpr Scalar(std::uint8_t value) : type_{Type::u8_}, data_(value) {}
  constexpr Scalar(std::uint16_t value) : type_{Type::u16_}, data_(value) {}
  constexpr Scalar(std::uint32_t value) : type_{Type::u32_}, data_(value) {}
  constexpr Scalar(std::uint64_t value) : type_{Type::u64_}, data_(value) {}
  constexpr Scalar(std::int8_t value) : type_{Type::i8_}, data_(value) {}
  constexpr Scalar(std::int16_t value) : type_{Type::i16_}, data_(value) {}
  constexpr Scalar(std::int32_t value) : type_{Type::i32_}, data_(value) {}
  constexpr Scalar(std::int64_t value) : type_{Type::i64_}, data_(value) {}
  constexpr Scalar(float value) : type_{Type::f32_}, data_(value) {}
  constexpr Scalar(double value) : type_{Type::f64_}, data_(value) {}
  constexpr Scalar(bool value) : type_{Type::bool_}, data_(value) {}

  constexpr Type type() const { return type_; }

  constexpr bool is(Type type) const { return type_ == type; }

  constexpr std::uint8_t as_u8() const {
    assert(is(Type::u8_));
    return data_.u8_;
  }

  constexpr std::uint16_t as_u16() const {
    assert(is(Type::u16_));
    return data_.u16_;
  }

  constexpr std::uint32_t as_u32() const {
    assert(is(Type::u32_));
    return data_.u32_;
  }

  constexpr std::uint64_t as_u64() const {
    assert(is(Type::u64_));
    return data_.u64_;
  }

  constexpr std::int8_t as_i8() const {
    assert(is(Type::i8_));
    return data_.i8_;
  }

  constexpr std::int16_t as_i16() const {
    assert(is(Type::i16_));
    return data_.i16_;
  }

  constexpr std::int32_t as_i32() const {
    assert(is(Type::i32_));
    return data_.i32_;
  }

  constexpr std::int64_t as_i64() const {
    assert(is(Type::i64_));
    return data_.i64_;
  }

  constexpr float as_f32() const {
    assert(is(Type::f32_));
    return data_.f32_;
  }

  constexpr double as_f64() const {
    assert(is(Type::f64_));
    return data_.f64_;
  }

  constexpr bool as_bool() const {
    assert(is(Type::bool_));
    return data_.bool_;
  }
};
} // namespace fun::IR