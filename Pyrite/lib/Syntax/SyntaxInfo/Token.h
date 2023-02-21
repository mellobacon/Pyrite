#pragma once
#include <string>
#include "TokenType.h"
#include "../Parser/Node.h"

class Token final : public Node
{
public:
    std::string tokentext;
    TokenType tokentype{};
    int value;
    Token(const std::string& text, const TokenType toktype, const int val)
    {
        tokentext = text;
        tokentype = toktype;
        value = val;
    }

    TokenType GetType() override;
    std::list<Node*> GetChildren() override;
};
