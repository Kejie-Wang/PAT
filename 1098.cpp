#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int initialSeq[100], targetSeq[100], num;

void HeapSort(int *seq, int MaxSize)
{
	int tmp = seq[MaxSize];
	seq[MaxSize] = seq[1];
	int child;
	for (int i = 1; i * 2 < MaxSize; i = child)
	{
		child = 2 * i;
		if (child+1 != MaxSize && seq[child] < seq[child + 1])
			child++;
		if (tmp < seq[child])
			seq[i] = seq[child];
		else
			break;
	}
	seq[child] = tmp;
}

int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> initialSeq[i];
	for (int i = 1; i <= num; i++)
		cin >> targetSeq[i];

	int i = 2, index = 2;
	bool flag = true;
	while (i <= num)
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
	if (i == num+1)
	{
		cout << "Insertion Sort" << endl;
		int tmp = targetSeq[index];
		while (index > 1 && tmp < targetSeq[index - 1])
		{
			targetSeq[index] = targetSeq[index - 1];
			index--;
		}
		targetSeq[index] = tmp;
		for (int j = 1; j < num; j++)
			cout << targetSeq[j] << " ";
		cout << targetSeq[num];
	}
	else
	{
		cout << "Heap Sort" << endl;
		int last;
		for (last = num; last >= 0; last--)
			if (targetSeq[last] < targetSeq[1])
				break;
		HeapSort(targetSeq, last);
		for (int j = 1; j < num; j++)
			cout << targetSeq[j] << " ";
		cout << targetSeq[num];
	}

}