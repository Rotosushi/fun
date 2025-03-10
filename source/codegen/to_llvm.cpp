// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

#include "codegen/to_llvm.hpp"
#include <llvm-20/llvm/IR/Constant.h>

using fun::IR::Scalar;
using fun::IR::Type;

namespace fun::codegen {

llvm::Type *to_llvm(Type::Ptr const &type, env::Context &ctx) {
    switch (type->index()) {
    case 0:  return ctx.llvm_Int1Ty();   // Type::Nil
    case 1:  return ctx.llvm_Int1Ty();   // Type::Bool
    case 2:  return ctx.llvm_Int8Ty();   // Type::u8
    case 3:  return ctx.llvm_Int16Ty();  // Type::u16
    case 4:  return ctx.llvm_Int32Ty();  // Type::u32
    case 5:  return ctx.llvm_Int64Ty();  // Type::u64
    case 6:  return ctx.llvm_Int8Ty();   // Type::i8
    case 7:  return ctx.llvm_Int16Ty();  // Type::i16
    case 8:  return ctx.llvm_Int32Ty();  // Type::i32
    case 9:  return ctx.llvm_Int64Ty();  // Type::i64
    case 10: return ctx.llvm_FloatTy();  // Type::f32
    case 11: return ctx.llvm_DoubleTy(); // Type::f64
    case 12: {                           // Type::Function
        Type::Function const &function = type->as<Type::Function>();
        std::vector<llvm::Type *> arguments;
        for (Type::Function::Argument const &arg : function.arguments) {
            arguments.push_back(to_llvm(arg.type, ctx));
        }
        return llvm::FunctionType::get(
            to_llvm(function.return_type, ctx), arguments, false);
    }
    default: std::unreachable();
    }
}

llvm::Constant *to_llvm(Scalar const &scalar, env::Context &ctx) {
    switch (scalar.index()) {
    case 0:  return ctx.llvm_Int1(false);                      // Scalar::Nil
    case 1:  return ctx.llvm_Int1(scalar.as<Scalar::Bool>());  // Scalar::Bool
    case 2:  return ctx.llvm_Int8(scalar.as<Scalar::u8>());    // Scalar::u8
    case 3:  return ctx.llvm_Int16(scalar.as<Scalar::u16>());  // Scalar::u16
    case 4:  return ctx.llvm_Int32(scalar.as<Scalar::u32>());  // Scalar::u32
    case 5:  return ctx.llvm_Int64(scalar.as<Scalar::u64>());  // Scalar::u64
    case 6:  return ctx.llvm_Int8(scalar.as<Scalar::i8>());    // Scalar::i8
    case 7:  return ctx.llvm_Int16(scalar.as<Scalar::i16>());  // Scalar::i16
    case 8:  return ctx.llvm_Int32(scalar.as<Scalar::i32>());  // Scalar::i32
    case 9:  return ctx.llvm_Int64(scalar.as<Scalar::i64>());  // Scalar::i64
    case 10: return ctx.llvm_Float(scalar.as<Scalar::f32>());  // Scalar::f32
    case 11: return ctx.llvm_Double(scalar.as<Scalar::f64>()); // Scalar::f64

    default: std::unreachable();
    }
}

} // namespace fun::codegen
