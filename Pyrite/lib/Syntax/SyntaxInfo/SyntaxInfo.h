#pragma once
#include "Token.h"

static class SyntaxInfo
{
public:
    static int GetPrecedence(const Token& t);
};
