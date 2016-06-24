#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int value;
	int left = -1;
	int right = -1;
};

Node tree[100];
int num[100];
int cnt = 0;

void PreTraversal(int root)	//use preorder traversal to set the value
{
	if (root == -1)
		return;
	PreTraversal(tree[root].left);
	tree[root].value = num[cnt++];
	PreTraversal(tree[root].right);
}

void levelTraversal(int root)
{
	queue<int> que;
	que.push(root);
	while (!que.empty())
	{
		int index = que.front();
		que.pop();
		if (index != root)
			cout << " ";
		cout << tree[index].value;
		if (tree[index].left != -1)
			que.push(tree[index].left);
		if (tree[index].right != -1)
			que.push(tree[index].right);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tree[i].left >> tree[i].right;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);

	PreTraversal(0);
	levelTraversal(0);
}