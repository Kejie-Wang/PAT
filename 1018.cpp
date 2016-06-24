#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
struct Station
{
	int bikeNum;
	int minTime = INF;
	vector<int> pre;
	bool visited = false;
};
struct Path
{
	vector<int> path;
	int from;
	int back;
	Path(vector<int> path){ this->path = path; Update(); }
	void Update();
};

int stationMap[501][501];
Station stations[501];
vector<Path> paths;
int half;

void FindPath(int destination, vector<int> path)
{
	path.push_back(destination);
	if (destination == 0)
		paths.push_back(Path(vector<int>(path.rbegin(), path.rend())));
	for (int i = 0; i < stations[destination].pre.size(); i++)
		FindPath(stations[destination].pre[i], path);
}

void Path::Update()
{
	from = 0;
	back = 0;
	for (int i = 1; i < path.size(); i++)
	{
		int s = path[i];
		if (stations[s].bikeNum >= half)
			back += (stations[s].bikeNum - half);
		else if (back >= half - stations[s].bikeNum)
			back -= (half - stations[s].bikeNum);
		else
		{
			from += (half - stations[s].bikeNum - back);
			back = 0;
		}
	}
}

int main()
{
	int max, stationNum, destination, roadsNum;
	cin >> max >> stationNum >> destination >> roadsNum;
	half = max / 2;
	for (int i = 1; i <= stationNum; i++)
		cin >> stations[i].bikeNum;
	//initialize the station map
	for (int i = 0; i < 501; i++)
		for (int j = 0; j < 501; j++)
			stationMap[i][j] = stationMap[j][i] = INF;
	for (int i = 0; i < roadsNum; i++)
	{
		int s1, s2, time;
		cin >> s1 >> s2 >> time;
		stationMap[s1][s2] = stationMap[s2][s1] = time;
	}

	//using dijkstra algorithm to get the minimum time path
	//initialize
	int min = 0;
	stations[0].minTime = 0;
	stations[0].visited = true;
	while (1)
	{
		for (int i = 1; i <= stationNum; i++)
		{
			//update the time connnected to the station with minimum station
			if (stationMap[min][i] < INF)
			{
				if (stations[min].minTime + stationMap[min][i] < stations[i].minTime)
				{
					stations[i].minTime = stations[min].minTime + stationMap[min][i];
					stations[i].pre.clear();
					stations[i].pre.push_back(min);
				}
				else if (stations[min].minTime + stationMap[min][i] == stations[i].minTime)
					stations[i].pre.push_back(min);
			}
		}
		//find the unknown station with minimum time
		int minTime = INF;
		for (int i = 1; i <= stationNum; i++)
		{
			if (!stations[i].visited && stations[i].minTime < minTime)
			{
				minTime = stations[i].minTime;
				min = i;
			}
		}
		stations[min].visited = true;
		//all station are known
		if (minTime == INF)
			break;
	}

	FindPath(destination, vector<int>());
	int minFrom = INF, minBack = INF, minPath;
	for (int i = 0; i < paths.size(); i++)
	{
		if (paths[i].from < minFrom)
		{
			minPath = i;
			minFrom = paths[i].from;
			minBack = paths[i].back;
		}
		else if (paths[i].from == minFrom && paths[i].back < minBack)
		{
			minPath = i;
			minBack = paths[i].back;
		}
	}

	cout << paths[minPath].from << " ";
	for (int i = 0; i < paths[minPath].path.size()-1; i++)
		cout << paths[minPath].path[i] << "->";
	cout << paths[minPath].path.back() << " ";
	cout << paths[minPath].back;
}