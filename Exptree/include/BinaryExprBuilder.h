#ifndef BINARYEXPRBUILDER_H
#define BINARYEXPRBUILDER_H
#include "NumElemNode.h"
#include <ExprElemNode.h>
#include <BinaryOpNode.h>
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
        virtual ~BinaryExprBuilder();

    protected:

    private:
        stack<opStr> operatorStack;
        stack<ExprElemNode *> operandStack;

        void processOperator(string op, char t);
        void processOpUnary(string op);
        void processRightParenthesis();
        void do_node();
        //int precedence(char op);

};

#endif // BINARYEXPRBUILDER_H
