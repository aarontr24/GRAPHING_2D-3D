#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void leer(string str)
{
    istringstream istr(str);
    char token;
    string func;
    while(istr>>token)
    {
        //vector<char> letters {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}

        if ((token >= '0') && (token <= '9') )
        {
            double number;
            istr.putback(token);
            istr>>number;
            cout<<number<<endl;
            //continue;
        }
        else if(token == '+')
        {
            cout<<token<<endl;
            continue;
        }
        else if(token == '(')
        {
            cout<<token<<endl;
        }
        else if(token == ')')
        {
            cout<<token<<endl;
        }
        else
        {

            func.push_back(token);
            if(((istr.peek()>= '0') && (istr.peek()<= '9')) || istr.peek()==istr.eof() || istr.peek()=='('||istr.peek()==')')
            {
                cout<<func<<endl;
            }

        }
    }
}

int main()
{
    string expresion;
    getline(cin,expresion);
    leer(expresion);

    return 0;
}
