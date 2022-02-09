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

    return 0;
}