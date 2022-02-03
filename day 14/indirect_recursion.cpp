#include <iostream>

using namespace std;

void B(int);

void A(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        B(n - 1);
    }
}

void B(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        A(n / 2);
    }
}

int main()
{
    int a = 30;
    A(a);
    cout << endl;

    return 0;
}