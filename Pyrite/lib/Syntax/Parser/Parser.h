#pragma once
#include <string>
#include <utility>

#include "Ast.h"
#include "Expression.h"
#include "../Lexer/Lexer.h"
#include "../SyntaxInfo/Token.h"

class Parser
{
    std::vector<Token> _tokens;
    Token _current;
    int _position{};

    void Advance();
    Token GetNextToken();

    Expression* ParseExpression();
    Expression* ParseLiteralExpression();
public:
    explicit Parser(std::string t) : _current(Token{"", TokenType::EOF_TOKEN})
    {
        Lexer lexer(std::move(t));
        while (true)
        {
            Token token = lexer.Lex();
            if (token.tokentype == TokenType::EOF_TOKEN)
            {
                break;
            }
            _tokens.emplace_back(token);
        }
        _current = _tokens[0];
    }
    Ast Parse();
};
