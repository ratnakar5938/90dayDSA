#include <iostream>

using namespace std;

class Array
{
    int *A;
    int size;
    int length;

public:
    Array(int n)
    {
        size = n;
        A = new int[size];
        length = 0;
    }

    void add(int x);
    void display();
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

int main()
{
    int x;
    cout << "Enter the size of the array : ";
    cin >> x;
    Array arr(x);

    int n;
    for (int i = 0; i < x; i++)
    {
        cout << "Enter element no. " << (i + 1) << " : ";
        cin >> n;
        arr.add(n);
    }

    arr.display();

    return 0;
}