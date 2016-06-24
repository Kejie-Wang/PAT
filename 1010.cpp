#include <iostream>
#include <string>

using namespace std;


long long ToRadix(string num, long long radix)
{
	long long res = 0;
	for (int i = 0; i < num.size(); i++)
	{
		int x = (num[i] >= '0'&&num[i] <= '9') ? num[i] - '0' : num[i] - 'a' + 10;
		res = res*radix + x;
	}

	return res;
}

int main()
{
	string num[2];
	int tag;
	long long radix;

	cin >> num[0] >> num[1] >> tag >> radix;
	long long base = ToRadix(num[tag - 1], radix);

	string number = num[2 - tag];
	if (number.size() == 1)
	{
		int x = (number[0] >= '0'&&number[0] <= '9') ? number[0] - '0' : number[0] - 'a' + 10;
		if (x == base)
			cout << x + 1;
		else
			cout << "Impossible";

		return 0;
	}

	long long minRadix = 0, maxRadix = base;
	for (int i = 0; i < number.size(); i++)
	{
		int x = (number[i] >= '0'&&number[i] <= '9') ? number[i] - '0' : number[i] - 'a' + 10;
		if (x + 1 > minRadix)
			minRadix = x + 1;
	}

	while (minRadix <= maxRadix)
	{
		long long middle = (minRadix + maxRadix) / 2;
		long long x = ToRadix(number, middle);
		if (x == base)
		{
			cout << middle;
			return 0;
		}
		else if (x > base || x<0)
			maxRadix = middle - 1;
		else
			minRadix = middle + 1;
	}

	cout << "Impossible";
}