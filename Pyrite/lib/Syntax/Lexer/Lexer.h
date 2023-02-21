#pragma once
#include <string>
#include <utility>
#include <vector>
#include "../SyntaxInfo/Token.h"

class Lexer
{
    int _position{};
    int _start{};
    char _current{};
    int _value{};
    TokenType _type = TokenType::EOF_TOKEN;
    std::string _current_string;
    void Advance();
    char Peek(int offset) const;

    void LexNumber();
    void LexWhitespace();
public:
    std::string text;

    explicit Lexer(std::string t)
    {
        text = std::move(t);
        _current = text[0];
    }
    Token Lex();
};
