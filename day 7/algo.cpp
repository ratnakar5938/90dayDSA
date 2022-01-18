#include <iostream>

using namespace std;

// Algorithm for finding the largest number among three numbers
// Step 1: Start
// Step 2: Declare variables a,b and c.
// Step 3: Read variables a,b and c.
// Step 4: If a > b
//            If a > c
//               Display a is the largest number.
//            Else
//               Display c is the largest number.
//         Else
//            If b > c
//               Display b is the largest number.
//            Else
//               Display c is the greatest number.
// Step 5: Stop

int largestAmongThree(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
            return a;
        else
            return c;
    }
    else
    {
        if (b > c)
            return b;
        else
            return c;
    }
}

int main()
{
    int a, b, c;
    cout << "Enter the three numbers to compare : ";
    cin >> a >> b >> c;
    cout << "Largest Among Three : " << largestAmongThree(a, b, c) << endl;

    return 0;
}