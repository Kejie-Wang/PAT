#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string spell(int digit)
{
	if(digit==0)
		return "zero";
	else if(digit==1)
		return "one";
	else if(digit==2)
		return "two";
	else if(digit==3)
		return "three";
	else if(digit==4)
		return "four";
	else if(digit==5)
		return "five";
	else if(digit==6)
		return "six";
	else if(digit==7)
		return "seven";
	else if(digit==8)
		return "eight";
	else if(digit==9)
		return "nine";
}

int main()
{
	string num;
	int sum=0;
	string res;

	cin >> num;
	for(int i=0;i<num.size();i++)
		sum += (num[i]-'0');
	int digit = sum%10;
	sum /= 10;
	res = spell(digit) + res;

	while(sum!=0)
	{
		digit = sum%10;
		sum /=10;
		res = spell(digit) + " " + res;
	}

	cout << res;

}
