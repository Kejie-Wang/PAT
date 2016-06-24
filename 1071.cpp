#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string speech;
    getline(cin, speech);

    map<string, int> count;
    int i = 0;
    string word;
    while (i < speech.size())
    {
        char ch = speech[i];
        if (isalpha(ch) || isalnum(ch))
        {
            if (isupper(ch))
                ch = tolower(ch);
            word.insert(word.end(), ch);
        }
        else if (!word.empty())
        {
            if (count.find(word) == count.end())
                count[word] = 1;
            else
                count[word]++;
            word.clear();
        }
        i++;
    }
    if(!word.empty())
    {
        if (count.find(word) == count.end())
            count[word] = 1;
        else
            count[word]++;
    }

    map<string, int>::iterator it = count.begin();
    string maxword = it->first;
    int maxcount = 0;
    while (it != count.end())
    {
        string word = it->first;
        int cnt = it->second;
        if (cnt > maxcount||(cnt==maxcount&&word < maxword))
        {
            maxcount = cnt;
            maxword = word;
        }
        it++;
    }

    cout << maxword << " " << maxcount;
}