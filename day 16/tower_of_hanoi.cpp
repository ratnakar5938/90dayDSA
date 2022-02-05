#include <iostream>

using namespace std;
// We have to transfer all the discs from A to C towers and one extra tower B is given for using
// Condition 1 : Only one disc can be moved at a time
// Condition 2 : No bigger disc can be put above a smaller disc

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "From " << A << " to " << C << endl;
        TOH(n - 1, B, A, C);
    }
    return;
}
// time complexity -> O(2^n)

int main()
{
    TOH(4, 'A', 'B', 'C');

    return 0;
}