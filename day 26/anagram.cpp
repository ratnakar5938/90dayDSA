#include <iostream>

using namespace std;

bool anagram(char *A, char *B)
{
    int *C = new int[26]{0};
    for (int i = 0; A[i] != '\0'; i++)
        C[A[i] - 97]++;
    for (int i = 0; B[i] != '\0'; i++)
        C[B[i] - 97]--;
    for (int i = 0; i < 26; i++)
        if (C[i] != 0)
            return false;
    return true;
}
// time complexity -> O(n + n + n) -> O(n)
// assumption -> all characters are lower case alphabets
//            -> both strings are of same size

int main()
{
    char A[] = "verbose";
    char B[] = "observe";
    if (anagram(A, B))
        cout << A << " and " << B << " are anagram" << endl;
    else
        cout << A << " and " << B << " are not anagram" << endl;

    return 0;
}