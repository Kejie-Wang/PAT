#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void count(map<string, vector<string>> &tree, map<string, unsigned int> &generation, string &root)
{
	int rootgeneration = generation[root];
	vector<string> child;
	if (tree.find(root) != tree.end())
		child = tree[root];
	else
		return;

	for (int i = 0; i<child.size(); i++)
	{
		string everychild = child[i];

		generation[everychild] = rootgeneration + 1;
		count(tree, generation, everychild);
	}

}


int main()
{
	int MemberNum, ParenentNum;
	map<string, vector<string>> tree;
	map<string, unsigned int> generation;
	int result[100];
	int maxnum = 0, maxgeneration = 0;

	for (int i = 0; i<100; i++)
		result[i] = 0;
	generation["01"] = 1;
	cin >> MemberNum >> ParenentNum;

	for (int i = 0; i<ParenentNum; i++)
	{
		string parent, child;
		int ChildNum;
		vector<string> v;

		cin >> parent >> ChildNum;
		for (int j = 0; j < ChildNum; j++)
		{
			cin >> child;
			v.push_back(child);
		}

		tree[parent] = v;
	}

	string root = "01";
	count(tree, generation, root);

	map<string, unsigned int>::iterator it;

	for (it = generation.begin(); it != generation.end(); it++)
		result[it->second]++;

	for (int i = 0; i<100; i++)
	{
		if (result[i]>maxnum)
		{
			maxnum = result[i];
			maxgeneration = i;
		}
	}

	cout << maxnum <<" "<< maxgeneration;
}