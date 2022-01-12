#include <iostream>

using namespace std;

// example 1
class Rectangle
{
public:
    int length = 0, width = 0;
    int area();
};

int Rectangle::area()
{
    int area = length * width;
    return area;
}

//  ____________
// |            |
// |            | width
// |            |
//  ------------
//     length

// Example 2
class Complex
{
public:
    int real;
    int imaginary;
};

// Example 3
class Student
{
public:
    int roll;
    string name;
    string dept;
    string address;
};

// Example 4
class Card
{
public:
    int face;
    int shape;
    int color;
};

int main()
{
    Rectangle r;
    r.length = 12;
    r.width = 6;

    cout << "Area of rectangle is : " << r.area() << endl;

    return 0;
}