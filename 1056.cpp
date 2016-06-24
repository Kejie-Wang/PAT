#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Programmer
{
    int index;
    int weight;
    int turn = 1;
    int rank;
};

bool cmp1(const Programmer& prog1, const Programmer& prog2)
{
    return prog1.turn > prog2.turn;
}

bool cmp2(const Programmer& prog1, const Programmer& prog2)
{
    return prog1.index < prog2.index;
}

int main()
{
    int NP, NG;
    cin >> NP >> NG;
    Programmer* prog = new Programmer[NP];
    for (int i = 0; i < NP; i++)
    {
        prog[i].index = i;
        cin >> prog[i].weight;
    }
    queue<int> order;
    for (int i = 0; i < NP; i++)
    {
        int index;
        cin >> index;
        order.push(index);
    }

    int turn = 1;
    while (order.size() != 1)
    {
        vector<int> vec;
        while(vec.size() < NG && !order.empty())
        {
            int index = order.front();
            if (prog[index].turn == turn)
            {
                vec.push_back(index);
                order.pop();
            }
            else
                break;
        }
        if (!vec.empty())
        {
            int max = vec[0];
            for (int j = 1; j < vec.size(); j++)
                if (prog[vec[j]].weight > prog[max].weight)
                    max = vec[j];
            prog[max].turn++;
            order.push(max);
        }
        if (prog[order.front()].turn != turn)
            turn++;
    }

    sort(prog, prog + NP, cmp1);
    int lastRank = 1;
    for (int i = 0; i < NP; i++)
    {
        if (prog[i].turn == turn)
            prog[i].rank = lastRank;
        else
        {
            prog[i].rank = i + 1;
            turn = prog[i].turn;
            lastRank = i + 1;
        }
    }
    
    sort(prog, prog + NP, cmp2);
    for (int i = 0; i < NP - 1; i++)
        cout << prog[i].rank << " ";
    cout << prog[NP - 1].rank;
}