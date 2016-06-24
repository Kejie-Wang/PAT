#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>

using namespace std;

struct Record
{
	string plateNum;
	string time;
	string status;
};

Record records[10000];
bitset<10000> paired;
map<string, int> in;
string query[80000];

bool cmp(Record r1, Record r2)
{
	return r1.time < r2.time;
}

int Duration(string start, string end)
{
	for (int i = 0; i < start.size(); i++)
		if (start[i] == ':')
			start[i] = end[i] = ' ';

	int h1, h2, m1, m2, s1, s2;
	stringstream ss;
	ss << start << " " << end;
	ss >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

	return (h2 * 60 * 60 + m2 * 60 + s2) - (h1 * 60 * 60 + m1 * 60 + s1);
}

string ToStandardTime(int duration)
{
	int h, m, s;
	h = duration / 3600;
	m = (duration - 3600 * h) / 60;
	s = duration - 3600 * h - m * 60;

	return string(1, h / 10 + '0') + string(1, h % 10 + '0') + ":" + \
		string(1, m / 10 + '0') + string(1, m % 10 + '0') + ":" + \
		string(1, s / 10 + '0') + string(1, s % 10 + '0');
}

int main()
{
	int recordNum, queryNum;
	cin >> recordNum >> queryNum;
	for (int i = 0; i < recordNum; i++)
		cin >> records[i].plateNum >> records[i].time >> records[i].status;
	for (int i = 0; i < queryNum; i++)
	{
		char s[10];
		scanf("%s", s);
		query[i] = string(s);
	}

	sort(records, records + recordNum, cmp);
	//sure whether a record is paired
	for (int i = 0; i < recordNum; i++)
	{
		if (records[i].status == "in")
			in[records[i].plateNum] = i;
		else
		{
			map<string, int>::iterator it = in.find(records[i].plateNum);
			if ( it != in.end())
			{
				int indexOfin = in[records[i].plateNum];
				paired.set(indexOfin);
				paired.set(i);
				in.erase(it);
			}
		}
	}
	in.clear();

	int queryIndex = 0;
	string querytime = query[queryIndex++];
	map<string, int> duration;
	for (int i = 0; i < recordNum; i++)
	{
		while(querytime < records[i].time)
		{
			cout << in.size() << endl;
			if (queryIndex < queryNum)
				querytime = query[queryIndex++];
			else
				querytime = "24:00:00";
		}
		if (paired[i])
		{
			if (records[i].status == "in")
				in[records[i].plateNum] = i;
			else
			{
				int indexOfIn = in[records[i].plateNum];
				if (duration.find(records[i].plateNum) == duration.end())
					duration[records[i].plateNum] = Duration(records[indexOfIn].time, records[i].time);
				else
					duration[records[i].plateNum] += Duration(records[indexOfIn].time, records[i].time);
				in.erase(in.find(records[i].plateNum));
			}
		}
	}
	if (querytime != "24:00:00")
	{
		for (int i = 0; i <= queryNum - queryIndex; i++)
			cout << 0 << endl;
	}

	//sure the maximum period and corresponding plate numbers
	int maxDuration = -1;
	vector<string> plate;
	for (map<string, int>::iterator it = duration.begin(); it != duration.end(); it++)
	{
		if (it->second > maxDuration)
		{
			maxDuration = it->second;
			plate.clear();
			plate.push_back(it->first);
		}
		else if (it->second == maxDuration)
			plate.push_back(it->first);
	}
	for (vector<string>::iterator it = plate.begin(); it != plate.end(); it++)
		cout << *it << " ";
	cout << ToStandardTime(maxDuration);
}