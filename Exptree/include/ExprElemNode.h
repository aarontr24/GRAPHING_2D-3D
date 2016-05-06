#ifndef EXPRELEMNODE_H
#define EXPRELEMNODE_H


class ExprElemNode
{
    public:
        ExprElemNode();
        virtual double value() = 0; //Retorna el valor de este nodo.
        virtual ~ExprElemNode();

    protected:

    private:
};

#endif // EXPRELEMNODE_H
