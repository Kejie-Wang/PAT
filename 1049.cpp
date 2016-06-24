#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int ToInt(string num)
{
	int res = 0;
	for (int i = 0; i < num.size(); i++)
		res = res * 10 + num[i] - '0';
	return res;
}

int CountingOnes(string num)
{
	if (num.size() == 1)
	{
		if (num == "0")
			return 0;
		else
			return 1;
	}
	else
	{
		int total = 0;
		int first = num[0] - '0';
		string sub = string(num.begin() + 1, num.end());
		if (first == 1)
			total += (ToInt(sub) + 1);
		else if (first > 1)
			total += pow(10, sub.size());
		total += CountingOnes(sub) + first * CountingOnes(string(sub.size(), '9'));
		return total;
	}
}

int main()
{
	string num;
	cin >> num;

	cout << CountingOnes(num);
}