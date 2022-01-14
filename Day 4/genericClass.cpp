#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T a, b;

public:
    Arithmetic(T, T);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    T c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::sub()
{
    T c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> a1(5, 2);
    cout << a1.add() << endl;
    cout << a1.sub() << endl;

    Arithmetic<float> a2(5.4, 2.5);
    cout << a2.add() << endl;
    cout << a2.sub() << endl;

    return 0;
}