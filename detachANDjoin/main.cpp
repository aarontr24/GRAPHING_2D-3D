#include <iostream>
#include <thread>
using namespace std;

void function_1() {
        std::cout << "This is a message to nothing" << std::endl;
    }

class Fctor {
public:
    void operator()(string& msg) {
        cout < "t1 say: " << msg << endl;
        msg = "Trust is the mother of deceit.";
    }
};
int main()
{
    string s = "Where there is no trust, there is no love";
    std::thread t1(((Fctor()),s));
    //t1.join();
    t1.join();


    if (t1.joinable())
        t1.join();

    return 0;
}
