#include <iostream>

using namespace std;

int fun(int n)
{
    static int i = 1;
    if (n >= 5)
        return n;
    n += i;
    i++;
    return fun(n);
}

int main()
{
    // find the output of fun(1)
    cout << fun(1) << endl;
    return 0;
}

// logical process
// fun(1) -> n = 2, i = 2, fun(2) -> n = 4, i = 3, fun(4) -> n = 7, i = 4, fun(7) -> return 7;