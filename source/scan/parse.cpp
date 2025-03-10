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
 * @brief Defines [parse](@ref parse)
 */

#include <cassert>

#include <boost/parser/parser.hpp>

namespace bp = boost::parser;

#include "IR/instruction.hpp"
#include "IR/operand.hpp"
#include "IR/scalar.hpp"
#include "IR/type.hpp"
#include "IR/value.hpp"

#include "scan/parse.hpp"

using fun::IR::Scalar;

namespace fun::scan {

bp::rule<struct nil_, Scalar> nil_rule = "nil";
auto const nil_rule_def                = bp::lit("nil");
BOOST_PARSER_DEFINE_RULES(nil_rule);

bp::rule<struct bool_, Scalar> bool_rule = "bool";
auto const bool_rule_def                 = bp::bool_;
BOOST_PARSER_DEFINE_RULES(bool_rule);

bp::rule<struct bin, Scalar> bin_rule = "bin";
auto const bin_rule_def = bp::lit("0b") > bp::bin | bp::lit("0B") > bp::bin;
BOOST_PARSER_DEFINE_RULES(bin_rule);

bp::rule<struct hex, Scalar> hex_rule = "hex";
auto const hex_rule_def = bp::lit("0x") > bp::hex | bp::lit("0X") > bp::hex;
BOOST_PARSER_DEFINE_RULES(hex_rule);

bp::rule<struct oct, Scalar> oct_rule = "oct";
auto const oct_rule_def = bp::lit("0o") > bp::oct | bp::lit("0O") > bp::oct;
BOOST_PARSER_DEFINE_RULES(oct_rule);

bp::rule<struct u8_, Scalar> u8_rule = "u8";
auto const u8_rule_def =
    (bin_rule > bp::lit("u8") | hex_rule > bp::lit("u8") |
     oct_rule > bp::lit("u8") | bp::ushort_ > bp::lit("u8"))[([](auto &ctx) {
        unsigned short value = _attr(ctx);
        if (value > std::numeric_limits<std::uint8_t>::max()) {
            _report_error(ctx, "u8 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::uint8_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(u8_rule);

bp::rule<struct u16_, Scalar> u16_rule = "u16";
auto const u16_rule_def =
    (bin_rule > bp::lit("u16") | hex_rule > bp::lit("u16") |
     oct_rule > bp::lit("u16") | bp::ushort_ > bp::lit("u16"))[([](auto &ctx) {
        unsigned int value = _attr(ctx);
        if (value > std::numeric_limits<std::uint16_t>::max()) {
            _report_error(ctx, "u16 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::uint16_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(u16_rule);

bp::rule<struct u32_, Scalar> u32_rule = "u32";
auto const u32_rule_def =
    (bin_rule > bp::lit("u32") | hex_rule > bp::lit("u32") |
     oct_rule > bp::lit("u32") | bp::uint_ > bp::lit("u32"))[([](auto &ctx) {
        unsigned long value = _attr(ctx);
        if (value > std::numeric_limits<std::uint32_t>::max()) {
            _report_error(ctx, "u32 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::uint32_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(u32_rule);

bp::rule<struct u64_, Scalar> u64_rule = "u64";
auto const u64_rule_def =
    (bin_rule > bp::lit("u64") | hex_rule > bp::lit("u64") |
     oct_rule > bp::lit("u64") | bp::ulong_ > bp::lit("u64") | bp::ulong_);
BOOST_PARSER_DEFINE_RULES(u64_rule);

bp::rule<struct i8_, Scalar> i8_rule = "i8";
auto const i8_rule_def =
    (bin_rule > bp::lit("i8") | hex_rule > bp::lit("i8") |
     oct_rule > bp::lit("i8") | bp::short_ > bp::lit("i8"))[([](auto &ctx) {
        short value = _attr(ctx);
        if (value > std::numeric_limits<std::int8_t>::max() ||
            value < std::numeric_limits<std::int8_t>::min()) {
            _report_error(ctx, "i8 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::int8_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(i8_rule);

bp::rule<struct i16_, Scalar> i16_rule = "i16";
auto const i16_rule_def =
    (bin_rule > bp::lit("i16") | hex_rule > bp::lit("i16") |
     oct_rule > bp::lit("i16") | bp::short_ > bp::lit("i16"))[([](auto &ctx) {
        int value = _attr(ctx);
        if (value > std::numeric_limits<std::int16_t>::max() ||
            value < std::numeric_limits<std::int16_t>::min()) {
            _report_error(ctx, "i16 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::int16_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(i16_rule);

bp::rule<struct i32_, Scalar> i32_rule = "i32";
auto const i32_rule_def =
    (bin_rule > bp::lit("i32") | hex_rule > bp::lit("i32") |
     oct_rule > bp::lit("i32") | bp::int_ > bp::lit("i32"))[([](auto &ctx) {
        long value = _attr(ctx);
        if (value > std::numeric_limits<std::int32_t>::max() ||
            value < std::numeric_limits<std::int32_t>::min()) {
            _report_error(ctx, "i32 literal out of range", _where(ctx));
        }
        return Scalar{static_cast<std::int32_t>(value)};
    })];
BOOST_PARSER_DEFINE_RULES(i32_rule);

bp::rule<struct i64_, Scalar> i64_rule = "i64";
auto const i64_rule_def =
    (bin_rule > bp::lit("i64") | hex_rule > bp::lit("i64") |
     oct_rule > bp::lit("i64") | bp::long_ > bp::lit("i64") | bp::long_);
BOOST_PARSER_DEFINE_RULES(i64_rule);

bp::rule<struct f32_, Scalar> f32_rule = "f32";
auto const f32_rule_def                = bp::float_;
BOOST_PARSER_DEFINE_RULES(f32_rule);

bp::rule<struct f64_, Scalar> f64_rule = "f64";
auto const f64_rule_def                = bp::double_;
BOOST_PARSER_DEFINE_RULES(f64_rule);

bp::rule<struct number, Scalar> number_rule = "number";
auto const number_rule_def                  = ;

bp::rule<struct atom, Operand> atom_rule = "atom";
auto const atom_rule_def =
    nil_rule | bool_rule | i64_rule | u64_rule | f64_rule;
BOOST_PARSER_DEFINE_RULES(atom_rule);

bool parse(std::string_view view, env::Context &ctx) { return false; }

} // namespace fun::scan
