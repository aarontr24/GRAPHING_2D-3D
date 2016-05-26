#ifndef BINARYOPNODE_H
#define BINARYOPNODE_H

#include <ExprElemNode.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;


class BinaryOpNode : public ExprElemNode
{
    public:
        BinaryOpNode(string op, ExprElemNode *l, ExprElemNode *r);
        virtual double value();
        virtual ~BinaryOpNode();

    protected:

    private:
        string binary_op;
        ExprElemNode *left;
        ExprElemNode *right;
};

#endif // BINARYOPNODE_H
