#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	long P_cnt=0, T_cnt=0;
	long res=0;
	int i;
	cin >> s;

	for(i=0;i<s.size();i++)
		if(s[i]=='T')
			T_cnt++;

	for(i=0;i<s.size();i++)
	{
		if(s[i]=='A')
		{
			res += ((P_cnt*T_cnt)%1000000007);
			res = res%1000000007;
		}
		else if(s[i]=='P')
			P_cnt++;
		else
			T_cnt--;
	}

	cout << res;

}