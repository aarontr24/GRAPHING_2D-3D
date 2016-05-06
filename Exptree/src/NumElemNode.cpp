#include "NumElemNode.h"

NumElemNode::NumElemNode(double val)
{
    number = val;
    //ctor
}

double NumElemNode::value()
{
    return number;
}

NumElemNode::~NumElemNode()
{
    //dtor
}
