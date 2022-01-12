#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &r = a; // reference variable
    cout << a << endl;
    r++;
    cout << a << endl;
    cout << r << endl;
    return 0;
}