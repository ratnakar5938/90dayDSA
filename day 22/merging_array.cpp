#include <iostream>

using namespace std;

class Array
{
    int size;

public:
    int *A;
    int length;
    Array(int n)
    {
        size = n;
        A = new int[size];
        length = 0;
    }

    void add(int);
    void display();
    bool sorted();
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

bool Array::sorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

Array merge(Array *a1, Array *a2)
{
    Array merged(a1->length + a2->length);
    int i = 0, j = 0;

    while (i < a1->length && j < a2->length)
    {
        if (a1->A[i] <= a2->A[j])
            merged.add(a1->A[i++]);
        else
            merged.add(a2->A[j++]);
    }

    while (j < a2->length)
        merged.add(a2->A[j++]);

    while (i < a1->length)
        merged.add(a1->A[i++]);

    return merged;
}
// time complexity -> ⊖(m + n)
// m is the order from a1 array
// n is the order from a2 array

int main()
{
    int x;
    cout << "Enter the size of the array : ";
    cin >> x;
    Array arr1(x);

    int n;
    if (x > 2)
    {
        for (int i = 0; i < x - 2; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr1.add(n);
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr1.add(n);
        }
    }

    cout << "Enter the size of the 2nd array : ";
    cin >> x;
    Array arr2(x);

    if (x > 2)
    {
        for (int i = 0; i < x - 2; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr2.add(n);
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            cout << "Enter element no. " << (i + 1) << " : ";
            cin >> n;
            arr2.add(n);
        }
    }

    arr1.display();
    if (arr1.sorted())
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    arr2.display();
    if (arr2.sorted())
        cout << "2nd Array is sorted" << endl;
    else
        cout << "2nd Array is not sorted" << endl;

    Array arr3 = merge(&arr1, &arr2);
    arr3.display();

    return 0;
}