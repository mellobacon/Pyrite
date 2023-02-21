#include "Parser.h"

#include "BinaryExpression.h"
#include "LiteralExpression.h"

Ast Parser::Parse()
{
    Expression* expression = ParseExpression();
    return Ast{expression};
}

void Parser::Advance()
{
    _position++;
    if ((size_t)_position >= _tokens.size())
    {
        _current = _tokens.back();
    }
    else
    {
        _current = _tokens[_position];
    }
}

Token Parser::GetNextToken()
{
    Token current = _current;
    Advance();
    return current;
}

Expression* Parser::ParseExpression()
{
    Expression* left = ParseLiteralExpression();
    const Token op = GetNextToken();
    Expression* right = ParseLiteralExpression();
    return new BinaryExpression{left, op, right};
}

Expression* Parser::ParseLiteralExpression()
{
    const Token number = GetNextToken();
    return new LiteralExpression{number, number.tokentext};
}


