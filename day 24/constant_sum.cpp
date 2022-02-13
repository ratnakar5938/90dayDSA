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

void constant_sum(Array<int> *arr, int k)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        for (int j = i + 1; j < arr->length; j++)
        {
            if (arr->A[i] + arr->A[j] == k)
                cout << "Sum of " << arr->A[i] << " and " << arr->A[j] << " is " << k << endl;
        }
    }
}

void constant_sum_hash(Array<int> *arr, int k)
{
    int length = arr->max() + 1;
    int *A = new int[length]{0};
    for (int i = 0; i < arr->length; i++)
    {
        if (A[k - arr->A[i]] == 1)
            cout << arr->A[i] << " and " << k - arr->A[i] << " sum up to " << k << endl;
        A[arr->A[i]]++;
    }
}

int main()
{
    int x;
    cout << "Size : ";
    cin >> x;
    Array<int> arr(x);

    int n;
    cout << "Elements : ";
    if (x > 2)
    {
        for (int i = 0; i < x - 2; i++)
        {
            cin >> n;
            arr.add(n);
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            cin >> n;
            arr.add(n);
        }
    }

    arr.display();
    cout << "sum : ";
    cin >> n;

    // constant_sum(&arr, n);
    constant_sum_hash(&arr, n);

    return 0;
}