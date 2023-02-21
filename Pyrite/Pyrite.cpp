#include <iostream>
#include "lib/Syntax/Parser/Parser.h"

class Base
{
public:
    virtual void Thing()
    {
        std::cout << "in base";
    }
    
};

class Derived: public Base
{
public:
    void Thing() override
    {
        std::cout << "in derived";
    }
};

void Test()
{
    Base* b = new Base;
    Derived* d = new Derived;
    Base* e = d;
    d->Thing();
}

bool operator==(Node* lhs, const Node& rhs);

void PrintTree(Node* node, std::string indent = "", bool islast = true)
{
    std::string marker;
    if (islast)
    {
        marker = "└──";
    }
    else
    {
        marker = "├──";
    }
    std::cout << indent;
    std::cout << marker;
    switch (node->GetType())  // NOLINT(clang-diagnostic-switch-enum)
    {
    case TokenType::LITERAL_EXPRESSION:
        std::cout << "LITERAL_EXPRESSION" << std::endl;
        break;
    case TokenType::PLUS:
        std::cout << "PLUS" << std::endl;
        break;
    case TokenType::MINUS:
        std::cout << "MINUS" << std::endl;
        break;
    case TokenType::SLASH:
        std::cout << "SLASH" << std::endl;
        break;
    case TokenType::STAR:
        std::cout << "STAR" << std::endl;
        break;
    case TokenType::MOD:
        std::cout << "MODULO" << std::endl;
        break;
    default:
        std::cout << " ";
    }

    std::cout << "\n";
    if (islast)
    {
        indent = "   ";
    }
    else
    {
        indent = "|  ";
    }
    
    auto last = &node->GetChildren().back();
    for (Node& child : node->GetChildren())
    {
        PrintTree(&child, indent, child == last);
    }
}

void Start()
{
    std::cout << "Pyrite v0.0.0" << std::endl;
    while (true)
    {
        std::cout << "> ";
        std::string input;
        std::cin >> input;
        if (input == "exit") break;
        const Ast tree = Ast::Parse(input);
        PrintTree(tree.root);
    }
}

int main(int argc, char* argv[])
{
    Start();
    return 0;
}

