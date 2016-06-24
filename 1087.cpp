#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

const int INF = 0x7fffffff;
map<string, int> indexMap;
vector<string> city;
int happiness[200];
int cityMap[200][200];
int maxHappiness[200];
int minCost[200];
int cityPast[200];
int minCostRoute[200];
bitset<200> visited;
int pre[200];

int main()
{
    int cityNum, routeNum;
    cin >> cityNum >> routeNum;
    string start;
    cin >> start;
    indexMap[start] = 0;
    city.push_back(start);
    for (int i = 1; i < cityNum; i++)
    {
        string c;
        cin >> c >> happiness[i];
        indexMap[c] = i;
        city.push_back(c);
    }

    for (int i = 0; i < cityNum; i++)    //initial the city map
        for (int j = 0; j < cityNum; j++)
            cityMap[i][j] = cityMap[j][i] = INF;
    for (int i = 0; i < routeNum; i++)
    {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        int index1 = indexMap[c1];
        int index2 = indexMap[c2];
        cityMap[index1][index2] = cityMap[index2][index1] = cost;
    }
    
    for (int i = 0; i < cityNum; i++)
    {
        maxHappiness[i] = 0;
        minCost[i] = INF;
    }

    //using dijkstra algorithm
    visited.set(0);
    int min = 0;
    maxHappiness[0] = 0;
    minCost[0] = 0;
    cityPast[0] = 0;
    minCostRoute[0] = 1;
    while (1)
    {
        for (int i = 0; i < cityNum; i++)
        {
            if (cityMap[min][i] < INF)
            {
                if (minCost[min] + cityMap[min][i] < minCost[i])
                {
                    pre[i] = min;
                    minCost[i] = minCost[min] + cityMap[min][i];
                    maxHappiness[i] = maxHappiness[min] + happiness[i];
                    cityPast[i] = cityPast[min] + 1;
                    minCostRoute[i] = minCostRoute[min];
                }
                else if (minCost[min] + cityMap[min][i] == minCost[i])
                {
                    minCostRoute[i] += minCostRoute[min];
                    if (maxHappiness[min] + happiness[i] > maxHappiness[i])
                    {
                        pre[i] = min;
                        maxHappiness[i] = maxHappiness[min] + happiness[i];
                        cityPast[i] = cityPast[min] + 1;
                    }
                    else if (maxHappiness[min] + happiness[i] == maxHappiness[i])
                    {
                        if (cityPast[min] + 1 < cityPast[i])
                        {
                            pre[i] = min;
                            cityPast[i] = cityPast[min] + 1;
                        }
                    }
                }
            }
        }

        int cost = INF;
        for (int j = 0; j < cityNum; j++)
        {
            if (!visited[j] && cost > minCost[j])
            {
                cost = minCost[j];
                min = j;
            }
        }
        visited.set(min);
        if (cost==INF)
            break;
    }

    int ROMIndex = indexMap["ROM"];
    cout << minCostRoute[ROMIndex] << " " << minCost[ROMIndex] << " " << maxHappiness[ROMIndex] << " "
        << maxHappiness[ROMIndex] / cityPast[ROMIndex] << endl;
    vector<string> vec;
    for (int i = ROMIndex; i != 0; i = pre[i])
        vec.push_back(city[i]);
    vec.push_back(start);
    for (vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend()-1; it++)
        cout << *it << "->";
    cout << vec.front();
}