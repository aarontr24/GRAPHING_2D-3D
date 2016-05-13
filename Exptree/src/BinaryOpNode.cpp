#include "BinaryOpNode.h"

BinaryOpNode::BinaryOpNode(char op, ExprElemNode *l, ExprElemNode *r)
{
    binary_op = op;
    left = l;
    right = r;
    //ctor
}

double BinaryOpNode::value()
{
    double leftval = left->value();
    double rightval = right->value();
    double result;

    switch(binary_op)
    {
        case '+':
            result = leftval + rightval;
            break;

        case '-':
            result = leftval - rightval;
            break;

        case '*':
            result = leftval * rightval;
            break;

        case '/':
            result = leftval / rightval;
            break;

        case '^':
            result = pow(leftval,rightval);
            break;
    }
    return result;
}

BinaryOpNode::~BinaryOpNode()
{
    //dtor
}
