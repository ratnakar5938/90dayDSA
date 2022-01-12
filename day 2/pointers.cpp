#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p;              // declaration
    p = &a;              // initialization
    int *q = &a;         // declaration and initialization
    int *r = new int[5]; // allocating heap memory

    cout << a << " " << *p << " " << *q << endl;
    return 0;
}