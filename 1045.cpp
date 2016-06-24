#include <iostream>
#include <vector>

using namespace std;

vector<int> index[201];
int favoriteColor[201];
int stripe[10001];
int maxLength[201][10000];

//find the max index in this sub color, if not return -1
int FindColor(int color, int column)
{
	vector<int>& vec = index[color];
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] <= column)
			return vec[i];
	return -1;
}
int main()
{
	int colorNum, n;
	cin >> colorNum >> n;
	for (int i = 0; i < n; i++)	//get the favourite colors
		cin >> favoriteColor[i];
	for (int i = n - 1; i >= 0; i--)	
		index[favoriteColor[i]].push_back(i);
	int length;
	cin >> length;
	for (int i = 1; i <= length; i++)
		cin >> stripe[i];

	for (int j = 0; j < n; j++)	//initial 
		maxLength[j][0] = 0;
	for (int j = 1; j <= length; j++)
	{
		int color = stripe[j];
		for (int i = 0; i < n; i++)
		{
			if (FindColor(color, i) == -1)
				maxLength[i][j] = maxLength[i][j - 1];
			else
			{
				int index = FindColor(color, i);
				if (maxLength[index][j - 1] + 1 > maxLength[i][j - 1])
					maxLength[i][j] = maxLength[index][j - 1] + 1;
				else
					maxLength[i][j] = maxLength[i][j - 1];
			}
		}
	}

	cout << maxLength[n-1][length];
}
}