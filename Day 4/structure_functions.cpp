#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int width;
    void getData();
};

void Rectangle::getData()
{
    cout << "Length of the rectangle : " << length << endl;
    cout << "Width of the rectangle : " << width << endl;
}

void initialize(Rectangle *r, int l, int w)
{
    r->length = l;
    r->width = w;
}

void area(Rectangle r)
{
    cout << "Area of the rectangle : " << (r.length * r.width) << endl;
}

void changeLength(Rectangle *r, int l)
{
    r->length += l;
}

int main()
{
    Rectangle r1;
    initialize(&r1, 10, 5);
    r1.getData();
    area(r1);
    changeLength(&r1, 2);
    r1.getData();

    return 0;
}