#include <iostream>
#include <utility>

using namespace std;

pair<int, int> vowel_n_consonant_count(char *s)
{
    pair<int, int> count;
    count.first = 0, count.second = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            count.first++;
        else if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            count.second++;
    return count;
}
int word_count(char *s)
{
    int total = 1;
    int i = 0;
    while (s[i++] != '\0')
        if (s[i] == ' ')
            if (s[i - 1] != ' ')
                total++;
    return total;
}

int main()
{
    char s[] = "How are   you";
    pair<int, int> count = vowel_n_consonant_count(s);
    cout << "Total number of vowels : " << count.first << endl;
    cout << "Total number of consonants : " << count.second << endl;
    cout << "Total number of words : " << word_count(s) << endl;
    return 0;
}