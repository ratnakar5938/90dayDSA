#include <iostream>

using namespace std;

// n! = n * (n-1) * (n-2) ... 3 * 2 * 1

int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}

int factorial_iter(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int a = 5;
    cout << factorial(a) << endl;
    cout << factorial_iter(a) << endl;
    return 0;
}