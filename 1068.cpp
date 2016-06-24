#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coins[10001];
int money[10001][101];
int all[10001][101];
vector<int> ToPay;

void FindCoins(int amount, int index)
{
	if (amount == 0)
		return;
	for (int i = index; i >= 0; i--)
	{
		if (money[i][amount] == 1)
		{
			ToPay.push_back(coins[i]);
			FindCoins(amount - coins[i], i - 1);
			return;
		}
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int coinsNum, amountToPay;
	cin >> coinsNum >> amountToPay;
	for (int i = 0; i < coinsNum; i++)
		cin >> coins[i];
	sort(coins, coins + coinsNum, cmp);
	//initialize
	for (int i = 0; i < coinsNum; i++)
		money[i][0] = all[i][0] = 1;
	for (int i = 0; i < coinsNum; i++)
	{
		if (i == 0)
		{
			money[i][coins[i]] = all[i][coins[i]] = 1;
			continue;
		}
		for (int j = 0; j <= amountToPay; j++)
		{
			if (all[i - 1][j] == 1)
				all[i][j] = 1;
			if (all[i - 1][j] == 1 && j + coins[i] <= amountToPay)
			{
				money[i][j + coins[i]] = 1;
				all[i][j + coins[i]] = 1;
			}
		}
	}
	if (all[coinsNum - 1][amountToPay] == 0)
	{
		cout << "No Solution";
		return 0;
	}
	FindCoins(amountToPay, coinsNum-1);
	
	for (int i = 0; i < ToPay.size()-1; i++)
		cout << ToPay[i] << " ";
	cout << ToPay.back();
}