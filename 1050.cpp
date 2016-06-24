#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
	bitset<128> IsNeedDelete;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i < s2.size(); i++)
		IsNeedDelete.set(s2[i]);

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		if (IsNeedDelete[*it])
			it = s1.erase(it);
		else
			it++;
	}
	
	cout << s1;
}