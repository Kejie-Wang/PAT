#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> coins;
	int coinsNum, amountToPay;
	cin >> coinsNum >> amountToPay;
	for (int i = 0; i < coinsNum; i++)
	{
		int value;
		scanf("%d", &value);
		coins.push_back(value);
	}
	sort(coins.begin(), coins.end());
	int start = 0, end = coins.size() - 1;
	while (start < end)
	{
		if (coins[start] + coins[end] > amountToPay)
			end--;
		else if (coins[start] + coins[end] < amountToPay)
			start++;
		else
		{
			cout << coins[start] << " " << coins[end];
			return 0;
		}
	}
	cout << "No Solution";
}
