#pragma once
#include <string>

#include "TokenType.h"
#include "../Parser/Node.h"

struct Token final : Node
{
    std::string tokentext;
    TokenType tokentype{};
    Token(const std::string& text, const TokenType toktype)
    {
        tokentext = text;
        tokentype = toktype;
    }

    TokenType GetType() override
    {
        return TokenType::EOF_TOKEN;
    }
    std::list<Node&> GetChildren() override
    {
        return {};
    }
};
