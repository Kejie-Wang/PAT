#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;
int Map[1010][1010];
bitset<1010> visited;
int minLength[10][1010];
int houseNum, stationNum, roadNum, range;

int ToInt(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 10 + s[i] - '0';
    return res;
}

int HashIndex(string p)
{
    if (p[0] == 'G')
        return ToInt(string(p.begin() + 1, p.end())) - 1;
    else
        return ToInt(p) - 1 + stationNum;
}

int main()
{
    cin >> houseNum >> stationNum >> roadNum >> range;
    for (int i = 0; i < stationNum + houseNum; i++)
        for (int j = 0; j < stationNum + houseNum; j++)
            Map[i][j] = INF;
    for (int i = 0; i < roadNum; i++)
    {
        string p1, p2;
        int dist;
        cin >> p1 >> p2 >> dist;
        int index1 = HashIndex(p1), index2 = HashIndex(p2);
        Map[index1][index2] = Map[index2][index1] = dist;
    }
    //initial the minLength to INF
    for (int i = 0; i < stationNum; i++)
        for (int j = 0; j < stationNum + houseNum; j++)
            minLength[i][j] = INF;
    for (int i = 0; i < stationNum; i++)
    {
        int start = i;
        visited.reset();
        //using dijkstra algorithm
        //initial the start
        minLength[start][start] = 0;
        visited.set(start);
        int min = start;
        while (1)
        {
            for (int i = 0; i < stationNum + houseNum; i++)
            {
                if (Map[min][i] < INF && minLength[start][min] + Map[min][i] < minLength[start][i])
                    minLength[start][i] = minLength[start][min] + Map[min][i];
            }
            int length = INF;
            for (int i = 0; i < stationNum + houseNum; i++)
            {
                if (!visited[i] && minLength[start][i] < length)
                {
                    length = minLength[start][i];
                    min = i;
                }
            }
            visited.set(min);
            if (length == INF)
                break;
        }
    }

    int min[11], max[11], sum[11];
    for (int i = 0; i < stationNum; i++)
    {
        min[i] = *min_element(minLength[i] + stationNum, minLength[i] + stationNum + houseNum);
        max[i] = *max_element(minLength[i] + stationNum, minLength[i] + stationNum + houseNum);
        sum[i] = 0;
        for (int j = stationNum; j < houseNum + stationNum; j++)
            sum[i] += minLength[i][j];
    }
    double maxDist = -INF, minSum;
    int maxIndex;
    for (int i = 0; i < stationNum; i++)
    {
        if (max[i] <= range)
        {
            if (min[i] > maxDist)
            {
                maxDist = min[i];
                maxIndex = i;
                minSum = sum[i];
            }
            else if (min[i] == maxDist)
            {
                if (sum[i] < minSum)
                {
                    minSum = sum[i];
                    maxIndex = i;
                }
            }
        }
    }
    
    if (maxDist == -INF)
        cout << "No Solution";
    else
    {
        cout << "G" << maxIndex + 1 << endl;
        printf("%.1f %.1f", maxDist, minSum / houseNum);
        //cout << hex << setprecision(1) << 1.0*maxDist << " " << 1.0*minSum / houseNum;
    }

}