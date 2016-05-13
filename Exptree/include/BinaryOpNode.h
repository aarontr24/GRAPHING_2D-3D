#ifndef BINARYOPNODE_H
#define BINARYOPNODE_H

#include <ExprElemNode.h>
#include <math.h>


class BinaryOpNode : public ExprElemNode
{
    public:
        BinaryOpNode(char op, ExprElemNode *l, ExprElemNode *r);
        virtual double value();
        virtual ~BinaryOpNode();

    protected:

    private:
        char binary_op;
        ExprElemNode *left;
        ExprElemNode *right;
};

#endif // BINARYOPNODE_H
