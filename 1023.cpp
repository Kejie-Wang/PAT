#include <iostream>
#include <string>

using namespace std;

class numbers
{
friend bool is_fun(numbers number);
private:
	string num;
	unsigned int fre[10];
public:
	numbers();
	~numbers();
	void read(string num);
	string doub();
	string num_out();
};

numbers::numbers()
{
	for (unsigned int i = 0; i < 10; ++i)
		fre[i] = 0;
}

numbers::~numbers()
{

}

void numbers::read(string num)
{
	this->num = num;
	for (unsigned int i = 0; i < num.size(); i++)
		fre[num[i] - '0']++;
}

string numbers::doub()
{
	string dou_num;
	string tmpnum;
	short int carry = 0;

	for (int i = num.size() - 1; i >= 0;i--)
	{
		short int t = num[i] - '0';
		char c;
		t = t * 2 + carry;
		if (t >= 10)
		{
			c = t - 10 + '0';
			carry = 1;
			tmpnum.insert(tmpnum.end(), c);
		}
		else
		{
			c = t + '0';
			carry = 0;
			tmpnum.insert(tmpnum.end(), c);
		}
	}
	if (carry)
		tmpnum.insert(tmpnum.end(), '1');
	//reverse
	for (int i = tmpnum.size() - 1; i >= 0; i--)
		dou_num.insert(dou_num.end(), tmpnum[i]);

	return dou_num;
}

string numbers::num_out()
{
	return num;
}

bool is_fun(numbers number)
{
	numbers number2;
	string num2;
	unsigned int i;

	num2 = number.doub();
	number2.read(num2);
	for (unsigned int i = 0; i < 10; i++)
		if (number.fre[i] != number2.fre[i])
			return false;

	return true;
}

int main()
{
	string num;
	numbers number;

	cin >> num;
	number.read(num);
	if (is_fun(number))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << number.doub();
}