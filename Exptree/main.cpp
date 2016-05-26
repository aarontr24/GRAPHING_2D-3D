#include <iostream>
#include <BinaryExprBuilder.h>
#include <BinaryOpNode.h>

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

    cout << " resultado = " << root->value();

    return 0;
}
