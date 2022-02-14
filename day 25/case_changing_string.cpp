#include <iostream>

using namespace std;

void change_case(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
        else if (s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
}

int main()
{
    char s[] = "Ravi-555-Devil";
    cout << s << endl;
    change_case(s);
    cout << s << endl;

    return 0;
}