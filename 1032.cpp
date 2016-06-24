#include <iostream>

using namespace std;

struct Node
{
	char data;
	int nextIndex;
	bool isVisited = false;
};

Node words[1000000];

int main()
{
	int start1, start2, nodeNum;
	cin >> start1 >> start2 >> nodeNum;

	for (int i = 0; i < nodeNum; i++)
	{
		int address, next;
		char data;
		cin >> address >> data >> next;
		words[address].data = data;
		words[address].nextIndex = next;
	}
	int i = start1;
	while (i != -1)
	{
		words[i].isVisited = true;
		i = words[i].nextIndex;
	}
	i = start2;
	while (i != -1)
	{
		if (words[i].isVisited)
			break;
		i = words[i].nextIndex;
	}
	if (i == -1)
		printf("-1");
	else
		printf("%.05d", i);
}