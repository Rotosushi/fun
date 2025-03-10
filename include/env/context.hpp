// fun (c) by Cade Weinberg
//
// To the extent possible under law, the person who associated CC0 with
// fun has waived all copyright and related or neighboring rights
// to fun.
//
// You should have received a copy of the CC0 legalcode along with this
// work.  If not, see <https://creativecommons.org/publicdomain/zero/1.0/>.

/**
 * @file context.hpp
 * @brief Defines [Context](@ref Context)
 */

#pragma once

#include <filesystem>

#include <llvm/ADT/StringSet.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/TargetParser/Host.h>

#include "IR/label.hpp"

namespace fs = std::filesystem;

namespace fun::env {

/**
 * @class Context
 * @brief Represents the context in which code is generated
 * we consider it to be equivalent to a single translation unit.
 * one context per file essentially.
 */
class Context {
    llvm::LLVMContext context_;
    llvm::Module module_;
    llvm::IRBuilder<> builder_;
    llvm::TargetMachine *target_machine_;
    llvm::StringSet<> string_interner_;

public:
    std::string HostCPUFeatures() {
        std::string features;
        llvm::StringMap<bool> host_features = llvm::sys::getHostCPUFeatures();

        auto cursor = host_features.begin();
        auto end    = host_features.end();
        auto length = host_features.getNumItems();
        auto index  = 0U;

        while (cursor != end) {
            if (cursor->getValue()) {
                features += "+";
            } else {
                features += "-";
            }

            features += cursor->getKeyData();

            if (index < (length - 1)) { features += ","; }

            ++cursor;
            ++index;
        }

        return features;
    }

    Context(fs::path path)
        : context_{}, module_{path.string(), context_}, builder_{context_},
          target_machine_{nullptr} {
        std::string target_triple = llvm::sys::getDefaultTargetTriple();

        std::string error;
        auto target = llvm::TargetRegistry::lookupTarget(target_triple, error);
        if (!target) {
            llvm::errs() << error;
            std::exit(1);
        }

        target_machine_ =
            target->createTargetMachine(target_triple,
                                        llvm::sys::getHostCPUName(),
                                        HostCPUFeatures(),
                                        llvm::TargetOptions{},
                                        llvm::Reloc::Model::PIC_,
                                        llvm::CodeModel::Small,
                                        llvm::CodeGenOptLevel::Default,
                                        false);

        module_.setDataLayout(target_machine_->createDataLayout());
        module_.setTargetTriple(target_triple);
    }

    IR::Label intern_string(std::string_view string) {
        return IR::Label{string_interner_.insert(string).first->getKey()};
    }

    llvm::Type *llvm_Int1Ty() { return builder_.getInt1Ty(); }
    llvm::Type *llvm_Int8Ty() { return builder_.getInt8Ty(); }
    llvm::Type *llvm_Int16Ty() { return builder_.getInt16Ty(); }
    llvm::Type *llvm_Int32Ty() { return builder_.getInt32Ty(); }
    llvm::Type *llvm_Int64Ty() { return builder_.getInt64Ty(); }
    llvm::Type *llvm_FloatTy() { return builder_.getFloatTy(); }
    llvm::Type *llvm_DoubleTy() { return builder_.getDoubleTy(); }

    llvm::Constant *llvm_Int1(bool value) {
        return llvm::ConstantInt::get(builder_.getInt1Ty(), value, false);
    }

    llvm::Constant *llvm_Int8(std::uint8_t value) {
        return llvm::ConstantInt::get(builder_.getInt8Ty(), value, false);
    }

    llvm::Constant *llvm_Int16(std::uint16_t value) {
        return llvm::ConstantInt::get(builder_.getInt16Ty(), value, false);
    }

    llvm::Constant *llvm_Int32(std::uint32_t value) {
        return llvm::ConstantInt::get(builder_.getInt32Ty(), value, false);
    }

    llvm::Constant *llvm_Int64(std::uint64_t value) {
        return llvm::ConstantInt::get(builder_.getInt64Ty(), value, false);
    }

    llvm::Constant *llvm_Int8(std::int8_t value) {
        return llvm::ConstantInt::get(
            builder_.getInt8Ty(), (std::uint8_t)value, true);
    }

    llvm::Constant *llvm_Int16(std::int16_t value) {
        return llvm::ConstantInt::get(
            builder_.getInt16Ty(), (std::uint16_t)value, true);
    }

    llvm::Constant *llvm_Int32(std::int32_t value) {
        return llvm::ConstantInt::get(
            builder_.getInt32Ty(), (std::uint32_t)value, true);
    }

    llvm::Constant *llvm_Int64(std::int64_t value) {
        return llvm::ConstantInt::get(
            builder_.getInt64Ty(), (std::uint64_t)value, true);
    }

    llvm::Constant *llvm_Float(float value) {
        return llvm::ConstantFP::get(builder_.getFloatTy(), value);
    }

    llvm::Constant *llvm_Double(double value) {
        return llvm::ConstantFP::get(builder_.getDoubleTy(), value);
    }
};

} // namespace fun::env