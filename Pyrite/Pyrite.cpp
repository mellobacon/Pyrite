#include <iostream>
#include "lib/Syntax/Parser/Parser.h"

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
    case TokenType::BINARY_EXPRESSION:
        std::cout << "BINARY_EXPRESSION";
        break;
    case TokenType::LITERAL_EXPRESSION:
        std::cout << "LITERAL_EXPRESSION";
        break;
    case TokenType::PLUS:
        std::cout << "PLUS";
        break;
    case TokenType::MINUS:
        std::cout << "MINUS";
        break;
    case TokenType::SLASH:
        std::cout << "SLASH";
        break;
    case TokenType::STAR:
        std::cout << "STAR";
        break;
    case TokenType::MOD:
        std::cout << "MODULO";
        break;
    default:
        std::cout << "NUMBER";
    }

    if (!node->TryGetToken().empty())
    {
        for (const std::pair<const TokenType, std::string>& x : node->TryGetToken())
        {
            std::cout << " " << x.second;
        }
    }

    std::cout << std::endl;
    if (islast)
    {
        indent += "   ";
    }
    else
    {
        indent += "|  ";
    }

    auto x = node->GetChildren();
    for (Node* child : node->GetChildren())
    {
        PrintTree(child, indent, child == node->GetChildren().back());
    }
}

void Start()
{
    std::cout << "Pyrite v0.0.0" << std::endl;
    while (true)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
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

