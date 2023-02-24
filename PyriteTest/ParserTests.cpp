#include <stack>
#include "../Pyrite/lib/Syntax/Parser/Ast.h"
#include "../Pyrite/lib/Syntax/SyntaxInfo/Token.h"
#include "gtest/gtest.h"

class Assertion
{
    std::vector<TokenType> _tree;
    void CreateTree(Node* node)
    {
        _tree.emplace_back(node->GetType());
        for (Node* child : node->GetChildren())
        {
            CreateTree(child);
        }
    }
    
public:
    explicit Assertion(Node* n)
    {
        CreateTree(n);
    }
    std::vector<TokenType> GetTree() { return _tree;}
};

TEST(Parser, ParserParseBinaryExpression)
{
    const Ast tree = Ast::Parse("1 + 2");
    const auto root = tree.root;

    Assertion treenode(root);
    const std::vector<TokenType> expectedtree = treenode.GetTree();
    const std::vector<TokenType> resultedtree = {
        TokenType::BINARY_EXPRESSION,
        TokenType::LITERAL_EXPRESSION,
        TokenType::NUMBER,
        TokenType::PLUS,
        TokenType::LITERAL_EXPRESSION,
        TokenType::NUMBER
    };
    for (size_t i = 0; i < expectedtree.size(); i++)
    {
        ASSERT_EQ(expectedtree[i], resultedtree[i]);
    }
}
TEST(Parser, ParserRespectsBinaryPrecedence)
{
    const Ast tree = Ast::Parse("1 + 2 * 5");
    const auto root = tree.root;

    Assertion treenode(root);
    const std::vector<TokenType> expectedtree = treenode.GetTree();
    const std::vector<TokenType> resultedtree = {
        TokenType::BINARY_EXPRESSION,
        TokenType::LITERAL_EXPRESSION,
        TokenType::NUMBER,
        TokenType::PLUS,
        TokenType::BINARY_EXPRESSION,
        TokenType::LITERAL_EXPRESSION,
        TokenType::NUMBER,
        TokenType::STAR,
        TokenType::LITERAL_EXPRESSION,
        TokenType::NUMBER,
    };
    for (size_t i = 0; i < expectedtree.size(); i++)
    {
        ASSERT_EQ(expectedtree[i], resultedtree[i]);
    }
}