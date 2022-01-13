#include <iostream>

using namespace std;

void fun(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

int *fun2(int n)
{
    int *p;
    p = new int[n]();
    return p;
}

int main()
{
    int funNumber[] = {2, 4, 6, 8, 10, 12};
    fun(funNumber, 6);
    int *A;
    A = fun2(5);
    for (int i = 0; i < 5; i++)
    {
        A[i] = (i + 1) * 5;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}