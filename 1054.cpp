#include <iostream>

using namespace std;

int ColorNum[16777216];

int main()
{
	int M, N;
	cin >> M >> N;
	int maxNum = 0, maxColor = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int color;
			cin >> color;
			if (++ColorNum[color] > maxNum)
			{
				maxNum = ColorNum[color];
				maxColor = color;
			}
		}
	cout << maxColor;
}