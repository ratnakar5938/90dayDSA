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

template <class T>
void Duplicate(Array<T> *arr)
{
    T lastDuplicate = 0;
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1] && arr->A[i] != lastDuplicate)
        {
            lastDuplicate = arr->A[i];
            cout << "Duplicate element : " << lastDuplicate << endl;
        }
    }
}

template <class T>
int Count_duplicate(Array<T> *arr)
{
    int numOfDuplicate = 0;
    int j;
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1])
        {
            j = i + 1;
            while (arr->A[j] == arr->A[i])
                j++;
            cout << arr->A[i] << " is duplicated " << j - i << " times" << endl;
            numOfDuplicate += j - i;
            i = j - 1;
        }
    }
    return numOfDuplicate;
}

void Duplicate_hash(Array<int> *arr)
{

    int length = arr->A[arr->length - 1] + 1;
    int *A = new int[length]{0};

    for (int i = 0; i < arr->length; i++)
    {
        A[arr->A[i]]++;
    }
    for (int i = 0; i < length; i++)
        if (A[i] > 1)
            cout << i << " is duplicated " << A[i] << " times" << endl;
}
// time complexity -> O(n)

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
    // Duplicate(&arr);
    // int totalDuplicates = Count_duplicate(&arr);
    // cout << "Number of total duplicates : " << totalDuplicates << endl;

    Duplicate_hash(&arr);

    return 0;
}