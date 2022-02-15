#include <iostream>

using namespace std;

void duplicate(char *s)
{
    int *hash = new int[26]{0};
    for (int i = 0; s[i] != '\0'; i++)
        hash[s[i] - 97]++;
    for (int i = 0; i < 26; i++)
        if (hash[i] > 1)
            cout << (char)(i + 97) << " has " << hash[i] << " duplicates" << endl;
}
// time complexity -> O(n)

void duplicate2(char *s)
{
    long int H = 0, X = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        X = 1;
        X = X << (s[i] - 97);
        if (X & H > 0)
            cout << s[i] << " has duplicates" << endl;
        else
            H = X | H;
    }
}

int main()
{
    char A[] = "finding";
    // duplicate(A);
    // duplicate2(A);
    long int H = 0, X = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        X = 1;
        X = X << (A[i] - 97);
        if ((X & H) > 0)
            cout << A[i] << " has duplicates" << endl;
        else
            H = X | H;
    }
    return 0;
}