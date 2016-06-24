#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int initialSeq[100], targetSeq[100], num;
void Merge(int *seq, int length)
{
    int *p = seq;
    while (p < seq + num)
    {
        if (p + length > seq + num)
            sort(p, seq + num);
        else
            sort(p, p + length);
        p += length;
    }
}

bool equal(int *p, int *q)
{
    int i = 0;
    while (i < num && p[i] == q[i])
        i++;
    if (i == num)
        return true;
    else
        return false;
}

int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> initialSeq[i];
    for (int i = 0; i < num; i++)
        cin >> targetSeq[i];

    int i= 1, index=1;
    bool flag = true;
    while (i < num)
    {
        if (targetSeq[i] >= targetSeq[i - 1] && flag)
        {
            i++;
            index = i;
        }
        else if (targetSeq[i] == initialSeq[i])
        {
            i++;
            flag = false;
        }
        else
            break;
    }
    if (i == num)
    {
        cout << "Insertion Sort" << endl;
        int tmp = targetSeq[index];
        while (index > 0 && tmp < targetSeq[index - 1])
        {
            targetSeq[index] = targetSeq[index - 1];
            index--;
        }
        targetSeq[index] = tmp;
        for (int j = 0; j < num - 1; j++)
            cout << targetSeq[j] << " ";
        cout << targetSeq[num - 1];
    }
     else
    {
        cout << "Merge Sort" << endl;
        int length = 2;
        while (!equal(initialSeq, targetSeq))
        {
            Merge(initialSeq, length);
            length *= 2;
        }
        Merge(targetSeq, length);
        for (int j = 0; j < num - 1; j++)
            cout << targetSeq[j] << " ";
        cout << targetSeq[num - 1];
    }

}