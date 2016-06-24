#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Customer 
{
	string arrivingTime;
	int serDuration;
	string serTime;
};

Customer customers[10000];
set<string> inService;

bool cmp(const Customer& c1, const Customer& c2)
{
	return c1.arrivingTime < c2.arrivingTime;
}

string AddDuration(string start, int duration)
{
	for (int i = 0; i < start.size(); i++)
		if (start[i] == ':')
			start[i] = ' ';
	int h0, m0, s0;
	stringstream ss;
	ss << start;
	ss >> h0 >> m0 >> s0;
	m0 += duration;
	h0 = h0 + m0 / 60;
	m0 = m0 % 60;
	string res = string(1, h0 / 10 + '0') + string(1, h0 % 10 + '0') + ":" + string(1, m0 / 10 + '0') + \
		string(1, m0 % 10 + '0') + ":" + string(1, s0 / 10 + '0') + string(1, s0 % 10 + '0');

	return res;
}

double GetDuration(string start, string end)
{
	for (int i = 0; i < start.size(); i++)
		if (start[i] == ':')
			start[i] = end[i] = ' ';
	int h1, h2, m1, m2, s1, s2;
	stringstream ss;
	ss << start;
	ss >> h1 >> m1 >> s1;
	ss.clear();
	ss << end;
	ss >> h2 >> m2 >> s2;

	return (h2 - h1) * 60 + (m2 - m1) + 1.0*(s2 - s1) / 60;
}

int main()
{
	int customerNum, windowsNum;
	cin >> customerNum >> windowsNum;

	for (int i = 0; i < customerNum; i++)
	{
		cin >> customers[i].arrivingTime >> customers[i].serDuration;
		if (customers[i].arrivingTime >= "17:00:00")
		{
			customerNum--;
			i--;
		}
		if (customers[i].serDuration > 60)
			customers[i].serDuration = 60;
	}
	sort(customers, customers + customerNum, cmp);

	for (int i = 0; i < windowsNum && i < customerNum; i++)
	{
		if (customers[i].arrivingTime <= "08:00:00")
			customers[i].serTime = "08:00:00";
		else
			customers[i].serTime = customers[i].arrivingTime;
		inService.insert(AddDuration(customers[i].serTime, customers[i].serDuration));
	}
	int wait = customerNum > windowsNum ? windowsNum : customerNum;

	while (!inService.empty())
	{
		string first = *(inService.begin());
		inService.erase(inService.begin());
		if (wait < customerNum)
		{
			if (first > customers[wait].arrivingTime)
			{
				inService.insert(AddDuration(first, customers[wait].serDuration));
				customers[wait].serTime = first;
			}
			else
			{
				inService.insert(AddDuration(customers[wait].arrivingTime, customers[wait].serDuration));
				customers[wait].serTime = customers[wait].arrivingTime;
			}
			wait++;
		}
	}

	double totalWait = 0;
	for (int i = 0; i < customerNum; i++)
		totalWait += GetDuration(customers[i].arrivingTime, customers[i].serTime);

	cout << fixed << setprecision(1)  << totalWait / customerNum;
}