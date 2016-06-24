#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node
{
	vector<int> vec;
	int level;
	int count;
};

Node distributor[100000];
double total = 0;
double p, r;

void SetLevel(int root)
{
	if (distributor[root].vec.empty())
	{
		total += p*pow(1 +r*1.0/100, distributor[root].level)*distributor[root].count;
		return;
	}	
	for (int i = 0; i < distributor[root].vec.size(); i++)
	{
		int child = distributor[root].vec[i];
		distributor[child].level = distributor[root].level + 1;
		SetLevel(child);
	}
}

int main()
{
	int n;
	cin >> n >> p >> r;
	for (int i = 0; i < n; i++)
	{
		int num, id;
		cin >> num;
		if (num == 0)
			cin >>distributor[i].count;
		for (int j = 0; j < num; j++)
		{
			cin >> id;
			distributor[i].vec.push_back(id);
		}
	}	
	distributor[0].level = 0;
	SetLevel(0);

	cout << fixed << setprecision(1) << total;
}
