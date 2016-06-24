#include <iostream>
#include <stack>

using namespace std;

int sequence[1001];

int main()
{
	int maxCapacity, seqLength, queryNum;
	cin >> maxCapacity >> seqLength >> queryNum;

	for (int i = 0; i < queryNum; i++)
	{
		stack<int> Stack;
		for (int j = 0; j < seqLength; j++)
			cin >> sequence[j];
		int start = 1;
		int j = 0;
		while (j < seqLength)
		{
			while (start <= sequence[j])
			{
				Stack.push(start);
				start++;
				if (Stack.size() == maxCapacity)
					break;
			}
			if (Stack.top() != sequence[j])
				break;
			Stack.pop();
			j++;
		}
		if (j == seqLength)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}