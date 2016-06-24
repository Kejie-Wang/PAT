#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

list<int> graph[10001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].insert(graph[n1].begin(), n2);
		graph[n2].insert(graph[n2].begin(), n1);
	}

	set<int> leaf;
	for (int i = 1; i <= n; i++)
		if (graph[i].size() == 1)
			leaf.insert(i);
	if (leaf.size() == 0)
		leaf.insert(1);
	int maxLength = -1;
	set<int> root;
	int length[10001];
	bitset<10001> visited;
	for (set<int>::iterator it = leaf.begin(); it != leaf.end(); it++)
	{
		visited.reset();
		queue<int> que;
		int start = *it;
		length[start] = 0;
		que.push(start);
		visited.set(start);
		bool flag = false;
		int cnt = 1;
		while (!que.empty())
		{
			int node = que.front();
			que.pop();
			for (list<int>::iterator lit = graph[node].begin(); lit != graph[node].end(); lit++)
			{
				if (!visited[*lit])
				{
					length[*lit] = length[node] + 1;
					visited.set(*lit);
					que.push(*lit);
				}
			}
			if (que.empty())
			{
				for (int i = 1; i <= n; i++)
				{
					if (!visited[i])
					{
						que.push(i);
						visited.set(i);
						flag = true;
						cnt++;
						break;
					}
				}
			}
		}

		if (flag)
		{
			cout << "Error: " << cnt << " components" << endl;
			return 0;
		}
		int max = -1, maxIndex;
		for (int j = 1; j <= n; j++)
		{
			if (length[j] > max)
			{
				max = length[j];
				maxIndex = j;
			}
		}
		if (maxLength < max)
		{
			maxLength = max;
			root.clear();
			root.insert(start);
			root.insert(maxIndex);
		}
		else if (maxLength == max)
		{
			root.insert(start);
			root.insert(maxIndex);
		}
	}

	for (set<int>::iterator it = root.begin(); it != root.end(); it++)
		cout << *it << endl;
}