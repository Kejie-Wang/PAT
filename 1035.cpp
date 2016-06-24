#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool modify(string &pwd)
{
	bool ismodify = false;

	for (string::iterator it = pwd.begin(); it != pwd.end(); it++)
	{
		if (*it == '1')
		{
			*it = '@';
			ismodify = true;
		}
		else if (*it == '0')
		{
			*it = '%';
			ismodify = true;
		}
		else if (*it == 'l')
		{
			*it = 'L';
			ismodify = true;
		}
		else if (*it == 'O')
		{
			*it = 'o';
			ismodify = true;
		}
	}
	return ismodify;
}

int main()
{
	int testNum;
	vector<string> username, passwd;
	bitset<1000> ismodify;

	cin >> testNum;
	for (int i = 0; i < testNum; i++)
	{
		string name, pwd;
		cin >> name >> pwd;
		username.push_back(name);
		passwd.push_back(pwd);
	}
	int cnt = 0;
	for (int i = 0; i < testNum; i++)
		if (modify(passwd[i]))
		{
			ismodify.set(i);
			++cnt;
		}
	if (cnt == 0)
	{
		if (testNum == 1)
			cout << "There is " << testNum << " account and no account is modified";
		else
			cout << "There are " << testNum << " accounts and no account is modified";
	}
	else
	{
		cout << cnt << endl;
		for (int i = 0; i < testNum; i++)
			if (ismodify[i])
				cout << username[i] << " " << passwd[i] << endl;
	}

}