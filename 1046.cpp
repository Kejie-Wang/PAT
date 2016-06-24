#include <cstdio>
#include <iostream>

using namespace std;

int exitDst[100000];
int sumDst[100001];

int main()
{
	int exitNum, totalDst=0;
	cin >> exitNum;
	for (int i = 0; i < exitNum; i++)
		scanf("%d", &exitDst[i]);
	for (int i = 1; i < exitNum; i++)
		sumDst[i] = sumDst[i - 1] + exitDst[i - 1];
	totalDst= sumDst[exitNum-1] + exitDst[exitNum-1];

	int queryNum;
	cin >> queryNum;
	for (int i = 0; i < queryNum; i++)
	{
		int start, end, Dst=0;
		scanf("%d%d", &start, &end);
		Dst = sumDst[end - 1] - sumDst[start - 1];
		Dst = Dst >0 ? Dst : -Dst;
		if (totalDst - Dst < Dst)
			printf("%d\n", totalDst - Dst);
		else
			printf("%d\n", Dst);
	}
}