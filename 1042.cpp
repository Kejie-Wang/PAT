#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Card
{
	char c;
	int num;
	int index;
};

bool cmp(Card c1, Card c2)
{
	return c1.index < c2.index;
}

int main()
{
	vector<Card> vec(54);
	char ch[5]{'S', 'H', 'C', 'D', 'J'};

	for (int i = 0; i < 54; i++)
	{
		vec[i].c = ch[i / 13];
		vec[i].index = i % 13 + 1;
		vec[i].num = i % 13 + 1;
	}
	int repeat;
	vector<int> order(54);
	cin >> repeat;
	for (int i = 0; i < 54; i++)
		cin >> order[i];

	while (repeat--)
	{
		for (int i = 0; i < 54; i++)
			vec[i].index = order[i];
		sort(vec.begin(), vec.end(), cmp);
	}

	for (int i = 0; i < 53; i++)
		cout << vec[i].c << vec[i].num << " ";
	cout << vec[53].c << vec[53].num;
}