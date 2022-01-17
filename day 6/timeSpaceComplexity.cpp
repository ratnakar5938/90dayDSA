#include <iostream>

using namespace std;

int A[10][10];
int B[10][10];
int C[10][10];

int sum(int A[], int n)
{
    int s, i;
    s = 0;
    for (i = 0; i < n; i++)
    {
        s += A[i];
    }
    return s;
}
// time complexity -> O(n)

void swap(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
}
// time complexity -> O(1)

void add(int n)
{
    int i, j;
    const int s = n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
// time complexity -> O(n2)

int main()
{
    cout << "Time Complexity\n";
    return 0;
}