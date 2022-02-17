#include <iostream>

using namespace std;

class Lower_Triangular_RM
{
    int *A;
    int n;

public:
    Lower_Triangular_RM(int n)
    {
        A = new int[n * (n + 1) / 2];
        this->n = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Lower_Triangular_RM() { delete[] A; }
};

void Lower_Triangular_RM::set(int i, int j, int x)
{
    if (i >= j)
        A[((i - 1) * (i - 2) / 2) + (j - 2)] = x;
}

int Lower_Triangular_RM::get(int i, int j)
{
    if (i >= j)
        return A[((i - 1) * (i - 2) / 2) + (j - 2)];
    return 0;
}

void Lower_Triangular_RM::display()
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
    Lower_Triangular_RM l1(5);
    l1.set(1, 1, 5);
    l1.set(2, 1, 10);
    l1.set(2, 2, 15);
    l1.set(3, 1, 20);
    l1.set(3, 2, 25);
    l1.set(3, 3, 30);
    l1.set(4, 1, 35);
    l1.set(4, 2, 40);
    l1.set(4, 3, 45);
    l1.set(4, 4, 50);
    l1.set(5, 1, 55);
    l1.set(5, 2, 60);
    l1.set(5, 3, 65);
    l1.set(5, 4, 70);
    l1.set(5, 5, 75);

    l1.display();

    return 0;
}