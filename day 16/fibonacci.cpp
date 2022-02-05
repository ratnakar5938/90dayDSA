#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// time complexity -> calls n-1 2 times -> O(2^n)
// this fibonacci function calls itself multiple times for the same value that is y it is called excessive recursion

int fibonacci_improved(int n)
{
    static vector<int> s(n + 1, -1);
    if (n <= 1)
    {
        if (s[n] == -1)
        {
            s[n] = n;
        }
        return s[n];
    }
    if (s[n] == -1)
    {
        s[n] = fibonacci_improved(n - 1) + fibonacci_improved(n - 2);
    }
    return s[n];
}
// time complexity -> O(n)
// this approach of storing the values to be used later is called memoization

int fibonacci_iter(int n)
{
    int t_0 = 0, t_1 = 1, s;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = t_0 + t_1;
        t_0 = t_1;
        t_1 = s;
    }
    return s;
}
// time complexity -> O(n)

int main()
{
    int a;
    cout << "Enter the index : ";
    cin >> a;
    cout << fibonacci(a) << endl;
    cout << fibonacci_iter(a) << endl;
    cout << fibonacci_improved(a) << endl;

    return 0;
}