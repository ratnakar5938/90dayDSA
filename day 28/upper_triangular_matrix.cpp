#include <iostream>

using namespace std;

class Upper_Triangular_RM
{
    int *A;
    int n;

public:
    Upper_Triangular_RM(int n)
    {
        A = new int[n * (n - 1) / 2];
        this->n = n;
    }
    void set(int, int, int);
    int get(int, int);
    void display();
    ~Upper_Triangular_RM() { delete[] A; }
};

void Upper_Triangular_RM::set(int i, int j, int x)
{
    if (i <= j)
        A[((n * (i - 1)) - (i * (i - 1) / 2)) + (j - i)] = x;
}

int Upper_Triangular_RM::get(int i, int j)
{
    if (i <= j)
        return A[((n * (i - 1)) - (i * (i - 1) / 2)) + (j - i)];
    return 0;
}

void Upper_Triangular_RM::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << get(i, j) << " ";
        cout << endl;
    }
}

int main()
{
    // int n;
    // cout << "Enter Dimension : ";
    // cin >> n;
    Upper_Triangular_RM u1(5);

    // int x;
    // cout << "Enter the elements : \n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> x;
    //         u1.set(i, j, x);
    //     }
    // }
    u1.set(1, 1, 5);
    u1.set(1, 2, 5);
    u1.set(1, 3, 5);
    u1.set(1, 4, 5);
    u1.set(1, 5, 5);
    u1.set(2, 2, 5);
    u1.set(2, 3, 5);
    u1.set(2, 4, 5);
    u1.set(2, 5, 5);
    u1.set(3, 3, 5);
    u1.set(3, 4, 5);
    u1.set(3, 5, 5);
    u1.set(4, 4, 5);
    u1.set(4, 5, 5);
    u1.set(5, 5, 5);

    u1.display();

    return 0;
}