#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

struct Sequence
{
	multiset<int> seq;
	int sum;
};

bool cmp(Sequence s1, Sequence s2)
{
	if (s1.sum == s2.sum)
	{
		multiset<int>::reverse_iterator it1 = s1.seq.rbegin(), it2 = s2.seq.rbegin();
		while (it1 != s1.seq.rend() && it2 != s2.seq.rend())
		{
			if (*it1 == *it2)
				continue;
			return *it1 > *it2;
		}
		return true;
	}
	else
		return s1.sum > s2.sum;
	
}

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	int seq[405];
	
	Sequence array[405];
	for (int i = 1; ; i++)
	{
		int t = pow(i, p);
		if (t > n)
			break;
		array[t].seq.insert(i);
		array[t].sum = i;
	}
	while (--k)
	{
		Sequence tmp[401];
		for (int i = 1; ;i++)
		{
			if (!array[i].seq.empty())
			{
				if (i > n)
					break;
				int min = *array[i].seq.rbegin();
				for (int j = min; ;j++)
				{
					int t = pow(j, p);
					if (i + t > n)
						break;
					Sequence tmpseq = array[i];
					tmpseq.seq.insert(j);
					tmpseq.sum = array[i].sum + j;
					if (tmp[i + t].seq.empty() || cmp(tmpseq, tmp[i + t]))
						tmp[i + t] = tmpseq;
				}
			}
		}
		for (int i = 0; i < 401; i++)
		{
			array[i].seq = tmp[i].seq;
			array[i].sum = tmp[i].sum;
		}
	}

	if (array[n].seq.empty())
		cout << "Impossible";
	else
	{
		cout << n << " = ";
		for (multiset<int>::reverse_iterator it = array[n].seq.rbegin(); it != array[n].seq.rend();)
		{
			cout << *it << "^" << p;
			if (++it != array[n].seq.rend())
				cout << " + ";
		}
	}
}