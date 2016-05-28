#ifndef BINARYEXPRBUILDER_H
#define BINARYEXPRBUILDER_H
#include <NumElemNode.h>
#include <ExprElemNode.h>
#include <BinaryOpNode.h>
#include <VariableNode.h>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>
#include <map>

struct opStr{
    string op;
    char t;
};

using namespace std;

class BinaryExprBuilder
{
    public:
        BinaryExprBuilder();
        BinaryOpNode *parse(string &istr);
        void set_Var(double Var1, double Var2);
        virtual ~BinaryExprBuilder();

    protected:

    private:
        stack<opStr> operatorStack;
        stack<ExprElemNode *> operandStack;

        double V1 = 0;
        double V2 = 0;

        void processOperator(string op, char t);
        void processOpUnary(string op);
        void processRightParenthesis();
        void do_node();
};

#endif // BINARYEXPRBUILDER_H
