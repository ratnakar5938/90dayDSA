#include <iostream>

using namespace std;

int sumOfFirstN(int n)
{
    if (n > 0)
        return n + sumOfFirstN(n - 1);
    return 0;
}

int sumOfFirstN_iterative(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int a = 4;
    cout << sumOfFirstN(a) << endl;
    cout << sumOfFirstN_iterative(a) << endl;

    return 0;
}