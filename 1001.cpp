#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int a, b, res;

	cin >> a >> b;

	res = a + b;
	if(res<0)	//negative number
	{
		res = -res;
		cout << "-";
	}
	//read the result into a string
	stringstream ss;
	ss << res;
	string out = ss.str();
	
	//insert commas
	int i = out.size()-3;
	while(i>0)
	{
		out.insert(i, ",");
		i -= 3;
	}

	cout << out;
}