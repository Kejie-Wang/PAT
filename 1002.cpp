#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class polynomial
{
private:
	vector<double> coefficient;
	vector<int> radix;
public:
	friend polynomial operator+(const polynomial &poly1, const polynomial &poly2);
	friend istream& operator>>(istream &is, polynomial &poly);
	friend ostream& operator<<(ostream &os, const polynomial &poly);
};

polynomial operator+(const polynomial &poly1, const polynomial &poly2)
{
	polynomial polysum;

	int i=0, j=0;
	while(i<poly1.radix.size() || j<poly2.radix.size())
	{
		//only poly1 or the radix of poly1 greater than poly2
		if((i<poly1.radix.size()&&j==poly2.radix.size()) || (poly1.radix[i] > poly2.radix[j]))
		{
			polysum.radix.push_back(poly1.radix[i]);
			polysum.coefficient.push_back(poly1.coefficient[i]);
			i++;
		}
		//only poly2 or the radix of poly1 less than poly2
		else if((j<poly2.radix.size()&&i==poly1.radix.size()) || (poly1.radix[i] < poly2.radix[j]))
		{
			polysum.radix.push_back(poly2.radix[j]);
			polysum.coefficient.push_back(poly2.coefficient[j]);
			j++;
		}
		//the radix of poly1 equal to poly2
		else
		{
			if(poly1.coefficient[i] + poly2.coefficient[j]!=0)
			{
				polysum.radix.push_back(poly1.radix[i]);
				polysum.coefficient.push_back(poly1.coefficient[i] + poly2.coefficient[j]);
			}
			i++;
			j++;
		}
	}

	return polysum;
}

istream& operator>>(istream &is, polynomial &poly)
{
	int k;
	is >> k;
	for(int i=0;i<k;i++)
	{
		double tmpcoe;
		int tmprad;
		is >> tmprad >> tmpcoe;
		poly.radix.push_back(tmprad);
		poly.coefficient.push_back(tmpcoe);
	}

	return is;
}

ostream& operator<<(ostream &os, const polynomial &poly)
{
	os << poly.radix.size();
	if(poly.radix.size()!=0)
		cout << " ";
	for(int i=0;i<poly.radix.size();i++)
	{
			os << poly.radix[i] << " " << fixed << setprecision(1) << poly.coefficient[i];
			if(i!=poly.radix.size()-1)
				os << " ";
	}

	return os;
}

int main()
{
	 polynomial poly1, poly2;

	 cin >> poly1 >> poly2;
	 cout << poly1+poly2;
}