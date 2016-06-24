#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct GasStation
{
	double price;
	double dst;
	double fill;
};

GasStation station[500];
int maxTank, totalDst, stationNum, avg;

void GasConsume(double initialGas, int start, int end)
{
	if (start == end)
		return;
	//find the station with min price
	double minprice = station[start].price;
	int min = start;
	for (int i = start + 1; i < end; i++)
	{
		if (station[i].price <= minprice)
		{
			minprice = station[i].price;
			min = i;
		}
	}
	double length1 = station[min].dst - station[start].dst;
	double length2 = station[end].dst - station[min].dst;
	double maxConsume1 = length1 / avg, maxConsume2 = length2 / avg;
	if (maxConsume1 >= initialGas && maxConsume2 >= maxTank)
		station[min].fill = maxTank;
	else if (maxConsume1 < initialGas && maxConsume2 >= maxTank)
		station[min].fill = maxTank - (initialGas - maxConsume1);
	else if (maxConsume1 > initialGas && maxConsume2 < maxTank)
		station[min].fill = maxConsume2;
	else if (maxConsume1 + maxConsume2 > initialGas)
		station[min].fill = maxConsume2 - (initialGas - maxConsume1);
	else
		station[min].fill = 0;

	GasConsume(initialGas, start, min);
	double totalFill = 0;
	for (int i = start; i <= min; i++)
		totalFill += station[i].fill;
	double init = initialGas + totalFill - (station[min + 1].dst - station[start].dst) / avg;
	GasConsume(init, min+1, end);

}

bool cmp(const GasStation& s1, const GasStation& s2)
{
	return s1.dst < s2.dst;
}

int main()
{

	cin >> maxTank >> totalDst >> avg >> stationNum;

	for (int i = 0; i < stationNum; i++)
		cin >> station[i].price >> station[i].dst;
	station[stationNum].dst = totalDst;
	sort(station, station + stationNum, cmp);

	if (station[0].dst != 0)
	{
		cout << "The maximum travel distance = 0.00";
		return 0;
	}
	for (int i = 1; i <= stationNum; i++)
	{
		if (station[i].dst - station[i - 1].dst > maxTank*avg)
		{
		
			cout << "The maximum travel distance = ";
			printf("%.2f", station[i - 1].dst + maxTank*avg);
			return 0;
		}
	}
	GasConsume(0, 0, stationNum);
	double totalCost = 0, total=0;
	for (int i = 0; i < stationNum; i++)
		totalCost += station[i].fill*station[i].price;

	printf("%.2f", totalCost);
}