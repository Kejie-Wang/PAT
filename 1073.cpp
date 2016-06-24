#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	if (s[0] == '-')
		cout << s[0];
	int i = 1;
	string num;
	while (s[i] != 'E'&&i<s.size())
	{
		if (s[i] != '.')
			num.insert(num.end(), s[i]);
		i++;
	}
	i++;
	int flag = 1, radix = 0;
	if (s[i++] == '-')
		flag = -1;
	while (i < s.size())
	{
		radix = radix * 10 + s[i] - '0';
		i++;
	}

	int pointindex = 1 + flag*radix;
	if (pointindex <= 0)
		cout << "0." << string(-pointindex, '0') << num;
	else if (pointindex >= num.size())
		cout << num << string(pointindex - num.size(), '0');
	else
	{
		for (int i = 0; i < num.size(); i++)
		{
			if (i == pointindex)
				cout << ".";
			cout << num[i];
		}
	}
}