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
    int opcion;
    cin>>opcion;
    if(opcion==2)
    {
        for(float i=-20;i<=21;i+=0.01)
        {
            b.set_Var(i,0);
            file<<i<<" "<<root->value()<<endl;
        }
    }else
    {
        for(int i=-10;i<=10;i++)
        {
            for(int j=-10;j<=10;j++)
            {
                b.set_Var(i,j);
                file<<i<<" "<<j<<" "<<root->value()<<endl;
            }
        }
    }


    return 0;
}
