#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
	int address;
	int value;
	int next;
};

Node list[100000];

int main()
{
	int start, listNum, length;
	cin >> start >> listNum >> length;

	for (int i = 0; i < listNum; i++)
	{
		Node tmp;
		cin >> tmp.address >> tmp.value >> tmp.next;
		list[tmp.address] = tmp;
	}
	vector<Node> vec;
	int i = start, cnt = 0;
	Node* sublist = new Node[length];
	while (i != -1)
	{
		sublist[cnt] = list[i];
		cnt++;
		if (cnt == length)
		{
			for (int j = cnt-1; j>=0; j--)
				vec.push_back(sublist[j]);
			cnt = 0;
		}	
		i = list[i].next;
	}
	for (int j = 0; j < cnt; j++)
		vec.push_back(sublist[j]);
	
	printf("%.05d %d ", vec[0].address, vec[0].value);
	for (int i = 1; i < vec.size(); i++)
		printf("%.05d\n%.05d %d ", vec[i].address, vec[i].address, vec[i].value);
	printf("-1");
}