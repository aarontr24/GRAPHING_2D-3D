#include <iostream>
#include <BinaryExprBuilder.h>
#include <BinaryOpNode.h>

using namespace std;

int main()
{
    BinaryExprBuilder b;

    cout << "Ingrese una expresion matematica:" << endl;

    string expresion;
    getline(cin, expresion);

    BinaryOpNode *root = b.parse(expresion);

    cout << " resultado = " << root->value();
    return 0;
}
