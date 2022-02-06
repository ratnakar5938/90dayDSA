#include <iostream>

using namespace std;

int f(int &x, int c)
{
    c -= 1;
    if (c == 0)
        return 1;
    x += 1;
    return f(x, c) * x;
}

int main()
{
    // find the output
    int p = 5;
    cout << f(p, p) << endl;
    return 0;
}

// logical process ->
// f(5, 5) -> c = 4, x = 6, f(6,4)
// f(6, 4) -> c = 3, x = 7, f(7, 3)
// f(7, 3) -> c = 2, x = 8, f(8, 2)
// f(8, 2) -> c = 1, x = 9, f(9, 1)
// f(9, 1) -> c = 0, x = 9 return 1
// return 1*9 -> 9*9 -> 81*9 -> 729*9