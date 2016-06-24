#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string first[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string second[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int> rfirst, rsecond;
	for (int i = 0; i < 13; i++)
	{
		rfirst[first[i]] = i;
		rsecond[second[i]] = i;
	}

	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		string s;
		getline(cin, s);
		if (isdigit(s[0]))
		{
			int num;
			stringstream ss;
			ss << s;
			ss >> num;
			int d1, d2;
			d1 = num / 13;
			d2 = num % 13;
			if (d1 != 0)
			{
				cout << second[d1];
				if (d2 != 0)
					cout << " ";
				else
					cout << endl;
			}
			if (d2 !=0)
				cout << first[d2] << endl;
			if (num == 0)
				cout << first[d2] << endl;
		}
		else
		{
			stringstream ss; 
			ss << s;
			string tmp;
			int num = 0;
			while (ss >> tmp)
			{
				if (rsecond.find(tmp) != rsecond.end())
					num += rsecond[tmp] * 13;
				else
					num += rfirst[tmp];

			}

			cout << num << endl;
		}
	}
}