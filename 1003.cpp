#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7fffffff;
struct Node
{
	bool isknown = false;
	int minLength = INF;
};

int rescueTeams[500];
int cityMap[500][500];
int MaxTeams[500];
int minPath[500];
Node nodes[500];

int main()
{
	int cityNum, roadNum, start, destination;

	for (int i = 0; i<500; i++)	//initialize the city map
		for (int j = 0; j<500; j++)
			cityMap[i][j] = INF;

	cin >> cityNum >> roadNum >> start >> destination;
	for (int i = 0; i<cityNum; i++)
		cin >> rescueTeams[i];

	//construct the city map
	for (int i = 0; i<roadNum; i++)
	{
		int c1, c2, length;
		cin >> c1 >> c2 >> length;
		if (cityMap[c1][c2] > length)
			cityMap[c1][c2] = cityMap[c2][c1] = length;
	}

	//using dijkstra algorithms
	nodes[start].isknown = true;	//set the start konwn
	nodes[start].minLength = 0;
	MaxTeams[start] = rescueTeams[start];
	minPath[start] = 1;
	int minNode = start;
	int cnt = 1;
	while (cnt < cityNum)
	{
		//update the node connnected to the minimum node
		for (int j = 0; j<cityNum; j++)
		{
			if (cityMap[minNode][j] < INF)
			{
				//with a equal length and record the route
				if (nodes[minNode].minLength + cityMap[minNode][j] == nodes[j].minLength)
				{
					if (MaxTeams[j] < MaxTeams[minNode] + rescueTeams[j])
						MaxTeams[j] = MaxTeams[minNode] + rescueTeams[j];
					minPath[j] += minPath[minNode];
				}
				//with a smaller length
				else if (nodes[minNode].minLength + cityMap[minNode][j] < nodes[j].minLength)
				{
					nodes[j].minLength = nodes[minNode].minLength + cityMap[minNode][j];
					MaxTeams[j] = rescueTeams[j] + MaxTeams[minNode];
					minPath[j] = minPath[minNode];
				}			
			}
		}

		//find the unkonwn node with the minimum length
		int minLength = INF;
		for (int i = 0; i<cityNum; i++)
		{
			if (!nodes[i].isknown && minLength > nodes[i].minLength)
			{
				minLength = nodes[i].minLength;
				minNode = i;
			}
		}
		nodes[minNode].isknown = true;
		cnt++;
	}

	cout << minPath[destination] << " " << MaxTeams[destination];
}