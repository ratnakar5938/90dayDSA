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
    int search(int);
    int search_imp(int);
    int binary_search(int, int, int);
    void reverse();
    void reverse_imp();
    void l_shift();
    void l_rotate();
    void r_shift();
    void r_rotate();
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
int Array<T>::search(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
            return i;
    return -1;
}

template <class T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <class T>
int Array<T>::search_imp(int x)
{
    for (int i = 0; i < length; i++)
        if (A[i] == x)
        {
            swap(A[i], A[0]);
            return 0;
        }
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
void Array<T>::reverse()
{
    T *B = new int[length];
    for (int i = length - 1; i >= 0; i--)
    {
        B[length - 1 - i] = A[i];
    }
    for (int i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
    delete[] B;
}

template <class T>
void Array<T>::reverse_imp()
{
    T temp;
    for (int i = 0; i < length / 2; i++)
    {
        temp = A[i];
        A[i] = A[length - 1 - i];
        A[length - 1 - i] = temp;
    }
}

template <class T>
void Array<T>::l_shift()
{
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = 0;
}

template <class T>
void Array<T>::l_rotate()
{
    T temp = A[0];
    for (int i = 0; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
}

template <class T>
void Array<T>::r_shift()
{
    for (int i = length - 1; i >= 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = 0;
}

template <class T>
void Array<T>::r_rotate()
{
    T temp = A[length - 1];
    for (int i = length - 1; i >= 0; i--)
    {
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

template <class T>
Array<T> *merge(Array<T> *a1, Array<T> *a2)
{
    Array<T> *merged = new Array<T>(a1->length + a2->length);
    int i = 0, j = 0;

    while (i < a1->length && j < a2->length)
    {
        if (a1->A[i] <= a2->A[j])
            merged->add(a1->A[i++]);
        else
            merged->add(a2->A[j++]);
    }

    while (j < a2->length)
        merged->add(a2->A[j++]);

    while (i < a1->length)
        merged->add(a1->A[i++]);

    return merged;
}

template <class T>
Array<T> *union_unsorted(Array<T> *a1, Array<T> *a2)
{
    Array<T> *united = new Array<T>(a1->length + a2->length);

    int i = 0;
    while (i < a1->length)
        united->add(a1->A[i++]);

    i = 0;
    while (i < a2->length)
        if (united->search(a2->A[i]) == -1)
            united->add(a2->A[i++]);
        else
            i++;

    return united;
}

template <class T>
Array<T> *union_sorted(Array<T> *a1, Array<T> *a2)
{
    Array<T> *united = new Array<T>(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            united->add(a1->A[i]);
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            united->add(a1->A[i++]);
        else
            united->add(a2->A[j++]);

    while (i < a1->length)
        united->add(a1->A[i++]);
    while (j < a2->length)
        united->add(a2->A[j++]);

    return united;
}

template <class T>
Array<T> *intersection(Array<T> *a1, Array<T> *a2)
{
    Array<T> *x = new Array<T>(a1->length + a2->length);
    int i, j;
    for (i = 0; i < a1->length; i++)
    {
        for (j = 0; j < a2->length; j++)
        {
            if (a1->A[i] == a2->A[j])
            {
                x->add(a1->A[i]);
                break;
            }
        }
    }

    return x;
}

template <class T>
Array<T> *intersection_sorted(Array<T> *a1, Array<T> *a2)
{
    Array<T> *x = new Array<T>(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            x->add(a1->A[i]);
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            i++;
        else
            j++;

    return x;
}

template <class T>
Array<T> *difference(Array<T> *a1, Array<T> *a2)
{
    Array<T> *x = new Array<T>(a1->length + a2->length);
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
            x->add(a1->A[i]);
    }
    j = 0;
    while (j < a2->length)
        x->add(a2->A[j++]);

    return x;
}

template <class T>
Array<T> *difference_sorted(Array<T> *a1, Array<T> *a2)
{
    Array<T> *x = new Array<T>(a1->length + a2->length);
    int i = 0, j = 0;
    while (i < a1->length && j < a2->length)
        if (a1->A[i] == a2->A[j])
        {
            i++;
            j++;
        }
        else if (a1->A[i] < a2->A[j])
            x->add(a1->A[i++]);
        else
            x->add(a2->A[j++]);

    while (i < a1->length)
        x->add(a1->A[i++]);
    while (j < a2->length)
        x->add(a2->A[j++]);

    return x;
}

template <class T>
void all_operations(Array<T> *arr, int x)
{
    T n;
    int m;
    switch (x)
    {
    case 1:
        cout << "Enter the value of the element : ";
        cin >> n;
        arr->add(n);
        arr->display();
        break;

    case 2:
        cout << "Enter the value of the element : ";
        cin >> n;
        cout << "Enter the index you want to add to : ";
        cin >> m;
        arr->insert(m, n);
        arr->display();
        break;

    case 3:
        cout << "Enter the index you want to delete : ";
        cin >> m;
        cout << "Element deleted : " << arr->delete_element(m) << endl;
        arr->display();
        break;

    case 4:
        cout << "Enter the value of the element : ";
        cin >> n;
        cout << arr->binary_search(0, arr->length, n) << endl;
        break;

    case 5:
        arr->reverse_imp();
        arr->display();
        break;

    case 6:
        arr->l_shift();
        arr->display();
        break;

    case 7:
        arr->l_rotate();
        arr->display();
        break;

    case 8:
        arr->r_shift();
        arr->display();
        break;

    case 9:
        arr->r_rotate();
        arr->display();
        break;

    default:
        cout << "You entered wrong value" << endl;
        break;
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

    cout << "Enter the size of the 2nd array : ";
    cin >> x;
    Array<int> arr2(x);

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
    Array<int> *arr3;

    cout << "Enter the operation u want to execute : " << endl;
    cout << "1. To select array 1" << endl;
    cout << "2. To select array 2" << endl;
    cout << "3. To select both array" << endl;

    int y;
    cin >> y;

    switch (y)
    {
    case 1:
        cout << "You selected array 1" << endl;
        cout << "The provided array is : ";
        arr1.display();
        cout << "Enter the operation u want to execute : " << endl;
        cout << "1. To add an element in the end" << endl;
        cout << "2. To insert an element" << endl;
        cout << "3. To delete an element" << endl;
        cout << "4. To search an element" << endl;
        cout << "5. To reverse the array" << endl;
        cout << "6. To left shift the array" << endl;
        cout << "7. To left rotate the array" << endl;
        cout << "8. To right shift the array" << endl;
        cout << "9. To right rotate the array" << endl;
        cin >> x;
        all_operations(&arr1, x);
        break;

    case 2:
        cout << "You selected array 2" << endl;
        cout << "The provided array is : ";
        arr2.display();
        cout << "Enter the operation u want to execute : " << endl;
        cout << "1. To add an element in the end" << endl;
        cout << "2. To insert an element" << endl;
        cout << "3. To delete an element" << endl;
        cout << "4. To search an element" << endl;
        cout << "5. To reverse the array" << endl;
        cout << "6. To left shift the array" << endl;
        cout << "7. To left rotate the array" << endl;
        cout << "8. To right shift the array" << endl;
        cout << "9. To right rotate the array" << endl;
        cin >> x;
        all_operations(&arr2, x);
        break;

    case 3:
        cout << "You selected both arrays" << endl;
        cout << "The provided array is : \n";
        arr1.display();
        arr2.display();
        cout << "Enter the operation u want to execute : " << endl;
        cout << "1. To merge" << endl;
        cout << "2. To get union of unsorted array" << endl;
        cout << "3. To get union of sorted array" << endl;
        cout << "4. To get intersection of unsorted array" << endl;
        cout << "5. To get intersection of sorted array" << endl;
        cout << "6. To get difference of unsorted array" << endl;
        cout << "7. To get difference of sorted array" << endl;
        cin >> x;

        switch (x)
        {
        case 1:
            arr3 = merge(&arr1, &arr2);
            arr3->display();
            break;

        case 2:
            arr3 = union_unsorted(&arr1, &arr2);
            arr3->display();
            break;

        case 3:
            arr3 = union_sorted(&arr1, &arr2);
            arr3->display();
            break;

        case 4:
            arr3 = intersection(&arr1, &arr2);
            arr3->display();
            break;

        case 5:
            arr3 = intersection_sorted(&arr1, &arr2);
            arr3->display();
            break;

        case 6:
            arr3 = difference(&arr1, &arr2);
            arr3->display();
            break;

        case 7:
            arr3 = difference_sorted(&arr1, &arr2);
            arr3->display();
            break;

        default:
            cout << "You entered wrong value" << endl;
            break;
        }
        break;

    default:
        cout << "You entered wrong value" << endl;
        break;
    }

    return 0;
}