#include <iostream>
#include <BinaryExprBuilder.h>
#include <BinaryOpNode.h>
#include <fstream>

using namespace std;

int main()
{
    /*
    NumElemNode num1(30);
    NumElemNode num2(20);
    UnaryOpNode *n = new UnaryOpNode("tan", &num1);
    cout<< n->value();
    */
    BinaryExprBuilder b;

    cout << "Ingrese una expresion matematica:" << endl;

    string expresion;
    getline(cin, expresion);

    BinaryOpNode *root = b.parse(expresion);

    ofstream file("graph.dat");
    for(float i=-20;i<=41;i+=0.01)
    {
        b.set_Var(i,0);
        file<<i<<" "<<root->value()<<endl;
    }

    /*
    b.set_Var(-5,0);
    cout << " resultado = " << root->value();
    b.set_Var(-4,0);
    cout << " resultado = " << root->value();
    b.set_Var(-3,0);
    cout << " resultado = " << root->value();
    b.set_Var(-2,0);
    cout << " resultado = " << root->value();
    b.set_Var(-1,0);
    cout << " resultado = " << root->value();
    b.set_Var(0,0);
    cout << " resultado = " << root->value();
    b.set_Var(1,0);
    cout << " resultado = " << root->value();
    b.set_Var(2,0);
    cout << " resultado = " << root->value();
    b.set_Var(3,0);
    cout << " resultado = " << root->value();
    b.set_Var(4,0);
    cout << " resultado = " << root->value();
    b.set_Var(5,0);
    cout << " resultado = " << root->value();
    b.set_Var(6,0);
    cout << " resultado = " << root->value();
    b.set_Var(7,0);
    cout << " resultado = " << root->value();
    */

    return 0;
}
