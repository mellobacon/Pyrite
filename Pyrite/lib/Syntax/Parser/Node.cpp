#include "Node.h"

bool Node::operator==(const Node& node) const
{
    return this == &node;
}

bool Node::operator==(Node* node) const
{
    return this == node;
}

