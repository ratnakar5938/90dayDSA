#include <iostream>

using namespace std;

int find_length(string *s)
{
    int length = 0;
    while ((*s)[length] != '\0')
        length++;
    return length;
}

int main()
{
    string s = "ratnakar";

    cout << "Length is : " << find_length(&s) << endl;
    return 0;
}