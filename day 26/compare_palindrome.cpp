#include <iostream>

using namespace std;

int isSame(char *s1, char *s2)
{
    int i = 0;
    bool b = true;
    for (; s1[i] != '\0' || s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
        {
            b = false;
            break;
        }
    if (b)
        return 0;
    else
    {
        if (s1[i] > s2[i])
            return 1;
        else
            return 2;
    }
}

bool isPalindrome(char *s)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
        i++;
    for (i = i - 1; i > j; i--, j++)
        if (s[i] != s[j])
            return false;
    return true;
}

int main()
{
    char s[] = "painter";
    char t[] = "painting";
    cout << s << endl;
    cout << t << endl;
    if (isSame(s, t) == 0)
        cout << "Both are same" << endl;
    else if (isSame(s, t) == 1)
        cout << s << " is greater than " << t << endl;
    else
        cout << t << " is greater than " << s << endl;

    char pal[] = "madam";
    if (isPalindrome(pal))
        cout << pal << " is a palindrome" << endl;
    else
        cout << pal << " is not a palindrome" << endl;

    return 0;
}