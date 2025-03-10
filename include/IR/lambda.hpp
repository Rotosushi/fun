// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file lambda.hpp
 * @brief Defines [Lambda](@ref Lambda)
 */

#pragma once

#include <vector>

#include "IR/block.hpp"
#include "IR/label.hpp"
#include "IR/local.hpp"
#include "IR/type.hpp"

namespace fun::IR {

class Lambda {
public:
    struct Argument {
        Label name;
        Type::Ptr type;
    };
    using Arguments = std::vector<Argument>;
    using Locals    = std::vector<Local>;
    using Body      = std::vector<Block>;

private:
    Type::Ptr return_type_;
    Arguments arguments_;
    Locals locals_;
    Body body_;
};

} // namespace fun::IR
