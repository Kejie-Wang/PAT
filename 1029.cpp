#include <iostream>
#include <cstdio>

using namespace std;

long seq1[1000000], seq2[1000000];
long finalseq[2000000];

int main()
{
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++)
		scanf("%ld", &seq1[i]);
	cin >> n2;
	for (int i = 0; i < n2; i++)
		scanf("%ld", &seq2[i]);

	int i = 0, j = 0, k = 0;
	while (i < n1 || j < n2)
	{
		if (i == n1)	//only seqence1
			finalseq[k++] = seq2[j++];
		else if (j == n2)	//only seqence2
			finalseq[k++] = seq1[i++];
		else if (seq1[i] < seq2[j])
			finalseq[k++] = seq1[i++];
		else if (seq1[i]>seq2[j])
			finalseq[k++] = seq2[j++];
		else
		{
			finalseq[k++] = seq1[i++];
			j++;
		}
	}
	cout << finalseq[(k - 1) / 2];
}