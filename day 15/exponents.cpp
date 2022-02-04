#include <iostream>

using namespace std;

// a^n = a * a * a... (n times)

int pow(int a, int b)
{
    if (b > 0)

        return a * pow(a, b - 1);
    else
        return 1;
}

int pow2(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return pow2(a * a, b / 2);
    else
        return a * pow2(a * a, b / 2);
}

int pow_iter(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

int main()
{
    int a = 3, b = 5;
    cout << pow(a, b) << endl;
    cout << pow2(a, b) << endl;
    cout << pow_iter(a, b) << endl;
    return 0;
}