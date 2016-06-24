#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> course[2501];

int main()
{
	int stuNum, courseNum;
	scanf("%d%d", &stuNum, &courseNum);

	for (int i = 0; i < stuNum; i++)
	{
		char name[5];
		int courseTakeNum;
		scanf("%s%d", name, &courseTakeNum);
		string stuName(name);
		for (int j = 0; j < courseTakeNum; j++)
		{
			int courseIndex;
			scanf("%d", &courseIndex);
			course[courseIndex].push_back(stuName);
		}
	}
	for (int i = 1; i <= courseNum; i++)
	{
		printf("%d %d\n", i, course[i].size()); 
		sort(course[i].begin(), course[i].end());
		for (int j = 0; j < course[i].size(); j++)
			printf("%s\n", course[i][j].c_str());
	}
}