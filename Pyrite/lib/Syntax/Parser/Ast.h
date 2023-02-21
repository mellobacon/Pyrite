#pragma once
#include <string>
#include "Expression.h"

class Ast
{
public:
    Expression* root;

    explicit Ast(Expression* e)
    {
        root = e;
    }

    static Ast Parse(const std::string& text);
};
