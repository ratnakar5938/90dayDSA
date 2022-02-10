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
    void insert(int, int);
    int delete_element(int);
    int binary_search(int, int, int);
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

int Array::binary_search(int l, int h, int x)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (A[mid] == x)
        return mid;
    else if (x > A[mid])
        return binary_search(mid + 1, h, x);
    return binary_search(l, mid - 1, x);
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
    cout << "Enter the element u want to search : ";
    cin >> n;
    cout << "The index of " << n << " is : " << arr.binary_search(0, arr.length, n) << endl;
    return 0;
}