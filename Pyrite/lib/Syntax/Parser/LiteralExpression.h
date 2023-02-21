#pragma once
#include "Expression.h"
#include "../SyntaxInfo/Token.h"

class LiteralExpression : public Expression
{
    Token _token;
public:
    explicit LiteralExpression(Token token) : _token(std::move(token)){}
    TokenType GetType() override;
    std::list<Node&> GetChildren() override;
};
