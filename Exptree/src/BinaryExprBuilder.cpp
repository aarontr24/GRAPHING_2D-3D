#include "BinaryExprBuilder.h"
#include "NumElemNode.h"
#include <sstream>
#include <iostream>

using namespace std;

BinaryExprBuilder::BinaryExprBuilder()
{
    //ctor
}

BinaryOpNode *BinaryExprBuilder::parse(string &str)
{
    istringstream istr(str); //convierte el string en un vector
    char token;

    while (istr >> token)
    {

        switch (token)
        {

            case '+':
            case '-':
            case '*':
            case '/':
                processOperator(token);
                break;

            case ')':
                processRightParenthesis();
                break;

            case '(':
                operatorStack.push(token);
                break;

            default:
                istr.putback(token);

                double number;
                istr >> number;
                //cout<<number<<endl;

                NumElemNode *newNode = new NumElemNode(number);
                operandStack.push(newNode);

                continue;
        }
    }

    while (!operatorStack.empty())
    {

        doBinary(operatorStack.top());
        operatorStack.pop();
    }


    ExprElemNode *p = operandStack.top();

    return static_cast<BinaryOpNode *> (p);
}

void BinaryExprBuilder::processOperator(char op)
{
    int opPrecedence = precedence(op);

    while((!operatorStack.empty()) && (opPrecedence <= precedence(operatorStack.top())))
    {
        doBinary(operatorStack.top());
        operatorStack.pop();
    }
    operatorStack.push(op);
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
