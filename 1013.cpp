#include <iostream>
#include <bitset>

using namespace std;

static int CityMap[1000][1000];
static int RemainCityMap[1000][1000];

//depth first search
void DFS(int root, bitset<1000> &IsChecked, int CityNum, int DestroyCity)
{
	IsChecked.set(root);
	for (int i = 1; i <= CityNum; i++)
	{
		if (CityMap[root][i] && !IsChecked[i] && i != DestroyCity)
			DFS(i, IsChecked, CityNum, DestroyCity);
	}
}

//if all is checked return 0, else return a city that is not checked
int IsAllChecked(const bitset<1000> &Ischecked, int CityNum)
{
	for (int i = 1; i <= CityNum; i++)
	{
		if (!Ischecked.test(i))
			return i;
	}
	return 0;
}

int main()
{
	int CityNum, WayNum, CheckNum;
	cin >> CityNum >> WayNum >> CheckNum;

	//construct the city map
	for (int i = 0; i < WayNum; i++)
	{
		int City1, City2;
		cin >> City1 >> City2;

		CityMap[City1][City2] = CityMap[City2][City1] = 1;
	}
	for (int i = 0; i < CheckNum; i++)
	{
		int DestroyCity;
		cin >> DestroyCity;

		bitset<1000> IsChecked;
		int cnt = 0;

		IsChecked.set(DestroyCity);
		int CityNotChecked = IsAllChecked(IsChecked, CityNum);
		while (1)
		{
			DFS(CityNotChecked, IsChecked, CityNum, DestroyCity);
			CityNotChecked = IsAllChecked(IsChecked, CityNum);
			if (!CityNotChecked)	//all checked
				break;
			else
				cnt++;
		}
		cout << cnt;
		if (i < CheckNum - 1)
			cout << endl;
	}
}