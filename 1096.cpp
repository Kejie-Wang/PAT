#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long num;
	cin >> num;

	long long start = 2, length = 0;
	long long maxLength = 0, maxStart;
	long long remain = num;
	while (1)
	{
		if (remain % (start + length) != 0)
		{
			if (length > maxLength)
			{
				maxLength = length;
				maxStart = start;
			}
			start++;
			length = 0;
			remain = num;
			if (start*start > num)
				break;
		}
		else
		{
			remain /= (start + length);
			length++;
		}
	}

	if (maxLength == 0)
	{
		cout << 1 << endl;
		cout << num;
		return 0;
	}
	cout << maxLength << endl;
	for (long long i = 0; i < maxLength; i++)
	{
		cout << maxStart + i;
		if (i < maxLength - 1)
			cout << "*";
	}
}