#include <iostream>

using namespace std;

bool isValid(char *s)
{
    bool valid = true;
    for (int i = 0; s[i] != '\0'; i++)
        if (!((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)))
        {
            valid = false;
            break;
        }
    return valid;
}

int main()
{
    char name[] = "Anil$321";
    if (isValid(name))
        cout << "String is valid string" << endl;
    else
        cout << "String is not valid string" << endl;

    return 0;
}