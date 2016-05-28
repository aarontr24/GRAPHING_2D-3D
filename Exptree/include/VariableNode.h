#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include <iostream>
#include <ExprElemNode.h>

using namespace std;

class VariableNode : public ExprElemNode
{
    public:
        VariableNode(double &var);
        virtual double value();
        virtual ~VariableNode();

    protected:

    private:
        double *number;
};

#endif // VARIABLENODE_H
