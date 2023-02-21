#pragma once
#include <list>
#include "../SyntaxInfo/TokenType.h"

class Node
{
public:
    virtual ~Node() = default;
    
    virtual TokenType GetType() = 0;
    virtual std::list<Node*> GetChildren() = 0;
    
    bool operator==(const Node& node) const;
    bool operator==(Node* node) const;
};
