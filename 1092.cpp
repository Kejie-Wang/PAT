#include <iostream>
#include <string>

using namespace std;

class color{
public:
	string col;
	int count[62];
public:
	color(string s);
	~color();
};

color::color(string s)
{
	col = s;

	for(int i=0; i<62; i++)
		count[i] = 0;
	for(int i=0; i< s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9')
			count[s[i]-'0']++;
		else if(s[i]>='a' && s[i]<='z')
			count[s[i]-'a'+10]++;
		else if(s[i]>='A' && s[i]<='Z')
			count[s[i]-'A'+36]++;
	}
}
color::~color(){}

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	color Own(s1);
	color ToBuy(s2);
	int lack=0, extra=0;

	for(int i=0; i<62; i++)
	{
		if (Own.count[i] < ToBuy.count[i])
			lack += (ToBuy.count[i] - Own.count[i]);
		else
			extra += (Own.count[i] - ToBuy.count[i]);
	}
	if(lack==0)
		cout << "Yes " << extra;
	else
		cout << "No " << lack;
}