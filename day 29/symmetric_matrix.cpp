#include <iostream>

using namespace std;

class Symmetric_LT
{
    int *A;
    int n;

public:
    Symmetric_LT(int n)
    {
        A = new int[n * (n - 1) / 2];
        this->n = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Symmetric_LT() { delete[] A; }
};

void Symmetric_LT::set(int i, int j, int x)
{
    if (i >= j)
        A[(i * (i - 1) / 2) + (j - 1)] = x;
}

int Symmetric_LT::get(int i, int j)
{
    if (i >= j)
        return A[(i * (i - 1) / 2) + (j - 1)];
    return A[(j * (j - 1) / 2) + (i - 1)];
}

void Symmetric_LT::display()
{
    for (int i = 1; i <= this->n; i++)
    {
        for (int j = 1; j <= this->n; j++)
            cout << get(i, j) << " ";
        cout << endl;
    }
}

int main()
{
    Symmetric_LT s1(3);
    s1.set(1, 1, 1);
    s1.set(2, 1, 2);
    s1.set(2, 2, 3);
    s1.set(3, 1, 4);
    s1.set(3, 2, 6);
    s1.set(3, 3, 5);

    s1.display();

    return 0;
}