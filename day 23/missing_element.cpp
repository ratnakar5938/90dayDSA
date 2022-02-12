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

// sum method
void find_missing(Array<int> *arr)
{
    int diff = arr->A[1] - arr->A[0];
    int start = arr->A[0];
    int end = arr->A[arr->length - 1];
    int s = 0, sum = 0;
    int term = ((end - start) / diff) + 1;
    s = (term / 2) * (start + end);
    for (int i = 0; i < arr->length; i++)
    {
        sum += arr->A[i];
    }
    cout << "The missing element is : " << (s - sum) << endl;
}

// differnce method
void find_missing2(Array<int> *arr)
{
    int diff = arr->A[1] - arr->A[0];
    int constant = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] - (i * diff) != constant)
        {
            cout << "Missing element is : " << arr->A[0] + (i * diff) << endl;
            break;
        }
    }
}

int main()
{
    int x;
    cout << "Enter the size of the array : ";
    cin >> x;
    Array<int> arr1(x);

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

    arr1.display();
    // find_missing(&arr1);
    find_missing2(&arr1);
    return 0;
}