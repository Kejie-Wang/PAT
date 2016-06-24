#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int parent  = -1;
    int weight;
    vector<int> child;
};

Node tree[100];
int weight[100];


void CalculateWeight(int root)
{
    vector<int>& vec = tree[root].child;

    for (int i = 0; i < vec.size(); i++)
    {
        tree[vec[i]].weight = tree[root].weight + weight[vec[i]];
        CalculateWeight(vec[i]);
    }
}

bool cmp(vector<int> v1, vector<int> v2)
{
    int i = 0;
    while (i < v1.size() && i < v2.size())
    {
        if (v1[i] != v2[i])
            return v1[i] > v2[i];
        i++;
    }
    return false;
}

int main()
{
    int nodeNum, nonLeafNum, givenWeight;
    cin >> nodeNum >> nonLeafNum >> givenWeight;

    for (int i = 0; i < nodeNum; i++)
        cin >> weight[i];
    for (int i = 0; i < nonLeafNum; i++)
    {
        int parent, childNum;
        cin >> parent >> childNum;
        for (int i = 0; i < childNum; i++)
        {
            int child;
            cin >> child;
            tree[parent].child.push_back(child);
            tree[child].parent = parent;
        }
    }

    tree[0].weight = weight[0];
    CalculateWeight(0);

    vector< vector<int> > seq;
    for (int i = 0; i < nodeNum; i++)
    {
        if (tree[i].child.empty() && tree[i].weight == givenWeight)
        {
            vector<int> vec;
            int j = i;
            while (j != -1)
            {
                vec.push_back(weight[j]);
                j = tree[j].parent;
            }
            seq.push_back(vector<int>(vec.rbegin(), vec.rend()));
        }
    }
    sort(seq.begin(), seq.end(), cmp);
    for (int i = 0; i < seq.size(); i++)
    {
        vector<int>& vec = seq[i];
        for (int j = 0; j < vec.size() - 1; j++)
            cout << vec[j] << " ";
        cout << vec.back() << endl;
    }
}