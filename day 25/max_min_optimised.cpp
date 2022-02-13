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

void min_max_opt(Array<int> *arr)
{
    int max = arr->A[0], min = arr->A[0];
    for (int i = 1; i < arr->length; i++)
        if (arr->A[i] > max)
            max = arr->A[i];
        else if (arr->A[i] < min)
            min = arr->A[i];

    cout << "Max is " << max << "\nMin is " << min << endl;
}
// time complexity -> O(n)

int main()
{
    int x;
    cout << "Size : ";
    cin >> x;
    Array<int> arr(x + 2);

    int n;
    cout << "Elements : ";

    for (int i = 0; i < x; i++)
    {
        cin >> n;
        arr.add(n);
    }

    arr.display();
    min_max_opt(&arr);

    return 0;
}