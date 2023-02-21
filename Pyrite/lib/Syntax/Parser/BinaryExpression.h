#pragma once
#include "Expression.h"

#include <utility>
#include "../SyntaxInfo/Token.h"

class BinaryExpression : public Expression
{
    Expression* _left;
    Token _op;
    Expression* _right;
public:
    BinaryExpression(Expression* left, Token op, Expression* right)
    {
        _left = left;
        _op = std::move(op);
        _right = right;
    }

    TokenType GetType() override;
    std::list<Node&> GetChildren() override;
};
