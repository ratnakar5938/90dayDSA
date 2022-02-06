#include <iostream>

using namespace std;

int fun(int n)
{
    int x = 1, k;
    if (n == 1)
        return x;
    for (k = 1; k < n; ++k)
    {
        x = x + fun(k) * fun(n - k);
    }
    return x;
}

int main()
{
    // find the output
    cout << fun(5) << endl;
    return 0;
}

// logical process ->
// fun(5) -> x = 1 , x = x + fun(1) * fun(4) + fun(2) * fun(3) + fun(3) * fun(2) + fun(4) * fun(1) -> x = 1 + 15 + 10 + 10 + 15 = 51 -> 51
// fun(4) -> x = 1, x = x + fun(1) * fun(3) + fun(2) * fun(2) + fun(3) * fun(1) -> x = 1 + 5 + 4 + 5 = 15 -> 15
// fun(3) -> x = 1, x = x + fun(1) * fun(2) + fun(2) * fun(1) -> x = 1 + 2 + 2 = 5 -> 5
// fun(2) -> x = 1, x = x + fun(1) * fun(1) -> x = 2 -> 2
// fun(1) -> 1
// returns bottom to up -> o/p = 51