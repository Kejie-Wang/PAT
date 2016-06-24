#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class rational
{
private:
	long numertator;
	long denominator;
public:
	void read();
	void add(rational ra2);
	void reduction();
	void print();
};

void rational::read()
{
	string s, upper, lower;
	
	cin >> s;
	
	string::iterator it = s.begin();

	while (*it != '/')
		upper.insert(upper.end(), *it++);
	it++;
	while (it != s.end())
		lower.insert(lower.end(), *it++);
	stringstream ss;
	ss << upper;
	ss >> numertator;
	ss.clear();
	ss << lower;
	ss >> denominator;
}

void rational::add(rational ra2)
{
	long tmpdenominator, tmpnumertator;

	tmpdenominator = this->denominator * ra2.denominator;
	tmpnumertator = this->numertator*ra2.denominator + this->denominator*ra2.numertator;
	this->denominator = tmpdenominator;
	this->numertator = tmpnumertator;
	this->reduction();
}

void rational::reduction()
{
	long a, b;
	if (abs(numertator) > abs(denominator))
	{
		a = abs(numertator);
		b = abs(denominator);
	}
	else
	{
		a = abs(denominator);
		b = abs(numertator);
	}
	if (b == 0)
		return;
	while (a%b != 0)
	{
		long tmp = b;
		b = a % b;
		a = tmp;
	}

	numertator /= b;
	denominator /= b;
}

void rational::print()
{
	long real=0;

	if (numertator == 0)
	{
		cout << 0;
		return;
	}
	if (abs(numertator) >= abs(denominator))
	{
		real = numertator / denominator;
		numertator =abs(numertator)%denominator;
	}
	if (real&&numertator)
		cout << real << " " << numertator << "/" << denominator;
	else if (numertator == 0)
		cout << real;
	else
		cout << numertator << "/" << denominator;
}

int main()
{
	long n;
	rational ra1, ra2;

	cin >> n;
	ra1.read();
	while (--n)
	{
		ra2.read();
		ra1.add(ra2);
	}
	ra1.reduction();
	ra1.print();
}