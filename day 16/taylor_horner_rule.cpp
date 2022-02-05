#include <iostream>

using namespace std;

// e^x = 1 + (x/1) + (x^2/2!) + (x^3/3!) + (x^4/4!) ...
//     = 1 + (x/1)[1 + (x/2) + (x^2/(2*3)) + (x^3/(2*3*4)]
//     = 1 + (x/1)[1 + (x/2)[1 + (x/3) + (x^2/(3*4)]]
//     = 1 + (x/1)[1 + (x/2)[1 + (x/3)[1 + (x/4)]]]

double e_iter(int x, int n)
{
    double result = 1;
    for (int i = n; i > 0; i--)
    {
        result = 1 + x * result / i;
    }
    return result;
}

double e(int x, int n)
{
    static double result = 1;
    if (n == 0)
        return result;
    result = 1 + x * result / n;
    return e(x, n - 1);
}

int main()
{
    int a = 1, b = 8;
    cout << e_iter(a, b) << endl;
    cout << e(a, b) << endl;
    return 0;
}