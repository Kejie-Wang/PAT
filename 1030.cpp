#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
struct Node
{
    int minLength = INF;
    bool visited = false;
    int pre;
    int cost;
};

struct Way
{
    int length = INF;
    int cost = INF;
};

Node nodes[500];
Way cityMap[500][500];

int main()
{
    int cityNum, wayNum, start, end;
    cin >> cityNum >> wayNum >> start >> end;

    for (int i = 0; i < wayNum; i++)
    {
        int c1, c2, dst, cost;
        cin >> c1 >> c2 >> dst >> cost;
        cityMap[c1][c2].length = cityMap[c2][c1].length = dst;
        cityMap[c1][c2].cost = cityMap[c2][c1].cost = cost;
    }

    //using dijkstra algorithm
    nodes[start].minLength = 0;
    nodes[start].visited = true;
    nodes[start].cost = 0;
    int min = start;
    while (1)
    {
        for (int i = 0; i < cityNum; i++)
        {
            //update the nodes information
            if (cityMap[min][i].length < INF && !nodes[i].visited)
            {
                if (nodes[min].minLength + cityMap[min][i].length < nodes[i].minLength)
                {
                    nodes[i].minLength = nodes[min].minLength + cityMap[min][i].length;
                    nodes[i].pre = min;
                    nodes[i].cost = nodes[min].cost + cityMap[min][i].cost;
                }
                else if (nodes[min].minLength + cityMap[min][i].length == nodes[i].minLength)
                {
                    if (nodes[min].cost + cityMap[min][i].cost < nodes[i].cost)
                    {
                        nodes[i].pre = min;
                        nodes[i].cost = nodes[min].cost + cityMap[min][i].cost;
                    }
                }
            }
        }

        //find the next minimum nodes
        int minLength = INF;
        for (int i = 0; i < cityNum; i++)
        {
            if (!nodes[i].visited && minLength > nodes[i].minLength)
            {
                minLength = nodes[i].minLength;
                min = i;
            }
        }
        if (minLength == INF)
            break;
        nodes[min].visited = true;
    }

    int totalCost = 0, totalDst = 0;
    vector<int> vec;
    int i = end;
    vec.push_back(end);
    while (1)
    {
        int pre = nodes[i].pre;
        totalCost += cityMap[pre][i].cost;
        totalDst += cityMap[pre][i].length;
        i = pre;
        vec.push_back(i);
        if (i == start)
            break;
    }
    for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << " ";
    cout << totalDst << " " << totalCost;
}