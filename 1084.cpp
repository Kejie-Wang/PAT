#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	bitset<127> is_out;

	int i, j;
	i = j = 0;
	while (i < s1.size() && j < s2.size())
	{
		if (s1[i] != s2[j])
		{
			char c = toupper(s1[i]);
			if (!is_out[c])
			{
				cout << c;
				is_out.set(c);
			}
		}
		else
			j++;
		i++;
	}
	while (i < s1.size())
	{
		char c = toupper(s1[i]);
		if (!is_out[c])
		{
			cout << c;
			is_out.set(c);
		}
		i++;
	}
}