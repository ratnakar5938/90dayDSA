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
    int search(int);
    int search_imp(int);
    int get(int);
    void set(int, int);
    int max();
    int min();
    int sum();
    int sum_rec(int);
    float average();
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
    if (index >= 0 && length < size && index <= length)
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
    if (index >= 0 && index < length)
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

int Array::search(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
            return i;
    return -1;
}

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
            swap(A[i], A[0]);
            return 0;
        }
    return -1;
}

int Array::get(int index)
{
    if (index >= 0 && index <= length)
    {
        return A[index];
    }
    return -1;
}

void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}

int Array::max()
{
    int maximum = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > maximum)
        {
            maximum = A[i];
        }
    }
    return maximum;
}

int Array::min()
{
    int minimum = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < minimum)
        {
            minimum = A[i];
        }
    }
    return minimum;
}

int Array::sum()
{
    int sum = A[0];
    for (int i = 1; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}

int Array::sum_rec(int n)
{
    if (n < 0)
    {
        return 0;
    }
    return A[n] + sum_rec(n - 1);
}

float Array::average()
{
    return float(sum()) / length;
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
    // cout << "Enter the index u want to get : ";
    // cin >> n;
    // cout << arr.get(n) << endl;
    // cout << "Enter the index u want to set : ";
    // cin >> n;
    // cout << "Enter the value : ";
    // cin >> x;
    // arr.set(n, x);
    // arr.display();
    cout << "Maximum of the array is : " << arr.max() << endl;
    cout << "Minimum of the array is : " << arr.min() << endl;
    cout << "Sum of the array is : " << arr.sum() << endl;
    cout << "Sum of the array is : " << arr.sum_rec(arr.length - 1) << endl;
    cout << "Average of the array is : " << arr.average() << endl;

    return 0;
}