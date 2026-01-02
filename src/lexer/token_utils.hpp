#include <string>
#include "token.hpp"
std::string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::EndOfFile:
        return "EndOfFile";
    case TokenType::Invalid:
        return "Invalid";
    case TokenType::Identifier:
        return "Identifier";
    case TokenType::IntegerLiteral:
        return "IntegerLiteral";
    case TokenType::FloatLiteral:
        return "FloatLiteral";
    case TokenType::StringLiteral:
        return "StringLiteral";

    case TokenType::KwInt:
        return "KwInt";
    case TokenType::KwFn:
        return "KwFn";
    case TokenType::KwReturn:
        return "KwReturn";
    case TokenType::KwLet:
        return "KwLet";

    case TokenType::Plus:
        return "Plus";
    case TokenType::Minus:
        return "Minus";
    case TokenType::Star:
        return "Star";
    case TokenType::Slash:
        return "Slash";
    case TokenType::Equals:
        return "Equals";
    case TokenType::Arrow:
        return "Arrow";

    case TokenType::LParen:
        return "LParen";
    case TokenType::RParen:
        return "RParen";
    case TokenType::LBrace:
        return "LBrace";
    case TokenType::RBrace:
        return "RBrace";
    case TokenType::Comma:
        return "Comma";
    case TokenType::Semicolon:
        return "Semicolon";

    default:
        return "Unknown";
    }
}
