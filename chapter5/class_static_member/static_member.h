#include <iostream>

using namespace std;

class A
{
    public:
        A();
        A(A &a);

        ~A();

        static void printCount();
    
    private:
        int data;
        static int count;
};
