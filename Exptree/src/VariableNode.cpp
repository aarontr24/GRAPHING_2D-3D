#include "VariableNode.h"

VariableNode::VariableNode(double &var)
{
    number=&var;
    //ctor
}

double VariableNode::value()
{
    return *number;
}

VariableNode::~VariableNode()
{
    //dtor
}
