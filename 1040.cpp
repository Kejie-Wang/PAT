#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int maxlength = 0;
	for (int i = 0; i < 2 * s.size() - 1; i++)
	{
		if (2 * s.size() - i - 1 <= maxlength)
			break;

		int max=0;
		if (i % 2 == 0)
		{	
			int center = i / 2;
			++max;
			int j = 1;
			while (center - j >= 0 && center + j < s.size())
			{
				if (s[center - j] == s[center + j])
					max += 2;
				else
					break;
				j++;
			}			
		}
		else
		{
			int left = (i - 1) / 2;
			int right = (i + 1) / 2;
			while (left >= 0 && right < s.size())
			{
				if (s[left] == s[right])
					max += 2;
				else
					break;
				left--;
				right++;
			}
		}
		if (max > maxlength)
			maxlength = max;
	}
	cout << maxlength;
}