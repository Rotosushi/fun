// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file block.hpp
 * @brief Defines [Block](@ref Block)
 */

#pragma once

#include <vector>

#include "IR/instruction.hpp"

namespace fun::IR {

/**
 * @class Block
 * @brief Represents a block of code
 *
 * A block is a sequence of instructions that are executed in order,
 * without any branches or jumps. Branches and Jump instructions target
 * blocks. They do not target individual instructions.
 */
class Block {
public:
    using Data = std::vector<Instruction>;

private:
    Data data_;

public:
    constexpr void append(Instruction::Opcode opcode, Operand A) {
        data_.emplace_back(opcode, A);
    }

    constexpr void append(Instruction::Opcode opcode, Operand A, Operand B) {
        data_.emplace_back(opcode, A, B);
    }

    constexpr void
    append(Instruction::Opcode opcode, Operand A, Operand B, Operand C) {
        data_.emplace_back(opcode, A, B, C);
    }

    constexpr std::uint64_t size() const noexcept { return data_.size(); }

    constexpr Data::reference operator[](std::size_t index) noexcept {
        return data_[index];
    }

    constexpr Data::iterator begin() noexcept { return data_.begin(); }

    constexpr Data::iterator end() noexcept { return data_.end(); }

    constexpr Data::const_iterator begin() const noexcept {
        return data_.begin();
    }

    constexpr Data::const_iterator end() const noexcept { return data_.end(); }

    constexpr Data::const_iterator cbegin() const noexcept {
        return data_.cbegin();
    }
    constexpr Data::const_iterator cend() const noexcept {
        return data_.cend();
    }

    constexpr Data::reverse_iterator rbegin() noexcept {
        return data_.rbegin();
    }

    constexpr Data::reverse_iterator rend() noexcept { return data_.rend(); }

    constexpr Data::const_reverse_iterator rbegin() const noexcept {
        return data_.rbegin();
    }

    constexpr Data::const_reverse_iterator rend() const noexcept {
        return data_.rend();
    }

    constexpr Data::const_reverse_iterator crbegin() const noexcept {
        return data_.crbegin();
    }

    constexpr Data::const_reverse_iterator crend() const noexcept {
        return data_.crend();
    }
};

inline std::ostream &operator<<(std::ostream &out, Block const &block) {
    std::uint64_t index = 0;
    for (auto const &instruction : block) {
        out << index++ << ":\t" << instruction << '\n';
    }
    return out;
}

} // namespace fun::IR
