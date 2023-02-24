#include "LiteralExpression.h"

TokenType LiteralExpression::GetType()
{
    return TokenType::LITERAL_EXPRESSION;
}

std::list<Node*> LiteralExpression::GetChildren()
{
    return {&_token};
}
std::map<TokenType, std::string> LiteralExpression::TryGetToken()
{
    return {};
}
