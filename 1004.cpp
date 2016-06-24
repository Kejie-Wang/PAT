#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

void FindLevel(map<string, vector<string>> &FamilyTree, string root, int rootlevel, int level[])
{

	if (FamilyTree.find(root) == FamilyTree.end())
	{
		level[rootlevel]++;
		return;
	}
	else
	{
		vector<string>::iterator it;
		it = FamilyTree[root].begin();
		while (it != FamilyTree[root].end())	//for every child of the root
		{
			FindLevel(FamilyTree, *it, rootlevel + 1, level);
			it++;
		}
	}

}

int main()
{
	int NodeNum, Non_leaf;
	map<string, vector<string> > FamilyTree;	
	int childnum;
	int level[100];
	memset(level, 0, sizeof(int) * 100);

	//construct the family tree
	cin >> NodeNum >> Non_leaf;
	for (int i = 0; i<Non_leaf; i++)
	{
		string parent, child;
		vector<string> children;
		cin >> parent >> childnum;
		for (int j = 0; j<childnum; j++)
		{
			cin >> child;
			children.push_back(child);
		}
		FamilyTree[parent] = children;
	}

	FindLevel(FamilyTree, "01", 0, level);

	int maxlevel = 0;
	for (int i = 0; i<100; i++)
		if (level[i] != 0)
			maxlevel = i;
	for (int i = 0; i <= maxlevel; i++)
	{
		cout << level[i];
		if(i<maxlevel)
			cout << " ";
	}
}