#include <iostream>
#include <set>

using namespace std;

set<int> WrongIndex;
int sequence[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sequence[i] = num;
        if (num != i)
            WrongIndex.insert(i);
    }
    int totalNum = WrongIndex.size();
    int cycle = 0;
    while (!WrongIndex.empty())
    {
        int initial = *(WrongIndex.begin());
        int next = sequence[initial];
        WrongIndex.erase(initial);
        while (next != initial)
        {
            WrongIndex.erase(next);
            next = sequence[next];
        }
        cycle++;
    }
    if (totalNum == 0)
        cout << 0;
    else if (sequence[0] != 0)
        cout << totalNum + cycle - 2;
    else
        cout << totalNum + cycle;
}