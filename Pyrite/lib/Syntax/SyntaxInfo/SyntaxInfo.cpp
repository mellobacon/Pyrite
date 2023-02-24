#include "SyntaxInfo.h"
#include "Token.h"

int SyntaxInfo::GetPrecedence(const Token& t)
{
    int precedence;
    switch (t.tokentype)
    {
    case TokenType::STAR:
    case TokenType::SLASH:
        precedence = 2;
        break;
    case TokenType::PLUS:
    case TokenType::MINUS:
        precedence = 1;
        break;
    default:
        precedence = 0;
        break;
    }
    return precedence;
}
