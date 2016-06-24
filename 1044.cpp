#include <cstdio>
#include <vector>

using namespace std;

int diamonds[100001];

int main()
{
    int diamondsNum, amountToPay;
    scanf("%d%d", &diamondsNum, &amountToPay);
    for (int i = 0; i < diamondsNum; i++)
        scanf("%d", &diamonds[i]);

    int start = 1, end = 0, sum=0, maxdiff = 10000;
    bool IsSolution = false;
    vector<int> minstart, minend;
    for (int i = 0; i < diamondsNum; i++)
    {
        sum += diamonds[i];
        end++;
        if (sum == amountToPay)
        {
            IsSolution = true;
            printf("%d-%d\n", start, end);
            //cout << start << "-" << end << endl;
            sum -= diamonds[start-1];
            start++;
        }
        else if (sum > amountToPay)
        {
            while (sum > amountToPay)
            {
                if (sum - amountToPay < maxdiff)
                {
                    minstart.clear();
                    minend.clear();
                    minstart.push_back(start);
                    minend.push_back(end);
                    maxdiff = sum - amountToPay;
                }
                else if (sum - amountToPay == maxdiff)
                {
                    minstart.push_back(start);
                    minend.push_back(end);
                }
                sum -= diamonds[start-1];
                start++;
            }
            if (sum == amountToPay)
            {
                IsSolution = true;
                printf("%d-%d\n", start, end);
                sum -= diamonds[start-1];
                start++;
            }
        }
    }
    if (!IsSolution)
    {
        for (int i = 0; i < minstart.size(); i++)
            printf("%d-%d\n", minstart[i], minend[i]);
    }
}