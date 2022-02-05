#include <iostream>

using namespace std;

// nCr = n!/[(r!)*(n-r)!]

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int c(int n, int r)
{
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);
    return t1 / (t2 * t3);
}
// time complexity -> O(n)

// pascal's triangle -> nCr = (n-1)C(r-1) + (n-1)Cr
int c_PT(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return c_PT(n - 1, r - 1) + c_PT(n - 1, r);
}

int main()
{
    int a = 4, b = 2;
    // cout << c(a, b) << endl;
    cout << c_PT(a, b) << endl;

    return 0;
}