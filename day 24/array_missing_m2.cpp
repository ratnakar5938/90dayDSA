#include <iostream>

using namespace std;

template <class T>
class Array
{
    int size;

public:
    T *A;
    int length;
    Array(int n)
    {
        size = n;
        A = new int[size];
        length = 0;
    }

    ~Array()
    {
        delete[] A;
    }

    void add(int);
    void display();
    void insert(int, int);
    T delete_element(int);
    int binary_search(int, int, int);
    T max();
    T min();
};

template <class T>
void Array<T>::add(int x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
    else
        cout << "Not Enough Space!!!" << endl;
}

template <class T>
void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::insert(int index, int x)
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

template <class T>
T Array<T>::delete_element(int index)
{
    if (index < length)
    {
        T temp = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return temp;
    }
    cout << "Not possible" << endl;
    return -1;
}

template <class T>
int Array<T>::binary_search(int l, int h, int x)
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

template <class T>
T Array<T>::max()
{
    T maximum = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > maximum)
        {
            maximum = A[i];
        }
    }
    return maximum;
}

template <class T>
T Array<T>::min()
{
    T minimum = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < minimum)
        {
            minimum = A[i];
        }
    }
    return minimum;
}

// application of hash-table/bitset
void find_missing_optimised(Array<int> *arr)
{
    const int length = arr->max() - arr->min();
    int base = arr->min();
    int X[length] = {0};

    for (int i = 0; i < arr->length; i++)
        X[arr->A[i] - base]++;

    for (int i = 0; i < length; i++)
        if (X[i] == 0)
            cout << "Missing element : " << i + base << endl;
}
// time complexity -> O(n)

int main()
{
    int x = 13;
    Array<int> arr1(x);

    arr1.add(3);
    arr1.add(7);
    arr1.add(4);
    arr1.add(11);
    arr1.add(1);
    arr1.add(12);
    arr1.add(5);
    arr1.add(9);
    arr1.add(10);
    arr1.add(2);

    arr1.display();
    find_missing_optimised(&arr1);
    return 0;
}
