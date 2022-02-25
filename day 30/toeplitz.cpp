#include <iostream>

using namespace std;

class Toeplitz
{
    int *A;
    int n;

public:
    Toeplitz(int n)
    {
        A = new int[2 * n - 1];
        this->n = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Toeplitz() { delete[] A; }
};

void Toeplitz::set(int i, int j, int x)
{
    if (i <= j)
        A[j - i] = x;
    else
        A[n + i - j - 1] = x;
}

int Toeplitz::get(int i, int j)
{
    if (i <= j)
        return A[j - i];
    else
        return A[n + i - j - 1];
}

void Toeplitz::display()
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
    Toeplitz t1(5);
    t1.set(1, 1, 2);
    t1.set(1, 2, 3);
    t1.set(1, 3, 4);
    t1.set(1, 4, 5);
    t1.set(1, 5, 6);
    t1.set(2, 1, 7);
    t1.set(3, 1, 8);
    t1.set(4, 1, 9);
    t1.set(5, 1, 0);

    t1.display();

    return 0;
}