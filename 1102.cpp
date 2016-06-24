#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int left = -1;
	int right = -1; //devote NULL
};

Node tree[11];

void LevelOrder(int root, int n)
{
	queue<int> que;
	que.push(root);
	int cnt = 0;
	while (!que.empty())
	{
		int node = que.front();
		cout << node;
		cnt++;
		if (cnt != n)
			cout << " ";
		else
			cout << endl;
		if (tree[node].left != -1)
			que.push(tree[node].left);
		if (tree[node].right != -1)
			que.push(tree[node].right);
		que.pop();
	}
}

int cnt = 0;
void InOrder(int root, int n)
{
	if (root == -1)
		return;
	InOrder(tree[root].left, n);
	cout << root;
	cnt++;
	if (cnt != n)
		cout << " ";
	InOrder(tree[root].right, n);
}

int main()
{
	int n;
	cin >> n;
	bitset<11> appear;
	for (int i = 0; i < n; i++)
	{
		getchar();
		char c1, c2;
		c1 = getchar();
		getchar();
		c2 = getchar();
		if (c1 != '-')
		{
			tree[i].right = c1 - '0';
			appear.set(c1 - '0');
		}
		if (c2 != '-')
		{
			tree[i].left = c2 - '0';
			appear.set(c2 - '0');
		}
	}
	int root;
	for (int i = 0; i < n; i++)
		if (!appear[i])
			root = i;

	LevelOrder(root, n);
	InOrder(root, n);
}