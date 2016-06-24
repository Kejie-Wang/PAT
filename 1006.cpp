#include <iostream>
#include <string>

using namespace std;

class Record
{
private:
	string id;
	string sign_in;
	string sign_out;
public:
	friend istream& operator>>(istream& is, Record& item);
	friend bool cmp_in(Record& lhs, Record& rhs);
	friend bool cmp_out(Record& lhs, Record& rhs);
	string GetId(){ return id; }
	string GetIn(){ return sign_in; }
	string GetOut(){ return sign_out; }
};

istream& operator>>(istream& is, Record& item)
{
	is >> item.id >> item.sign_in >> item.sign_out;

	return is;
}

bool cmp_in(Record& lhs, Record& rhs)
{
	return lhs.sign_in > rhs.sign_in;
}

bool cmp_out(Record& lhs, Record& rhs)
{
	return lhs.sign_out > rhs.sign_out;
}

int main()
{
	Record min_in, max_out, tmp;
	string id_in, id_out;
	int recordNum;

	cin >> recordNum;
	cin >> tmp;
	min_in = max_out = tmp;
	id_in = tmp.GetId();
	id_out = tmp.GetId();

	while (--recordNum)
	{
		cin >> tmp;
		if (cmp_in(min_in, tmp))
		{
			min_in = tmp;
			id_in = tmp.GetId();
		}
		if (cmp_out(tmp, max_out))
		{
			max_out = tmp;
			id_out = tmp.GetId();
		}
	}

	cout << id_in << " " << id_out;
}
