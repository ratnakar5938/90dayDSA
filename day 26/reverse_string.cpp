#include <iostream>

using namespace std;

char *reverse(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;

    char *s2;
    s2 = new char[i + 1];
    s2[i] = '\0';
    i--;
    int j = 0;

    for (; i >= 0; i--, j++)
        s2[j] = s[i];

    return s2;
}

template <class T>
void swap(T *a, T *b)
{
    T temp = &a;
    &a = &b;
    &b = temp;
}

void reverse2(char *s)
{
    int i = 0, j = 0;
    while (s[i] != '\0')
        i++;
    for (i = i - 1; i > j; i--, j++)
        swap(s[i], s[j]);
}

int main()
{
    char lang[] = "python is easy";
    cout << lang << endl;

    // method 1
    // char *lang2 = reverse(lang);
    // cout << lang2 << endl;

    // method 2
    reverse2(lang);
    cout << lang << endl;

    return 0;
}