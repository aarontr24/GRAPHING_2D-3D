#include <iostream>
#include <string>

using namespace std;

int main()
{
//declaramos una varible double donde alamenaremos el número despues de la conversión
double num=0.0;
//definimos una cadena con un valor de tipo double
string cad="12.3456";
cout<<endl<<endl;
//usamos la función stod() difinida en C++11
num=stod(cad,NULL);
//sumamos un valor para conprobar que la conversión fue correcta
num+=1.0;
//mostramos el resultado final
cout<<cad<<" + "<<1<<" = "<<num<<endl<<endl;

return 0;
}
