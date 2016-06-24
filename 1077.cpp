#include <iostream>
#include <string>

using namespace std;

string s[100];

int main()
{
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		string tmp;
		getline(cin, tmp);
		s[i].assign(tmp.rbegin(), tmp.rend());
	}
	int i = 0;
	while (1)
	{
		if (i >= s[0].size())
			break;
		char c = s[0][i];
		int j;
		for (j = 1; j < n; j++)
		{
			if (i >= s[j].size() || s[j][i] != c)
				break;
		}
		if (j != n)
			break;
		i++;
	}

	if (i == 0)
		cout << "nai";
	else
	{
		for (int j = i - 1; j >= 0; j--)
			cout << s[0][j];
	}
}