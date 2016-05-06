#ifndef NUMELEMNODE_H
#define NUMELEMNODE_H

#include <ExprElemNode.h>


class NumElemNode : public ExprElemNode
{
    public:
        NumElemNode(double val);
        virtual double value();
        virtual ~NumElemNode();

    protected:

    private:
        double number;
};

#endif // NUMELEMNODE_H
