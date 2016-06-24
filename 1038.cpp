#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2)
{
    return s1 + s2 < s2 + s1;
}

int main()
{
    int segNum;
    vector<string> segment;
    cin >> segNum;
    for (int i = 0; i < segNum; i++)
    {
        string seg;
        cin >> seg;
        segment.push_back(seg);
    }
    sort(segment.begin(), segment.end(), cmp);
    string res;
    for (int i = 0; i < segment.size(); i++)
        res += segment[i];

    string::iterator it = res.begin();
    while (*it == '0')
        it = res.erase(it);

    if (res.empty())
        cout << "0";
    else
        cout << res;
}