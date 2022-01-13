#include <iostream>

using namespace std;

void func1()
{
    cout << "Hello there" << endl;
}

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
    func1();
    func1();

    cout << add(3, 5) << endl;

    return 0;
}