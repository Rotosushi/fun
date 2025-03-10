// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file type.hpp
 * @brief Defines [Type](@ref Type)
 */

#pragma once

#include <cassert>
#include <memory>
#include <ostream>
#include <utility>
#include <variant>
#include <vector>

#include "IR/label.hpp"

namespace fun::IR {

class Type {
public:
    using Ptr = std::unique_ptr<Type>;

    struct Nil {};
    struct Bool {};
    struct u8 {};
    struct u16 {};
    struct u32 {};
    struct u64 {};
    struct i8 {};
    struct i16 {};
    struct i32 {};
    struct i64 {};
    struct f32 {};
    struct f64 {};
    struct Function {
        struct Argument {
            Label name;
            Ptr type;
        };
        using Arguments = std::vector<Argument>;

        Ptr return_type;
        Arguments arguments;

        constexpr Function(Ptr return_type, Arguments arguments) noexcept
            : return_type{std::move(return_type)},
              arguments{std::move(arguments)} {}
    };

private:
    using Data = std::variant<Nil,
                              Bool,
                              u8,
                              u16,
                              u32,
                              u64,
                              i8,
                              i16,
                              i32,
                              i64,
                              f32,
                              f64,
                              Function>;

    Data data_;

public:
    Type() noexcept : data_{Nil{}} {}
    Type(Nil) noexcept : data_{Nil{}} {}
    Type(Bool) noexcept : data_{Bool{}} {}
    Type(u8) noexcept : data_{u8{}} {}
    Type(u16) noexcept : data_{u16{}} {}
    Type(u32) noexcept : data_{u32{}} {}
    Type(u64) noexcept : data_{u64{}} {}
    Type(i8) noexcept : data_{i8{}} {}
    Type(i16) noexcept : data_{i16{}} {}
    Type(i32) noexcept : data_{i32{}} {}
    Type(i64) noexcept : data_{i64{}} {}
    Type(f32) noexcept : data_{f32{}} {}
    Type(f64) noexcept : data_{f64{}} {}
    Type(Ptr return_type, Function::Arguments arguments) noexcept
        : data_{std::in_place_type<Function>,
                std::move(return_type),
                std::move(arguments)} {}

    constexpr std::uint64_t index() const noexcept { return data_.index(); }

    template <class T> constexpr bool is() const noexcept {
        return std::holds_alternative<T>(data_);
    }

    template <class T> constexpr T const &as() const noexcept {
        assert(is<T>());
        return std::get<T>(data_);
    }
};

inline std::ostream &operator<<(std::ostream &out, Type const &type) {
    switch (type.index()) {
    case 0:  return out << "nil";
    case 1:  return out << "bool";
    case 2:  return out << "u8";
    case 3:  return out << "u16";
    case 4:  return out << "u32";
    case 5:  return out << "u64";
    case 6:  return out << "i8";
    case 7:  return out << "i16";
    case 8:  return out << "i32";
    case 9:  return out << "i64";
    case 10: return out << "f32";
    case 11: return out << "f64";
    case 12: {
        Type::Function const &function = type.as<Type::Function>();
        out << "(";
        for (auto it = function.arguments.begin();
             it != function.arguments.end();
             ++it) {
            out << it->name << ": " << *it->type;
            if (std::next(it) != function.arguments.end()) { out << ", "; }
        }
        out << ") -> " << *function.return_type;
        return out;
    }
    default: std::unreachable();
    }
}

} // namespace fun::IR