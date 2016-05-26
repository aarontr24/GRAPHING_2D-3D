#include "BinaryOpNode.h"

BinaryOpNode::BinaryOpNode(string op, ExprElemNode *l, ExprElemNode *r)
{
    binary_op = op;
    left = l;
    right = r;
    //ctor
}

double BinaryOpNode::value()
{
    double leftval = left->value();
    double rightval;

    if(right==NULL){
        rightval = NULL;
    }else{
        rightval = right->value();
    }

    map<string,double> list_op;
    list_op.insert(pair<string,double>("+",leftval+rightval));
    list_op.insert(pair<string,double>("-",leftval-rightval));
    list_op.insert(pair<string,double>("*",leftval*rightval));
    list_op.insert(pair<string,double>("/",leftval/rightval));
    list_op.insert(pair<string,double>("^",pow(leftval,rightval)));
    list_op.insert(pair<string,double>("sqrt",sqrt(leftval)));
    list_op.insert(pair<string,double>("pi",leftval));
    list_op.insert(pair<string,double>("exp",exp(leftval)));
    //list_op.insert(pair<string,double>("abs",abs(leftval)));
    list_op.insert(pair<string,double>("sin",sin(leftval)));
    list_op.insert(pair<string,double>("cos",cos(leftval)));
    list_op.insert(pair<string,double>("tan",tan(leftval)));;
    list_op.insert(pair<string,double>("asin",asin(leftval)));;
    list_op.insert(pair<string,double>("acos",acos(leftval)));
    list_op.insert(pair<string,double>("atan",atan(leftval)));
    //cout<<leftval<<" "<<rightval<<endl;
    //cout<<list_op.find(binary_op)->first<<endl;
    return list_op.find(binary_op)->second;


    /*

    double result;
    if(binary_op=="+")
    {
        result = leftval + rightval;
    }else if(binary_op=="-")
    {

        if(rightval==NULL)
        {
            result = -leftval;
        }else{
            result = leftval - rightval;
        }
    }else if(binary_op=="sin")
    {
        result = sin(leftval);
    }
    /*
    switch(binary_op)
    {
        case '+':
            result = leftval + rightval;
            break;

        case '-':
            result = leftval - rightval;
            break;

        case '*':
            result = leftval * rightval;
            break;

        case '/':
            result = leftval / rightval;
            break;

        case '^':
            result = pow(leftval,rightval);
            break;
    }


    return result;
    */
}

BinaryOpNode::~BinaryOpNode()
{
    //dtor
}
