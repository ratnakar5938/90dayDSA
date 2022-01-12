#include <iostream>

using namespace std;
int main()
{
    int A[5];                   // declaration
    A[0] = 22;                  // initialization
    int B[] = {2, 4, 5, 6, 10}; // declaration and initialization
    for (int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}