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
    void sorted_insert(int);
    bool sorted();
    void rearrange();
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

void Array::sorted_insert(int x)
{
    if (length < size)
    {
        int i = length - 1;
        while (A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
        length++;
        return;
    }
    cout << "Not Enough Space!!!" << endl;
}

bool Array::sorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

void Array::rearrange()
{
    int i = 0, j = length - 1;
    int temp;
    while (i < j)
    {
        if (A[i] >= 0 && A[j] < 0)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
        else
        {
            if (A[j] > 0)
                j--;
            if (A[i] <= 0)
                i++;
        }
    }
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

    // cout << "Enter the integer u want to add : ";
    // cin >> n;
    // arr.sorted_insert(n);

    // if (arr.sorted())
    //     cout << "Array is sorted" << endl;
    // else
    //     cout << "Array is not sorted" << endl;

    arr.rearrange();
    arr.display();

    return 0;
}