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
    list_op.insert(pair<string,double>("--",-(leftval)));
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

    return list_op.find(binary_op)->second;

}

BinaryOpNode::~BinaryOpNode()
{
    //dtor
}
