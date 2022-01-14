#include <iostream>

using namespace std;

class Rectangle
{
    int length;
    int width;

public:
    Rectangle(int, int);
    // void setData(int, int);
    void getData();
    int getArea();
    void changeLength(int);
};

Rectangle::Rectangle(int l, int w)
{
    length = l;
    width = w;
}

// void Rectangle::setData(int l, int w)
// {
//     length = l;
//     width = w;
// }

void Rectangle::getData()
{
    cout << "Length : " << length << endl;
    cout << "Width : " << width << endl;
}

int Rectangle::getArea()
{
    int area = length * width;
    return area;
}

void Rectangle::changeLength(int cl)
{
    length += cl;
}

int main()
{
    Rectangle r1(10, 5);
    // r1.setData(10, 5);
    r1.getData();
    cout << "Area : " << r1.getArea() << endl;
    r1.changeLength(2);
    r1.getData();

    return 0;
}