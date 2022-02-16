#include <iostream>

using namespace std;

class Matrix
{
    int len;

public:
    int *A;
    Matrix(int n)
    {
        A = new int[n];
        len = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Matrix() { delete[] A; }
};

void Matrix::set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Matrix::get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    return 0;
}

void Matrix::display()
{
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            cout << get(i, j) << " ";
        }
        cout << endl;
    }
}

int main()
{

    int x, n;
    cin >> n;
    Matrix m1(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        m1.set(i, i, x);
    }

    m1.display();

    return 0;
}