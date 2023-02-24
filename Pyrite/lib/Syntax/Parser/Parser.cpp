#include "Parser.h"

#include "BinaryExpression.h"
#include "LiteralExpression.h"
#include "../SyntaxInfo/SyntaxInfo.h"

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
    return ParseBinaryExpression();
}

Expression* Parser::ParseBinaryExpression(const int precedence)
{
    Expression* left = ParseLiteralExpression();
    while (true)
    {
        const int currentprecedence = SyntaxInfo::GetPrecedence(_current);
        if (currentprecedence == precedence || currentprecedence <= precedence)
        {
            break;
        }
        const Token op = GetNextToken();
        Expression* right = ParseBinaryExpression();
        left = new BinaryExpression{left, op, right};
    }
    return left;
}

Expression* Parser::ParseLiteralExpression()
{
    const Token number = GetNextToken();
    return new LiteralExpression{number, number.tokentext};
}


