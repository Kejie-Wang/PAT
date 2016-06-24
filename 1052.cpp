#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node
{
	int address;
	int value;
	int next;
};

bool cmp(const Node& lhs, const Node& rhs)
{
	return lhs.value < rhs.value;
}

Node nodes[1000000];

int main()
{
	vector<Node> vec;
	int NodeNum, start;
	cin >> NodeNum >> start;

	for (int i = 0; i < NodeNum; i++)
	{
		Node tmp;
		cin >> tmp.address >> tmp.value >> tmp.next;
		nodes[tmp.address] = tmp;
	}
	int i = start;
	while (i != -1)
	{
		vec.push_back(nodes[i]);
		i = nodes[i].next;
	}

	sort(vec.begin(), vec.end(), cmp);
	cout << vec.size() << " ";
	for (int i = 0; i < vec.size(); i++)
	{
		printf("%.05d\n", vec[i].address);
		//cout << vec[i].address << endl;
		//cout << vec[i].address << " " << vec[i].value << " ";
		printf("%.05d %d ", vec[i].address, vec[i].value);
	}
	cout << -1;
}