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
    void insert(int index, int x);
    int delete_element(int x);
    int search(int x);
    int search_imp(int x);
};

void Array::add(int x)
{
    A[length] = x;
    length++;
}
// Time Complexity -> O(1)

void Array::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Time Complexity -> O(n)

void Array::insert(int index, int x)
{
    if (length < size && index <= length)
    {
        for (int i = length; i >= index; i--)
            A[i] = A[i - 1];

        A[index] = x;
        length++;
    }
    else
    {
        cout << "Not enough space!!!" << endl;
    }
}
// Time complexity -> Best Case = O(1)
//                 -> Worst Case = O(n)

int Array::delete_element(int index)
{
    if (index < length)
    {
        int temp = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return temp;
    }
    cout << "Not possible" << endl;
    return -1;
}
// Time complexity -> Best Case = O(1)
//                 -> Worst Case = O(n)

int Array::search(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
            return i;
    return -1;
}
// Time complexity -> Best Case = O(1)
//                 -> Worst Case = O(n)
// average case -> (1 + 2 + 3 ... + n)/n = n(n+1)/2n = (n+1)/2 -> O(n)

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::search_imp(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
        {
            // transposition
            // swap(A[i], A[i - 1]);
            // return i - 1;

            // move to front
            swap(A[i], A[0]);
            return 0;
        }
    return -1;
}

int main()
{
    int x;
    cout << "Enter the size of the array : ";
    cin >> x;
    Array arr(x);

    int n;
    for (int i = 0; i < x - 2; i++)
    {
        cout << "Enter element no. " << (i + 1) << " : ";
        cin >> n;
        arr.add(n);
    }

    arr.display();
    arr.insert(2, 5);
    arr.display();
    cout << arr.delete_element(1) << endl;
    arr.display();

    cout << "Enter the element u want to search : ";
    cin >> n;
    cout << "The index of " << n << " is : " << arr.search(n) << endl;
    cout << "The index of " << n << " is : " << arr.search_imp(n) << endl;
    arr.display();

    return 0;
}