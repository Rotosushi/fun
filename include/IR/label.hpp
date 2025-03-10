// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file label.hpp
 * @brief Defines [Label](@ref Label)
 */

#pragma once

#include <ostream>
#include <string_view>

namespace fun::IR {

/**
 * @struct Label
 * @brief Represents a label in the code
 */
struct Label {
    std::string_view name;

    constexpr bool operator==(Label const &other) const noexcept {
        return name == other.name;
    }

    constexpr std::partial_ordering
    operator<=>(Label const &other) const noexcept {
        return name <=> other.name;
    }
};

inline std::ostream &operator<<(std::ostream &out, Label const &label) {
    return out << "@" << label.name;
}

} // namespace fun::IR