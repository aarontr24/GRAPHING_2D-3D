#ifndef BINARYEXPRBUILDER_H
#define BINARYEXPRBUILDER_H
#include <stack>
#include <string>
#include <ExprElemNode.h>
#include <BinaryOpNode.h>

using namespace std;

class BinaryExprBuilder
{
    public:
        BinaryExprBuilder();
        BinaryOpNode *parse(string &istr);
        virtual ~BinaryExprBuilder();

    protected:

    private:
        stack<char> operatorStack;
        stack<ExprElemNode *> operandStack;

        void processOperator(char op);
        void processRightParenthesis();
        void doBinary(char op);
        int precedence(char op);

};

#endif // BINARYEXPRBUILDER_H
