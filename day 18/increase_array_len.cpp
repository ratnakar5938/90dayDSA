#include <iostream>

using namespace std;

int main()
{
    int *p = new int[5];

    for (int i = 0; i < 5; i++)
    {
        p[i] = 2 * (i + 1);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    int *q = new int[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            q[i] = p[i];
        else
            q[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    delete[] p;
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}