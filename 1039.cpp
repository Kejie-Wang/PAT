#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int HashFunction(char* name)
{
	return (name[0] - 'A') * 26 * 26 * 10 + \
		(name[1] - 'A') * 26 * 10 + \
		(name[2] - 'A') * 10 + \
		(name[3] - '0');
}

vector<int> courseList[26*26*26*10];

int main()
{
	int queryNum, courseNum;
	scanf("%d%d", &queryNum, &courseNum);
	for (int i = 0; i < courseNum; i++)
	{
		int courseIndex, stuNum;
		scanf("%d%d", &courseIndex, &stuNum);
		for (int j = 0; j < stuNum; j++)
		{
			char s[5];
			scanf("%s", s);
			int index = HashFunction(s);
			courseList[index].push_back(courseIndex);
		}
	}

	for (int i = 0; i < queryNum; i++)
	{
		char name[5];
		scanf("%s", name);
		int index = HashFunction(name);
		if (courseList[index].empty())
			printf("%s 0", name);
		else
		{
			vector<int> vec = courseList[index];
			sort(vec.begin(), vec.end());
			printf("%s %d ", name, vec.size());
			for (int j = 0; j < vec.size(); j++)
			{
				printf("%d", vec[j]);
				if (j < vec.size() - 1)
					printf(" ");
			}
		}
		if (i < queryNum - 1)
			printf("\n");
	}
}