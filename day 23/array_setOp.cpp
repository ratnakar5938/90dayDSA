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
    void insert(int, int);
    int delete_element(int);
    int search(int);
};

void Array::add(int x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
    else
        cout << "Not Enough Space!!!" << endl;
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

int Array::search(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
            return i;
    return -1;
}

Array union_unsorted(Array *a1, Array *a2)
{
    Array united(a1->length + a2->length);

    int i = 0;
    while (i < a1->length)
        united.add(a1->A[i++]);

    i = 0;
    while (i < a2->length)
        if (united.search(a2->A[i]) == -1)
            united.add(a2->A[i++]);
        else
            i++;

    return united;
}
// Time taken -> n + n * n
// Time complexity -> O(n^2)

Array union_sorted(Array *a1, Array *a2)
{
    Array united(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            united.add(a1->A[i]);
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            united.add(a1->A[i++]);
        else
            united.add(a2->A[j++]);

    while (i < a1->length)
        united.add(a1->A[i++]);
    while (j < a2->length)
        united.add(a2->A[j++]);

    return united;
}
// Time taken -> m + n
// Time complexity -> ⊖(m + n) -> ⊖(n + n) -> ⊖(2n) -> ⊖(n)

Array intersection(Array *a1, Array *a2)
{
    Array x(a1->length + a2->length);
    int i, j;
    for (i = 0; i < a1->length; i++)
    {
        for (j = 0; j < a2->length; j++)
        {
            if (a1->A[i] == a2->A[j])
            {
                x.add(a1->A[i]);
                break;
            }
        }
    }

    return x;
}
// Time taken -> m * n
// Time complexity -> O(n^2)

Array intersection_sorted(Array *a1, Array *a2)
{
    Array x(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            x.add(a1->A[i]);
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            i++;
        else
            j++;

    return x;
}
// Time taken -> m + n
// Time complexity -> ⊖(m + n) -> ⊖(n + n) -> ⊖(2n) -> ⊖(n)

Array difference(Array *a1, Array *a2)
{
    Array x(a1->length + a2->length);
    int i, j;
    bool b;
    for (i = 0; i < a1->length; i++)
    {
        b = true;
        for (j = 0; j < a2->length; j++)
        {
            if (a1->A[i] == a2->A[j])
            {
                a2->delete_element(j);
                b = false;
                break;
            }
        }
        if (b)
            x.add(a1->A[i]);
    }
    j = 0;
    while (j < a2->length)
        x.add(a2->A[j++]);

    return x;
}
// Time taken -> m * n + n
// Time complexity -> O(n^2)

Array difference_sorted(Array *a1, Array *a2)
{
    Array x(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            x.add(a1->A[i++]);
        else
            x.add(a2->A[j++]);

    while (i < a1->length)
        x.add(a1->A[i++]);
    while (j < a2->length)
        x.add(a2->A[j++]);

    return x;
}
// Time taken -> m + n
// Time complexity -> ⊖(m + n) -> ⊖(n + n) -> ⊖(2n) -> ⊖(n)

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

    arr1.display();

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

    arr2.display();

    // Array arr3 = union_unsorted(&arr1, &arr2);
    // Array arr3 = union_sorted(&arr1, &arr2);
    // Array arr3 = intersection(&arr1, &arr2);
    // Array arr3 = intersection_sorted(&arr1, &arr2);
    // Array arr3 = difference(&arr1, &arr2);
    Array arr3 = difference_sorted(&arr1, &arr2);
    arr3.display();

    return 0;
}