#include <iostream>

using namespace std;

// swapping using call by value --> doesn't work as it copies the value without changing the actual value
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// swapping using call by address --> does work as it changes the actual value without creating a copy
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// swapping using call by reference --> does work as it changes the actual value without creating a copy
void swap3(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a, b;
    a = 10;
    b = 5;
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;
    swap2(&a, &b);
    cout << a << " " << b << endl;
    swap3(a, b);
    cout << a << " " << b << endl;

    return 0;
}