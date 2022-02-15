#include <iostream>

using namespace std;

void duplicte(char *s)
{
    int *hash = new int[26]{0};
    for (int i = 0; s[i] != '\0'; i++)
        hash[s[i] - 97]++;
    for (int i = 0; i < 26; i++)
        if (hash[i] > 1)
            cout << (char)(i + 97) << " has " << hash[i] << " duplicates" << endl;
}
// time complexity -> O(n)

int main()
{
    char A[] = "finding";
    duplicte(A);
    return 0;
}