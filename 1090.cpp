#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node
{
    vector<int> vec;
    int level;
};

Node distributor[100000];
double p, r;
int maxLevel = 0;
int cnt = 0;

void SetLevel(int root)
{
    if (distributor[root].vec.empty())
    {
        if (distributor[root].level > maxLevel)
        {
            maxLevel = distributor[root].level;
            cnt = 1;
        }
        else if (distributor[root].level == maxLevel)
            cnt++;
    }
    for (int i = 0; i < distributor[root].vec.size(); i++)
    {
        int child = distributor[root].vec[i];
        distributor[child].level = distributor[root].level + 1;
        SetLevel(child);
    }
}

int main()
{
    int n, root;
    cin >> n >> p >> r;
    for (int i = 0; i < n; i++)
    {
        int supplier;
        cin >> supplier;
        if (supplier == -1)
            root = i;
        else
            distributor[supplier].vec.push_back(i);
    }    
    distributor[root].level = 0;
    SetLevel(root);

    cout << fixed << setprecision(2) << p*pow(1 + r*1.0 / 100, maxLevel) << " " << cnt;
}