#include "BinaryOpNode.h"

BinaryOpNode::BinaryOpNode(string op, ExprElemNode *l, ExprElemNode *r)
{
    binary_op = op;
    left = l;
    right = r;
    //ctor
}

double BinaryOpNode::value()
{
    double leftval = left->value();
    double rightval;
    if(right==NULL){
        rightval = NULL;
    }else{
        rightval = right->value();
    }

    double result;
    if(binary_op=="+")
    {
        result = leftval + rightval;
    }else if(binary_op=="-")
    {

        if(rightval==NULL)
        {
            result = -leftval;
        }else{
            result = leftval - rightval;
        }
    }else if(binary_op=="sin")
    {
        result = sin(leftval);
    }
    /*
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

    */
    return result;
}

BinaryOpNode::~BinaryOpNode()
{
    //dtor
}
