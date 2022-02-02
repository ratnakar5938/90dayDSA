#include <iostream>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    int a = 3;
    fun(a);

    return 0;
}

// calling stack
//                                fun(3)
//                               /  |   \ 
//                              /   |    \ 
//                             3   f(2)   f(2) -> SAME AS f(2) but starts executing after the previous f(2)
//                               /  |  \   
//                              /   |   \ 
//                             2  f(1)   f(1) -> SAME AS f(1) but starts executing after the previous f(1)
//                                / | \ 
//                               /  |  \ 
//                              1  f(0) f(0)

// total calls => 15
// series => 1+2+4+8 = 15
// generalisation => 2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1) - 1
// time complexity => O(2^n)
// space complexity => O(n)