#include <iostream>

using namespace std;

class Array
{
    int *A;
    int size;

public:
    int length;
    Array(int n)
    {
        size = n;
        A = new int[size];
        length = 0;
    }

    void add(int);
    void display();
    void reverse();
    void reverse_imp();
    void l_shift();
    void l_rotate();
    void r_shift();
    void r_rotate();
};

void Array::add(int x)
{
    A[length] = x;
    length++;
}

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::reverse()
{
    int *B = new int[length];
    for (int i = length - 1; i >= 0; i--)
    {
        B[length - 1 - i] = A[i];
    }
    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
    delete[] B;
}

void Array::reverse_imp()
{
    int temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = A[i];
        A[i] = A[length - 1 - i];
        A[length - 1 - i] = temp;
    }
}

void Array::l_shift()
{
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}

void Array::l_rotate()
{
    int temp = A[0];
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
}

void Array::r_shift()
{
    for (int i = length - 1; i >= 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

void Array::r_rotate()
{
    int temp = A[length - 1];
    for (int i = length - 1; i >= 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

int main()
{
    int x;
    cout << "Enter the size of the array : ";
    cin >> x;
    Array arr(x);

    int n;
    if (x > 2)
    {
        for (int i = 0; i < x - 2; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr.add(n);
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr.add(n);
        }
    }

    arr.display();
    arr.reverse();
    arr.display();
    arr.reverse_imp();
    arr.display();
    // arr.l_shift();
    // arr.l_rotate();
    // arr.r_shift();
    arr.r_rotate();
    arr.display();

    return 0;
}