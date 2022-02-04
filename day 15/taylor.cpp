#include <iostream>

using namespace std;

// e^x = 1 + (x/1!) + (x^2/2!) ... n times

double e(int x, int n)
{
    static double p = 1;
    static double f = 1;
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + (p / f);
}

int main()
{
    int a = 3, b = 15;
    cout << e(a, b) << endl;

    return 0;
}