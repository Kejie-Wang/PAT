#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Mooncake
{
    double weight;
    double totalProfit;
    double unitPrice;
};

Mooncake cake[1005];

bool cmp(const Mooncake& cake1, const Mooncake& cake2)
{
    return cake1.unitPrice > cake2.unitPrice;
}

int main()
{
    int kinds, maxDemand;
    cin >> kinds >> maxDemand;
    for (int i = 0; i < kinds; i++)
        cin >> cake[i].weight;
    for (int i = 0; i < kinds; i++)
    {
        cin >> cake[i].totalProfit;
        cake[i].unitPrice = cake[i].totalProfit / cake[i].weight;
    }
    sort(cake, cake + kinds, cmp);

    int diff = maxDemand, i = 0;
    double maxProfit=0;
    while (diff != 0&&i<kinds)
    {
        if (diff>cake[i].weight)
        {
            maxProfit += cake[i].totalProfit;
            diff -= cake[i].weight;
        }
        else
        {
            maxProfit += (cake[i].unitPrice*diff);
            diff = 0;            
        }
        i++;
    }

    cout << fixed << setprecision(2) << maxProfit;
}