#pragma once
#include "Expression.h"
#include "../SyntaxInfo/Token.h"

class LiteralExpression final : public Expression
{
    Token _token;
    std::string _value;
public:
    explicit LiteralExpression(Token token, const std::string& value) : _token(std::move(token))
    {
        _value = value;
    }
    TokenType GetType() override;
    std::list<Node*> GetChildren() override;
};
