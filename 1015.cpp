#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

//judge if the number is prime
bool IsPrime(const int &num)
{
	int upper = sqrt(num);
	if (num == 1 || num==0)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	for (int i = 3; i <= upper; i += 2)
		if (num%i == 0)
			return false;
	return true;
}

//reverse the number with radix
int ReverseWithRadix(int num, int radix)
{
	int ReverseNum = 0;

	while (num != 0)
	{
		ReverseNum = ReverseNum*radix + num%radix;
		num /= radix;
	}
	
	return ReverseNum;
}

int main()
{
	int num, radix;

	cin >> num;
	if (num < 0)
		return 0;
	while (1)
	{
		cin >> radix;
		cout << ReverseWithRadix(num, radix) << endl;
		if (IsPrime(num) && IsPrime(ReverseWithRadix(num, radix)))
			cout << "Yes";
		else
			cout << "No";

		cin >> num;
		if (num < 0)
			break;
		else
			cout << endl;
	}
}