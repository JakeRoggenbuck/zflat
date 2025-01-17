/**
 * Operator - the operator enum, and precedence.
 */

#pragma once

#include <string>

namespace op {

#define OP_GROUP_SIZE 10

// All operators.
// This is structured so that every group of operators with equivalent
// precedence is separated OP_GROUP_SIZE apart, lowest to highest.
enum Operator {

    // Assignment operators
    EQUALS = 0 * OP_GROUP_SIZE, // =
    ADDEQ, // +=
    SUBEQ, // -=
    MULEQ, // *=
    DIVEQ, // /=
    REMEQ, // %=
    ANDEQ, // &=
    OREQ,  // |=
    XOREQ, // ^=

    // Equality tests
    EQ = 1 * OP_GROUP_SIZE, // ==
    NEQ, // !=

    // Other boolean operators
    GREATER = 2 * OP_GROUP_SIZE, // >
    LESSER,  // <
    GREQ,    // >=
    LESSEQ,  // <=

    // Arithmetic operators
    ADD = 3 * OP_GROUP_SIZE, // +
    SUB, // -
    MUL, // *
    DIV, // /
    REM, // %

    // Bitwise / logical operators
    AND = 4 * OP_GROUP_SIZE, // &
    OR, // |
    XOR, // ^

    ODOT = 5 * OP_GROUP_SIZE, // .

    // The '[]' operator. Cannot be converted to and from strings - must be
    // specially handled in all cases.
    INDEX,

    INVALID,

};

bool is_assign(Operator o);

bool is_bool(Operator o);

// -1 if a binds more tightly than b
// +1 if b binds more tightly than a
// =0 if it doesn't matter (parsed right-to-left)
int binding_order(Operator a, Operator b);

Operator strToOp(std::string in);
std::string opToStr(Operator in);

} // namespace op
