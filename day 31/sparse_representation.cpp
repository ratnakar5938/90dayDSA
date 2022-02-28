#include <iostream>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

class Sparse
{
    int m;
    int n;
    int num;
    Element *e;

public:
    Sparse(int m, int n, int non_zero)
    {
        this->m = m;
        this->n = n;
        this->num = non_zero;
        e = new Element[this->num];
    }
    void set();
    int get(int, int);
    void display();
    ~Sparse() { delete[] e; }
};

void Sparse::set()
{
    int i, j, x;
    cout << "Enter all elements with their respective dimensions" << endl;
    for (int k = 0; k < num; k++)
    {
        cin >> i >> j >> x;
        e[k].i = i;
        e[k].j = j;
        e[k].x = x;
    }
}

int Sparse::get(int r, int c)
{
    for (int i = 0; i < num; i++)
    {
        if (e[i].i == r)
        {
            if (e[i].j == c)
                return e[i].x;
            else if (e[i].j > c)
                return 0;
        }
        else if (e[i].i > r)
            return 0;
    }
}

void Sparse::display()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << get(i, j) << " ";
        cout << endl;
    }
}

int main()
{
    Sparse s1(5, 6, 5);
    s1.set();
    s1.display();
    return 0;
}