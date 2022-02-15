#include <iostream>

using namespace std;

void perm(char *A, int k)
{
    static int B[10] = {0};
    static char Result[10];
    int i;

    if (A[k] == '\0')
    {
        Result[k] = '\0';
        cout << Result << endl;
        return;
    }

    for (i = 0; A[i] != '\0'; i++)
    {
        if (B[i] == 0)
        {
            Result[k] = A[i];
            B[i] = 1;
            perm(A, k + 1);
            B[i] = 0;
        }
    }
}

template <class T>
void swap(T *a, T *b)
{
    T temp = &a;
    &a = &b;
    &b = temp;
}

void perm2(char *A, int low, int high)
{
    if (low == high)
    {
        cout << A << endl;
        return;
    }

    for (int i = low; i <= high; i++)
    {
        swap(A[low], A[i]);
        perm2(A, low + 1, high);
        swap(A[low], A[i]);
    }
}

int main()
{
    char A[] = "RAJ";
    // perm(A, 0);

    int i = 0;
    while (A[i] != '\0')
        i++;
    perm2(A, 0, i - 1);

    return 0;
}