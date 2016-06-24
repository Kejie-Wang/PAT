#include <cstdio>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set<int> s[51];

int main()
{
    int setNum;
    //cin >> setNum;
    scanf("%d", &setNum);
    for (int i = 1; i <= setNum; i++)
    {
        int keyNum;
        scanf("%d", &keyNum);
        //cin >> keyNum;
        for (int j = 0; j < keyNum; j++)
        {
            int key;
            scanf("%d", &key);
            s[i].insert(key);
        }
    }
    int queryNum;
    scanf("%d", &queryNum);
    //cin >> queryNum;
    for (int i = 0; i < queryNum; i++)
    {
        int index1, index2;
        scanf("%d%d", &index1, &index2);
        int NC = 0;
        set<int>::iterator it1, it2;
        it1 = s[index1].begin();
        it2 = s[index2].begin();
        while (it1 != s[index1].end() && it2 != s[index2].end())
        {
            if (*it1 == *it2)
            {
                it1++; it2++; NC++;
            }
            else if (*it1 < *it2)
                it1++;
            else
                it2++;
        }
        int NP = s[index1].size() + s[index2].size() - NC;
        
        printf("%.1f%%\n", NC*100.0 / NP);
    }
}