// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file instruction.hpp
 * @brief Defines [Instruction](@ref Instruction)
 */

#pragma once

#include "IR/operand.hpp"

namespace fun::IR {

/**
 * @class Instruction
 * @brief Represents an instruction in a block of code
 */
class Instruction {
public:
    /**
     * @enum Opcode
     * @brief Represents the operation to be performed
     *
     * @todo jmp, jeq, jne, jlt, jle, jgt, jge, jz, jnz,
     * store, as, is, subscript, slice, dot, and, or, xor, not,
     * shl, shr, eq, ne, lt, le, gt, ge
     *
     */
    enum class Opcode {
        // Control flow
        Ret,
        Call,
        // Memory
        Load,
        // Arithmetic
        Neg,
        Add,
        Sub,
        Mul,
        Div,
        Rem,
    };

    enum class Format {
        Unary,
        Binary,
        Ternary,
    };

private:
    Opcode opcode_;
    Format format_;
    Operand A_;
    Operand B_;
    Operand C_;

public:
    constexpr Instruction(Opcode opcode, Operand A) noexcept
        : opcode_{opcode}, format_{Format::Unary}, A_{A} {}
    constexpr Instruction(Opcode opcode, Operand A, Operand B) noexcept
        : opcode_{opcode}, format_{Format::Binary}, A_{A}, B_{B} {}
    constexpr Instruction(Opcode opcode,
                          Operand A,
                          Operand B,
                          Operand C) noexcept
        : opcode_{opcode}, format_{Format::Ternary}, A_{A}, B_{B}, C_{C} {}

    constexpr Opcode opcode() const noexcept { return opcode_; }
    constexpr Format format() const noexcept { return format_; }
    constexpr Operand A() const noexcept { return A_; }
    constexpr Operand B() const noexcept { return B_; }
    constexpr Operand C() const noexcept { return C_; }

    // #NOTE: if we want to implement optimizations ourselves, we can add
    // accessors for the data memebers as mutable references, to allow for
    // in-place modification of the instruction.

    friend std::ostream &operator<<(std::ostream &out,
                                    Instruction const &instruction);
};

inline std::ostream &operator<<(std::ostream &out,
                                Instruction::Opcode const &opcode) {
    switch (opcode) {
    case Instruction::Opcode::Ret:  out << "ret "; break;
    case Instruction::Opcode::Call: out << "call"; break;
    case Instruction::Opcode::Load: out << "load"; break;
    case Instruction::Opcode::Neg:  out << "neg "; break;
    case Instruction::Opcode::Add:  out << "add "; break;
    case Instruction::Opcode::Sub:  out << "sub "; break;
    case Instruction::Opcode::Mul:  out << "mul "; break;
    case Instruction::Opcode::Div:  out << "div "; break;
    case Instruction::Opcode::Rem:  out << "rem "; break;
    default:                        std::unreachable();
    }

    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                Instruction::Format const &format) {
    switch (format) {
    case Instruction::Format::Unary: out << "Instruction::Format::Unary"; break;
    case Instruction::Format::Binary:
        out << "Instruction::Format::Binary";
        break;
    case Instruction::Format::Ternary:
        out << "Instruction::Format::Ternary";
        break;
    default: std::unreachable();
    }

    return out;
}

inline std::ostream &operator<<(std::ostream &out,
                                Instruction const &instruction) {
    out << instruction.opcode();

    switch (instruction.format()) {
    case Instruction::Format::Unary: {
        out << " " << instruction.A();
        break;
    }
    case Instruction::Format::Binary: {
        out << " " << instruction.A() << ", " << instruction.B();
        break;
    }
    case Instruction::Format::Ternary: {
        out << " " << instruction.A() << ", " << instruction.B() << ", "
            << instruction.C();
        break;
    }
    default: std::unreachable();
    }

    return out;
}

} // namespace fun::IR