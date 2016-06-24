#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int seq[100001];

int main()
{
	int n;
	cin >> n;
	getchar();
	set<int> rs, ls;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
		rs.insert(seq[i]);
	}
	int leftmax = 0, rightmin;
	if (n == 0)
		getchar();
	if (!rs.empty())
		rightmin = *rs.begin();
	else
		rightmin = 1000000000;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		rs.erase(seq[i]);
		if (!rs.empty())
			rightmin = *rs.begin();
		else
			rightmin = 1000000000;
		if (seq[i] >leftmax && seq[i] < rightmin)
			vec.push_back(seq[i]);
		ls.insert(seq[i]);
		leftmax = *ls.rbegin();
	}
	if (vec.size() == 0)
		cout << 0 << endl << endl;
	else
	{
		cout << vec.size() << endl;
		for (int i = 0; i < vec.size() - 1; i++)
			cout << vec[i] << " ";
		cout << vec.back();
	}
}