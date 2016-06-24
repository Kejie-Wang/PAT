#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Gang
{
    int clusterNum = 0;
    int time=0;
};

int HashIndex(string name)
{
    return (name[0] - 'A') * 26 * 26 + \
        (name[1] - 'A') * 26 + \
        (name[2] - 'A');
}

string ReverseHash(int index)
{
    int digit1, digit2, digit3;
    digit3 = index % 26;
    digit2 = (index / 26) % 26;
    digit1 = (index / 26 / 26) % 26;
    return string(1, digit1 + 'A') + \
        string(1, digit2 + 'A') + \
        string(1, digit3 + 'A');
}

Gang GangRecord[26 * 26 * 26];
vector<string> vec[26 * 26 * 26];
int totaltime[26 * 26 * 26];
int maxtime[26 * 26 * 26];
string maxname[26 * 26 * 26];

int main()
{
    int RecordNum, threshold;
    cin >> RecordNum >> threshold;
    int ClusterNum = 0;

    for (int i = 0; i < RecordNum; i++)
    {
        string name1, name2;
        int time;
        cin >> name1 >> name2 >> time;
        int index1 = HashIndex(name1);
        int index2 = HashIndex(name2);
        if (GangRecord[index1].clusterNum == 0 && GangRecord[index2].clusterNum == 0)
        {
            ClusterNum++;
            vec[ClusterNum].push_back(name1);
            vec[ClusterNum].push_back(name2);
            totaltime[ClusterNum] = time;
            GangRecord[index1].clusterNum = ClusterNum;
            GangRecord[index1].time = time;
            GangRecord[index2].clusterNum = ClusterNum;
            GangRecord[index2].time = time;
        }
        else if (GangRecord[index1].clusterNum != 0 && GangRecord[index2].clusterNum != 0)
        {
            GangRecord[index1].time += time;
            GangRecord[index2].time += time;
            totaltime[GangRecord[index1].clusterNum] += time;
            if (GangRecord[index1].clusterNum != GangRecord[index2].clusterNum)
            {
                int clusterNum1 = GangRecord[index1].clusterNum;
                int clusterNum2 = GangRecord[index2].clusterNum;
                for (int i = 0; i < vec[clusterNum2].size(); i++)
                {
                    string name = vec[clusterNum2][i];
                    GangRecord[HashIndex(name)].clusterNum = GangRecord[index1].clusterNum;
                }
                vec[clusterNum1].insert(vec[clusterNum1].end(), vec[clusterNum2].begin(), vec[clusterNum2].end());
                vec[clusterNum2].clear();
                totaltime[clusterNum1] += totaltime[clusterNum2];
                totaltime[clusterNum2] = 0;
            }
        }
        else if (GangRecord[index1].clusterNum != 0)
        {
            vec[GangRecord[index1].clusterNum].push_back(name2);
            totaltime[GangRecord[index1].clusterNum] += time;
            GangRecord[index1].time += time;
            GangRecord[index2].clusterNum = GangRecord[index1].clusterNum;
            GangRecord[index2].time = time;
        }
        else
        {
            vec[GangRecord[index2].clusterNum].push_back(name1);
            totaltime[GangRecord[index2].clusterNum] += time;
            GangRecord[index2].time += time;
            GangRecord[index1].clusterNum = GangRecord[index2].clusterNum;
            GangRecord[index1].time = time;
        }
    }

    for (int i = 0; i < 26 * 26 * 26; i++)
    {
        int clusterNum = GangRecord[i].clusterNum;
        if (clusterNum != 0)
        {
            if (GangRecord[i].time > maxtime[clusterNum])
            {
                maxtime[clusterNum] = GangRecord[i].time;
                maxname[clusterNum] = ReverseHash(i);
            }
        }
    }
    int GangNum = 0;
    for (int index = 1; index <= ClusterNum; index++)
    {
        if (vec[index].size() > 2 && totaltime[index] > threshold)
            GangNum++;
    }
    cout << GangNum << endl;
    
    sort(maxname+1, maxname+ClusterNum+1);
    for (int i = 1; i <= ClusterNum; i++)
    {
        string name = maxname[i];
        if (name.empty())
            continue;
        int index = GangRecord[HashIndex(name)].clusterNum;

        if (vec[index].size() > 2 && totaltime[index] > threshold)
            cout << name << " " << vec[index].size() << endl;
    }
}