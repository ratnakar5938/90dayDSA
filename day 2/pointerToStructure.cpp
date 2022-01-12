#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int width;
    int area();
};

int Rectangle::area()
{
    int totalArea = length * width;
    return totalArea;
}

int main()
{
    Rectangle r = {10, 5}; // assigning in stack memory
    Rectangle *p = &r;
    p->length = 20;
    Rectangle *q = new Rectangle(); // assigning in heap memory
    q->length = 25;
    q->width = 5;
    cout << "Area of rectangle q : " << q->area() << endl;

    return 0;
}