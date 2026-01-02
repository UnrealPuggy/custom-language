#pragma once
#include <vector>
#include <string_view>
#include "token.hpp"

class Lexer
{
public:
    explicit Lexer(std::string_view src)
        : source(src) {}

    std::vector<Token> tokenize();

private:
    std::string_view source;
    size_t pos = 0;
    uint32_t line = 1;
    uint32_t column = 1;

    char peek() const { return pos < source.size() ? source[pos] : '\0'; }
    char advance()
    {
        char c = peek();
        pos++;
        if (c == '\n')
        {
            line++;
            column = 1;
        }
        else
        {
            column++;
        }
        return c;
    }

    Token makeToken(TokenType type, std::string lexeme);
};