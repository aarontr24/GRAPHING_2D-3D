#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;

void leer(string str)
{
    istringstream istr(str);
    char token;
    string func;
    char temp;
    while(istr>>token)
    {
        if ((token >= '0') && (token <= '9') )
        {
            double number;
            istr.putback(token);
            istr>>number;
            cout<<number<<endl;
            //continue;
        }
        else if(strchr("+-*/^)(",token)!=NULL)
        {
            //cout<<temp<<endl;
            if((temp=='(' || temp==NULL) && token=='-')
            {
                cout<<"negativo"<<endl;
            }
            else{
                cout<<string(1,token)<<endl;
            }

            //continue;
        }
        else
        {
            func.push_back(token);
            if(((istr.peek()>= '0') && (istr.peek()<= '9')) || strchr("+-*/^)(",istr.peek())!=NULL || istr.peek()<0)
            {
                if(func.length()==1)
                {
                    cout<<"variable"<<endl;
                }
                else{
                    cout<<func<<endl;
                }
                func.clear();
            }
        }
        temp=token;
    }
}

int main()
{
    string expresion;
    getline(cin,expresion);
    leer(expresion);

    return 0;
}
