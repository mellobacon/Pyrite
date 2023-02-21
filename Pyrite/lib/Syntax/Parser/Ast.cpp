#include "Ast.h"
#include <iostream>
#include "Parser.h"

Ast Ast::Parse(const std::string& text)
{
    Parser parser(text);
    return parser.Parse();
}

