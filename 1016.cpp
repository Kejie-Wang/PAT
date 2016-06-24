#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Record
{
	string month;
	string name;
	string time;
	string type;
};

int toll[24];
Record records[1000];

bool cmp(const Record& lhs, const Record& rhs)
{
	if (lhs.name == rhs.name)
		return lhs.time < rhs.time;
	else
		return lhs.name < rhs.name;
}

//calculate the duration of two time
int Duration(string start, string end)
{
	if (start >= end)
		return 0;
	for (int i = 0; i < start.size(); i++)
		if (start[i] == ':')
			start[i] = end[i] = ' ';
	int d1, d2, h1, h2, m1, m2;
	stringstream ss;
	ss << start;
	ss >> d1 >> h1 >> m1;
	ss.clear();
	ss << end;
	ss >> d2 >> h2 >> m2;

	return 24 * 60 * (d2 - d1) + 60 * (h2 - h1) + (m2 - m1);
}

//calculate the cost from "00:00:00" to the given time
double Cost(string time)
{
	for (int i = 0; i < time.size(); i++)
		if (time[i] == ':')
			time[i] = ' ';
	stringstream ss;
	ss << time;
	int d, h, m;
	ss >> d >> h >> m;
	double cost = 0;
	int sum = 0;
	for (int i = 0; i < 24; i++)
		sum += toll[i];
	cost += (1.0 * sum / 100 * d *60);
	for (int i = 0; i < h; i++)
 		cost += (1.0 * toll[i] / 100 * 60);
	cost += (1.0 * toll[h] / 100 * m);

	return cost;
}

int main()
{
	for (int i = 0; i < 24; i++)
		cin >> toll[i];
	int recordNum;
	string month;
	cin >> recordNum;
	for (int i = 0; i < recordNum; i++)
	{
		string time;
		cin >> records[i].name >> time >> records[i].type;
		records[i].month = time.substr(0, 2);
		records[i].time = time.substr(3, time.size() - 3);
	}
	sort(records, records + recordNum, cmp);
	
	string name;
	vector<Record> vec;
	for (int i = 0; i < recordNum; i++)
	{
		//the same customer and store them in the vector
		if (name.empty() || records[i].name == name)
		{
			vec.push_back(records[i]);
			name = records[i].name;
		}
		//an another different customer or the last record
		if ((!name.empty()&&records[i].name != name) || (i==recordNum-1))
		{
			//check if there is any record paired
			bool flag = false;
			int j;
			for (j = 0; j < vec.size(); j++)
			{
				if (vec[j].type == "on-line")
					flag = true;
				if (flag&& vec[j].type == "off-line")
					break;
			}
			if (j == vec.size())	//no records paired and not print anything
			{
				name = records[i].name;
				vec.clear();
				vec.push_back(records[i]);
				continue;
			}
			//print the records
			cout << name << " " << records[i-1].month << endl;
			string start, end;
			double totalCost = 0;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i].type == "on-line")
					start = vec[i].time;
				else if (vec[i].type == "off-line"&&!start.empty())
				{
					end = vec[i].time;
					int total;
					double cost;				
					total = Duration("00:00:00", end) - Duration("00:00:00", start);
					cost = Cost(end) - Cost(start);
					cout << start << " "<< end << " " << total << " $" << fixed << setprecision(2) << cost << endl;
					totalCost += cost;
					start.clear();
				}
			}
			cout << "Total amount: $" << totalCost << endl;

			name = records[i].name;
			vec.clear();
			vec.push_back(records[i]);
		}
	}
}