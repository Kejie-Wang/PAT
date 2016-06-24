#include <iostream>
#include <cstring>
#include <list>
#include <queue>

using namespace std;

list<int> userList[1001];
int userlevel[10001];
int cnt;
int l;

void BFS(int start)
{
	queue<int> que;
	que.push(start);
	userlevel[start] = 0;
	while (!que.empty())
	{
		int user = que.front();
		que.pop();
		if (userlevel[user] < l)
		{
			list<int>::iterator it = userList[user].begin();
			while (it != userList[user].end())
			{
				if (userlevel[*it] == -1)
				{
					userlevel[*it] = userlevel[user] + 1;
					que.push(*it);
					cnt++;
				}
				it++;
			}
		}
	}
}

int main()
{
	int userNum;
	cin >> userNum >> l;

	for (int i = 1; i <= userNum; i++)
	{
		int followerNum;
		cin >> followerNum;
		for (int j = 0; j < followerNum; j++)
		{
			int follower;
			cin >> follower;
			userList[follower].insert(userList[follower].begin(), i);
		}
	}
	int queryNum;
	cin >> queryNum;
	for (int i = 0; i < queryNum; i++)
	{
		int root;
		cin >> root;
		memset(userlevel, -1, (userNum + 1)*sizeof(int));
		cnt = 0;
		BFS(root);
		cout << cnt << endl;
	}
}