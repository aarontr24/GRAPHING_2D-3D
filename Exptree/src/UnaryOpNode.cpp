#include "UnaryOpNode.h"

UnaryOpNode::UnaryOpNode(char *op, ExprElemNode *c)
{
    unary_op = op;
    child = c;
    //ctor
}

double UnaryOpNode::value()
{
    double childval = child->value();
    double result;

    switch(unary_op[0])
    {
        case '-':
            result = -childval;
            break;
        case 's':
            cout<<unary_op<<endl;
            result = sin(childval);
            break;
        case 'c':
            result = cos(childval);
            break;
        case 't':
            result = tan(childval);
            break;
    }
    return result;
}

UnaryOpNode::~UnaryOpNode()
{
    //dtor
}
