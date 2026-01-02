#include "lexer.hpp"

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> tokens;

    while (char c = peek())
    {
        // Save start location for error messages

        unsigned int startLine = line;
        unsigned int startColumn = column;

        // I hate white(myself)
        if (isspace(c))
        {
            advance();
            continue;
        }

        //  Identifiers & shit
        if (isalpha(c) || c == '_')
        {
            std::string text;
            while (isalnum(peek()) || peek() == '_')
            {
                text += advance();
            }

            TokenType type;
            if (text == "int")
                type = TokenType::KwInt;
            else if (text == "fn")
                type = TokenType::KwFn;
            else if (text == "return")
                type = TokenType::KwReturn;
            else
                type = TokenType::Identifier;

            tokens.push_back(Token{type, {startLine, startColumn}, text});
            continue;
        }

        // Integers
        if (isdigit(c))
        {
            std::string text;
            while (isdigit(peek()))
            {
                text += advance();
            }
            tokens.push_back(Token{TokenType::IntegerLiteral, {startLine, startColumn}, text});
            continue;
        }

                switch (c)
        {
        case '+':
            tokens.push_back(makeToken(TokenType::Plus, std::string(1, advance())));
            break;
        case '-':
            advance();
            if (peek() == '>')
            { // Arrow: ->
                advance();
                tokens.push_back(makeToken(TokenType::Arrow, "->"));
            }
            else
            {
                tokens.push_back(makeToken(TokenType::Minus, "-"));
            }
            break;
        case '=':
            tokens.push_back(makeToken(TokenType::Equals, std::string(1, advance())));
            break;
        case '(':
            tokens.push_back(makeToken(TokenType::LParen, "("));
            advance();
            break;
        case ')':
            tokens.push_back(makeToken(TokenType::RParen, ")"));
            advance();
            break;
        case '{':
            tokens.push_back(makeToken(TokenType::LBrace, "{"));
            advance();
            break;
        case '}':
            tokens.push_back(makeToken(TokenType::RBrace, "}"));
            advance();
            break;
        case ';':
            tokens.push_back(makeToken(TokenType::Semicolon, ";"));
            advance();
            break;
        case ',':
            tokens.push_back(makeToken(TokenType::Comma, ","));
            advance();
            break;
        default:
            tokens.push_back(makeToken(TokenType::Invalid, std::string(1, advance())));
            break;
        }
    }

    tokens.push_back(makeToken(TokenType::EndOfFile, ""));
    return tokens;
}

Token Lexer::makeToken(TokenType type, std::string lexeme)
{
    return Token{type, {line, column}, lexeme};
}
