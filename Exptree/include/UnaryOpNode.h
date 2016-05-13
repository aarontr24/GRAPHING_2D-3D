#ifndef UNARYOPNODE_H
#define UNARYOPNODE_H

#include <ExprElemNode.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

class UnaryOpNode : public ExprElemNode
{
    public:
        UnaryOpNode(char *op, ExprElemNode *c);
        virtual double value();
        virtual ~UnaryOpNode();

    protected:

    private:
        char *unary_op;
        ExprElemNode *child;
};

#endif // UNARYOPNODE_H
