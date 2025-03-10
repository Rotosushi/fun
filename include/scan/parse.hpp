// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file parse.hpp
 * @brief Declares [parse](@ref parse)
 */

#pragma once

#include <filesystem>
#include <string_view>

#include "env/context.hpp"

namespace fs = std::filesystem;

namespace fun::scan {

bool parse(std::string_view view, env::Context &ctx);
bool parse(fs::path path, env::Context &ctx);

} // namespace fun::scan