#include <iostream>

using namespace std;

class Rectangle
{
    int length;
    int width;

public:
    Rectangle()
    {
        length = 1;
        width = 1;
    }
    Rectangle(int, int);
    int getArea();
    int getParameter();
    int getLength() { return length; }
    int getWidth() { return width; }
    void setLength(int l) { length = l; }
    void setWidth(int w) { width = w; }
    ~Rectangle();
};

Rectangle::Rectangle(int l, int w)
{
    length = l;
    width = w;
}

int Rectangle::getArea()
{
    return length * width;
}

int Rectangle::getParameter()
{
    return 2 * (length + width);
}

Rectangle::~Rectangle() {}

int main()
{
    Rectangle r(10, 5);
    cout << r.getArea() << endl;
    cout << r.getParameter() << endl;

    return 0;
}