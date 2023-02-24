#include "BinaryExpression.h"

TokenType BinaryExpression::GetType()
{
    return TokenType::BINARY_EXPRESSION;
}
std::list<Node*> BinaryExpression::GetChildren()
{
    return {_left, &_op, _right};
}
std::map<TokenType, std::string> BinaryExpression::TryGetToken()
{
    return {};
}


