#include <iostream>
#include <string>

using namespace std;

string toRadix13(int num)
{
	int n1 = num / 13;
	int n2 = num % 13;
	char c1, c2;
	if (n1 < 10)
		c1 = n1 + '0';
	else
		c1 = n1 - 10 + 'A';
	if (n2 < 10)
		c2 = n2 + '0';
	else
		c2 = n2 - 10 + 'A';
	return string(1, c1) + string(1, c2);
}

int main()
{
	int red, green, blue;
	cin >> red >> green >> blue;
	string out;

	out = "#" + toRadix13(red) + toRadix13(green) + toRadix13(blue);

	cout << out;
}