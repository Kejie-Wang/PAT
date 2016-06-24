#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct People
{
	string name;
	int age;
	int wealth;
};

bool cmp(const People& lhs, const People& rhs)
{
	if (lhs.wealth == rhs.wealth&&lhs.age == rhs.age)
		return lhs.name < rhs.name;
	else if (lhs.wealth == rhs.wealth)
		return lhs.age < rhs.age;
	else
		return lhs.wealth > rhs.wealth;
}

vector<People> age[201];

int FindMax(int *index, int Amin, int Amax)
{
	People max;
	int maxAge = -1;
	max.wealth = -0x7ffffff;
	//max.name = "max";
	//max.age = -1;
	for (int i = Amin; i <= Amax; i++)
	{
		if (index[i] < age[i].size() && cmp(age[i][index[i]], max))
		{
			max = age[i][index[i]];
			maxAge = i;
		}
	}
	
	return maxAge;
}

int main()
{
	int peopleNum, queryNum;
	cin >> peopleNum >> queryNum;

	for (int i = 0; i < peopleNum; i++)
	{
		People tmp;
		char s[9];
		scanf("%s%d%d", s, &tmp.age, &tmp.wealth);
		tmp.name = string(s);
		age[tmp.age].push_back(tmp);
	}
	for (int i = 1; i < 201; i++)
		sort(age[i].begin(), age[i].end(), cmp);

	for (int i = 0; i < queryNum; i++)
	{
		printf("Case #%d:\n", i + 1);
		int max, Amin, Amax;
		scanf("%d%d%d", &max, &Amin, &Amax);
		int index[201], cnt = 0;
		memset(index, 0, 201 * sizeof(int));
		while (cnt < max)
		{
			int maxAge = FindMax(index, Amin, Amax);
			if (maxAge == -1)
				break;
			else
			{
				People max = age[maxAge][index[maxAge]];
				printf("%s %d %d\n", max.name.c_str(), max.age, max.wealth);
				index[maxAge]++;
				cnt++;
			}
		}
		if (cnt == 0)
			printf("None\n");
	}
}