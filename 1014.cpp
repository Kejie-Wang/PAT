#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

struct Customer
{
	int serTime;
	int serDuration;
	int windows;
};

Customer customers[1000];
queue<int> windows[20];
set<int> inService;

int FindFirst()
{
	int minIndex = -1, min = 0x7fffffff;
	for (set<int>::iterator it = inService.begin(); it != inService.end(); it++)
	{
		if (customers[*it].serTime + customers[*it].serDuration < min)
		{
			minIndex = *it;
			min = customers[*it].serTime + customers[*it].serDuration;
		}
		else if (customers[*it].serTime + customers[*it].serDuration == min && *it < minIndex)
			minIndex = *it;
	}
	return minIndex;
}

string ToStandardTime(int time)
{
	int h = time / 60 + 8, m = time % 60;
	char h1 = h / 10 + '0', h2 = h % 10 + '0', m1 = m / 10 + '0', m2 = m % 10 + '0';
	
	return string(1, h1) + string(1, h2) + ":" + string(1, m1) + string(1, m2);
}

int main()
{
	int windowsNum, capacity, customersNum, queryNum;
	cin >> windowsNum >> capacity >> customersNum >> queryNum;
	for (int i = 0; i < customersNum; i++)
		cin >> customers[i].serDuration;

	for (int i = 0; i < windowsNum * capacity && i<customersNum; i++)
	{
		int index = i%windowsNum;
		windows[index].push(i);
		customers[i].windows = index;
		if (i<windowsNum)
		{
			inService.insert(i);
			customers[i].serTime = 0;
		}
	}
	int wait;
	if (customersNum > windowsNum*capacity)
		wait = windowsNum*capacity;
	else
		wait = customersNum;
	while (1)
	{
		int index = FindFirst();
		if (index == -1)	//all customer are done
			break;
		int time = customers[index].serTime + customers[index].serDuration;
		int windowsIndex = customers[index].windows;
		inService.erase(index);
		windows[windowsIndex].pop();
		if (!windows[windowsIndex].empty())	//there is some waiting in the windows
		{
			inService.insert(windows[windowsIndex].front());
			customers[windows[windowsIndex].front()].serTime = time;
		}
		if (wait < customersNum)	//someone waiting outside
		{
			windows[windowsIndex].push(wait);
			customers[wait].windows = windowsIndex;
			wait++;
		}
	}

	for (int i = 0; i < queryNum; i++)
	{
		int index;
		cin >> index;
		int time = customers[index - 1].serTime + customers[index - 1].serDuration;
		if (customers[index-1].serTime <540)
			cout << ToStandardTime(time) << endl;
		else
			cout << "Sorry" << endl;
	}
}