#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int width;
};

// call by value
int area(Rectangle r)
{
    int area = r.length * r.width;
    return area;
}

// call by reference
int area2(Rectangle &r)
{
    int area = r.length * r.width;
    return area;
}

// call by address
void changeLength(Rectangle *r)
{
    r->length += 5;
}

class Test
{
public:
    int A[5];
    int n;
};

void fun(Test t)
{
    t.A[0] = 10;
    t.A[1] = 9;
}

void fun2(Test *t)
{
    t->A[0] = 10;
    t->A[1] = 9;
    t->A[2] = 8;
    t->A[3] = 7;
    t->A[4] = 6;
}

int main()
{
    Rectangle r1 = {10, 5};
    cout << area(r1) << endl;
    cout << area2(r1) << endl;
    Rectangle *r2 = &r1;
    cout << r2->length << endl;
    changeLength(r2);
    cout << r2->length << endl;

    Test t = {{1, 2, 3, 4, 5}, 5};
    // fun(t);
    fun2(&t);
    for (int i = 0; i < t.n; i++)
    {
        cout << t.A[i] << " ";
    }
    cout << endl;

    return 0;
}