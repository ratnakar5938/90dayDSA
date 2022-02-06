#include <iostream>

using namespace std;

void foo(int n, int sum)
{
    int k = 0, j = 0;
    if (n == 0)
        return;
    k = n % 10;
    j = n / 10;
    sum += k;
    foo(j, sum);
    cout << k << " ";
}

int main()
{
    // find the output
    int a = 2048, sum = 0;
    foo(a, sum);
    cout << endl;
    cout << sum << endl;

    return 0;
}

// logical process ->
// foo(2048, 0) -> k = 8, j = 204, sum = 8, foo(204, 8)
// foo(204, 8) -> k = 4, j = 20, sum = 12, foo(20, 12)
// foo(20, 12) -> k = 0, j = 2, sum = 12, foo(2, 12)
// foo(2, 12) -> k = 2, j = 0, sum = 14, foo(0, 14) ->return
//  O/p -> 2 0 4 8
//         0