#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> preOrder;

void PreTraversal(int root)
{
	if (root > n)
		return;
	PreTraversal(2 * root);
	preOrder.push_back(root);
	PreTraversal(2 * root + 1);
}

int main()
{
	cin >> n;

	int num[1001], levelOrder[1001];
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);
	PreTraversal(1);
	for (int i = 0; i < preOrder.size(); i++)
		levelOrder[preOrder[i]] = num[i];
	for (int i = 1; i < n; i++)
		cout << levelOrder[i] << " ";
	cout << levelOrder[n];
		
}