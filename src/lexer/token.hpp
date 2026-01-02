#pragma once

#include <cstdint>
#include <string>
enum class TokenType
{
    // Special
    EndOfFile,
    Invalid,

    // Identifiers & Literals
    Identifier,     // foo, Bar, my_var
    IntegerLiteral, // 123
    FloatLiteral,   // 3.14
    StringLiteral,  // "hello"
    CharLiteral,    // 'a'

    // Keywords
    KwInt,
    KwBool,
    KwFloat,
    KwVoid,
    KwFn,
    KwReturn,
    KwLet,
    KwIf,
    KwElse,
    KwWhile,
    KwFor,
    KwStruct,
    KwType,

    // Operators
    Plus,    // +
    Minus,   // -
    Star,    // *
    Slash,   // /
    Percent, // %

    Equals,      // =
    PlusEquals,  // +=
    MinusEquals, // -=

    EqualEqual, // ==
    NotEqual,   // !=
    Less,
    LessEqual,
    Greater,
    GreaterEqual,

    AndAnd, // &&
    OrOr,   // ||
    Not,    // !

    Arrow, // => (lambda)

    // Delimiters
    LParen,   // (
    RParen,   // )
    LBrace,   // {
    RBrace,   // }
    LBracket, // [
    RBracket, // ]

    Comma,     // ,
    Dot,       // .
    Colon,     // :
    Semicolon, // ;
};
struct SourceLocation
{
    uint32_t line;
    uint32_t column;
};

struct Token
{
    TokenType type;
    SourceLocation loc;
    std::string lexeme;
};
