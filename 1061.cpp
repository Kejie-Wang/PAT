#include <iostream>
#include <string>

using namespace std; 

int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string day[7]{"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	int i = 0, cnt=0;
	while (i < s1.size() && i < s2.size())
	{
		if (s1[i] == s2[i] && (s1[i] >= 'A'&&s1[i] <= 'G')&&cnt == 0)
		{
			cout << day[s1[i] - 'A'] << " ";
			cnt++;
		}
		else if (s1[i] == s2[i] && cnt == 1)
		{
			if (s1[i] >= '0'&&s1[i] <= '9')
			{
				cout << 0 << s1[i];
				cnt++;
			}
			else if (s1[i] >= 'A'&&s1[i] <= 'N')
			{
				cout << s1[i] - 'A' + 10;
				cnt++;
			}
		}
		if (cnt == 2)
			break;
		i++;
	}
	i = 0;
	while (i < s3.size() && i < s4.size())
	{
		if (s3[i] == s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z')))
		{
			if (i < 9)
				cout << ":0" << i;
			else
				cout << ":"<< i;
			break;
		}
		i++;
	}
	
}