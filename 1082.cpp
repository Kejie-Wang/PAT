#include <iostream>
#include <string>

using namespace std;

string ToChinese(string s)
{
    string chinese[20]{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    s = string(4 - s.size(), '0') + s;
    string res;

    if (s[0] != '0')
    {
        res += (chinese[s[0] - '0']) + " Qian";
        if (s.substr(1, 3) != "000")
        {
            if (s.substr(1, 1) == "0")
                res += " ling";
            res += (" " + ToChinese(s.substr(1, 3)));
        }
    }
    else if (s[1] != '0')
    {
        res += (chinese[s[1] - '0']) + " Bai";
        if (s.substr(2, 2) != "00")
        {
            if (s.substr(2, 1) == "0")
                res += " ling";
            res += (" " + ToChinese(s.substr(2, 2)));
        }
    }
    else if (s[2] != '0')
    {
        res += (chinese[s[2] - '0']) + " Shi";
        if (s.substr(3, 1) != "0")
            res += (" " + ToChinese(s.substr(3, 1)));
    }
    else
        res += chinese[s[3] - '0'];
    
    return res;
}

int main()
{
    string s;
    cin >> s;
    if (s[0] == '-')
    {
        cout << "Fu" << " ";
        s.erase(s.begin());
    }
    if (s.size() > 8)
    {
        cout << ToChinese(s.substr(0, s.size() - 8)) << " Yi";
        s = s.substr(s.size() - 8, 8);
        if (s != "00000000")
            cout << " ";
        else
            return 0;
        if (s[0] == '0')
            cout << "ling ";
    }
    if (s.size() > 4)
    {
        cout << ToChinese(s.substr(0, s.size() - 4)) << " Wan";
        s = s.substr(s.size() - 4, 4);
        if (s != "0000")
            cout << " ";
        else
            return 0;
        if (s[0] == '0')
            cout << "ling ";
    }
    cout << ToChinese(s);
}