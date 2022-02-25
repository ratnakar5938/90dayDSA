#include <iostream>

using namespace std;

class Tridiagonal
{
    int *A;
    int n;

public:
    Tridiagonal(int n)
    {
        A = new int[3 * n - 2];
        this->n = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Tridiagonal() { delete[] A; }
};

void Tridiagonal::set(int i, int j, int x)
{
    int index;
    if (i - j == 1)
    {
        index = i - 2;
        A[index] = x;
    }
    else if (i - j == 0)
    {
        index = (n - 1) + i - 1;
        A[index] = x;
    }
    else if (i - j == -1)
    {
        index = (n * 2) - 1 + i - 1;
        A[index] = x;
    }
}

int Tridiagonal::get(int i, int j)
{
    if (i - j == 1)
        return A[i - 2];
    else if (i - j == 0)
        return A[(n - 1) + i - 1];
    else if (i - j == -1)
        return A[(n * 2) - 1 + i - 1];
    else
        return 0;
}

void Tridiagonal::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << get(i, j) << " ";
        cout << endl;
    }
}

int main()
{
    Tridiagonal t1(5);
    t1.set(1, 1, 2);
    t1.set(1, 2, 2);
    t1.set(2, 1, 2);
    t1.set(2, 2, 2);
    t1.set(2, 3, 2);
    t1.set(3, 1, 2);
    t1.set(3, 2, 2);
    t1.set(3, 3, 2);
    t1.set(3, 4, 2);
    t1.set(4, 3, 2);
    t1.set(4, 4, 2);
    t1.set(4, 5, 2);
    t1.set(5, 4, 2);
    t1.set(5, 5, 2);

    t1.display();

    return 0;
}