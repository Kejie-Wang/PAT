#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> factors, radix;
	long factor = 2;
	long num;
	cin >> num;
	cout << num << "=";
	if (num == 1)
	{
		cout << 1;
		return 0;
	}
	while (num != 1)
	{
		int cnt = 0;
		if (num % factor == 0)
			factors.push_back(factor);
		while (num%factor == 0)
		{
			cnt++;
			num /= factor;
		}
		if (cnt!=0)
			radix.push_back(cnt);
		factor++;
	}
	
	for (int i = 0; i < factors.size() - 1; i++)
	{
		cout << factors[i];
		if (radix[i]>1)
			cout << "^" << radix[i];
		cout << "*";
	}
	cout << factors.back();
	if (radix.back() > 1)
		cout << "^" << radix.back();
}