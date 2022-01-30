#include <iostream>

using namespace std;

int fun(int n)
{
    static int x = 0; // a single copy of this variable is made and used by every call of the function
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    cout << fun(a) << endl;
    return 0;
}