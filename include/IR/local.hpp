// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file local.hpp
 * @brief Defines [Local](@ref Local)
 */

#pragma once

#include "IR/label.hpp"
#include "IR/type.hpp"
#include "IR/value.hpp"

namespace fun::IR {

/**
 * @struct Local
 * @brief Represents a local constant or variable
 */
struct Local {
    Label name_;
    Type::Ptr type_;
    Value value_;
};

inline std::ostream &operator<<(std::ostream &out, Local const &local) {
    return out << "[" << local.name_ << ": " << local.type_ << " = "
               << local.value_ << "]";
}

/**
 * @struct Local
 * @brief Represents a handle to a local
 */
struct LocalHandle {
    Scalar::u64 index;

    constexpr bool operator==(LocalHandle const &other) const noexcept {
        return index == other.index;
    }

    constexpr std::partial_ordering
    operator<=>(LocalHandle const &other) const noexcept {
        return index <=> other.index;
    }
};

} // namespace fun::IR