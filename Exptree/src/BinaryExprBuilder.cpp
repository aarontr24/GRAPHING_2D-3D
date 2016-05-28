#include "BinaryExprBuilder.h"

map<string,int> precedence = {{"(",0},{"+",1},{"-",1},{"*",2},{"/",2},{"^",3},{"sqrt",3},{"sin",4},{"cos",4},{"tan",4},{"asin",4},{"acos",4},{"atan",4},{"pi",5},{"exp",5},{"--",5}};

BinaryExprBuilder::BinaryExprBuilder()
{
    //ctor
}

void BinaryExprBuilder::set_Var(double Var1, double Var2)
{
    V1=Var1;
    V2=Var2;
}

BinaryOpNode *BinaryExprBuilder::parse(string &str)
{
    //V1=V2=0;
    istringstream istr(str); //convierte el string en un vector
    char token;
    string func;
    string temp2 = "0";
    char temp;
    while(istr>>token)
    {
        if ((token >= '0') && (token <= '9') )
        {
            double number;
            istr.putback(token);
            istr>>number;
            NumElemNode *newNode = new NumElemNode(number);
            operandStack.push(newNode);
        }
        else if(strchr("+-*/^)(",token)!=NULL)
        {
            //cout<<temp<<endl;
            if((temp=='(' || temp==NULL) && token=='-')
            {
                //cout<<string(1,token)+'-'<<endl;
                processOperator(string(1,token)+'-','u');
            }
            else
            {
                if(token==')')
                {
                    processRightParenthesis();
                }
                else if(token=='(')
                {
                    opStr a = {string(1,token),'n'};
                    operatorStack.push(a);
                }
                else
                {
                    processOperator(string(1,token),'b');
                }
            }
        }
        else
        {
            func.push_back(token);
            if(((istr.peek()>= '0') && (istr.peek()<= '9')) || strchr("+-*/^)(",istr.peek())!=NULL || istr.peek()<0)
            {
                if(func.length()==1)
                {
                    if(func=="x")
                    {
                        VariableNode *newNode = new VariableNode(V1);
                        operandStack.push(newNode);
                    }else{
                        VariableNode *newNode = new VariableNode(V2);
                        operandStack.push(newNode);
                    }
                    //cout<<"variable"<<endl;
                }
                else if(func == "pi"){
                    processOperator(func,'p');
                }else
                {
                    processOperator(func,'u');
                    //cout<<func<<endl;
                }
                func.clear();
            }
        }
        temp=token;
    }

    while (!operatorStack.empty())
    {
        do_node();
        operatorStack.pop();
    }

    ExprElemNode *p = operandStack.top();

    return static_cast<BinaryOpNode *> (p);
}

void BinaryExprBuilder::processOperator(string op, char t)
{
    int opPrecedence = precedence.find(op)->second;

    while((!operatorStack.empty()) && (opPrecedence <= precedence.find(operatorStack.top().op)->second))
    {
        do_node();
        operatorStack.pop();
    }
    opStr a = {op,t};
    operatorStack.push(a);
}

void BinaryExprBuilder::processRightParenthesis()
{
    while(!operatorStack.empty() && operatorStack.top().op!="(")
    {
        do_node();
        operatorStack.pop();
    }
    operatorStack.pop(); //Quitamos '('.
}

void BinaryExprBuilder::do_node()
{
    ExprElemNode *right;
    if(operatorStack.top().t=='u'||operatorStack.top().t=='p')
    {
        right = NULL;
    }else{
        right = operandStack.top();
        operandStack.pop();
    }
    ExprElemNode *left;
    if(operatorStack.top().t=='p')
    {
        NumElemNode *newNode = new NumElemNode(M_PI);
        left = newNode;

    }else{
        left = operandStack.top();
        operandStack.pop();
    }
    BinaryOpNode *p = new BinaryOpNode(operatorStack.top().op, left, right);
    operandStack.push(p);
}

BinaryExprBuilder::~BinaryExprBuilder()
{
    //dtor
}
