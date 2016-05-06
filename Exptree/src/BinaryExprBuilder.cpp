#include "BinaryExprBuilder.h"

BinaryExprBuilder::BinaryExprBuilder()
{
    //ctor
}

BinaryOpNode *BinaryExprBuilder::parse(string &istr)
{

}

void BinaryExprBuilder::processOperator(char op)
{

}

void BinaryExprBuilder::processRightParenthesis()
{
    while(!operatorStack.empty() && operatorStack.top()!='(')
    {
        doBinary(operatorStack.top());
        operatorStack.pop();
    }
    operatorStack.pop(); //Quitamos '('.
}

void BinaryExprBuilder::doBinary(char op)
{
    ExprElemNode *right = operandStack.top();
    operandStack.pop();
    ExprElemNode *left = operandStack.top();
    operandStack.pop();
    BinaryOpNode *p = new BinaryOpNode(operatorStack.top(), left, right);
    operandStack.push(p);
}

int BinaryExprBuilder::precedence(char op)
{
    enum
    {
        lvl0, lvl1, lvl2
    };

    switch(op)
    {
        case '+':
        case '-':
            return lvl1;
        case '*':
        case '/':
            return lvl2;
        default:
            return lvl0;
    }
}

BinaryExprBuilder::~BinaryExprBuilder()
{
    //dtor
}
