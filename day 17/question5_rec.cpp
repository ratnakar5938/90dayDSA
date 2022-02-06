#include <iostream>

using namespace std;

void count(int n)
{
    static int d = 1;
    cout << n << " " << d << endl;
    d++;
    if (n > 1)
        count(n - 1);
    cout << d << endl;
}

int main()
{

    // find the output
    count(3);
    return 0;
}

// logical process ->
// c(3) -> d = 1 -> o/p => 3 1 -> d = 2 -> c(2) -> o/p => 2 2 -> d = 3 -> c(1) -> o/p => 3 1 -> d = 4 -> o/p => 4 4 4