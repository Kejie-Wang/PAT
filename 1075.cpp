#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

struct User
{
	int id=0;
	int scores[6];
	bitset<6> submit;
	int num = 0;
	int totalscore = 0;
	int rank;
	bool pass = false;
};

bool cmp(const User& u1, const User& u2)
{
	if (u1.totalscore == u2.totalscore&&u1.num == u2.num)
		return u1.id < u2.id;
	else if (u1.totalscore == u2.totalscore)
		return u1.num > u2.num;
	else
		return u1.totalscore > u2.totalscore;
}
User users[10001];

int main()
{
	int UserNum, problemNum, submissionNum;
	int fullScores[6], full = 0;
	cin >> UserNum >> problemNum >> submissionNum;
	for (int i = 1; i <= problemNum; i++)
	{
		cin >> fullScores[i];
		full += fullScores[i];
	}

	for (int i = 0; i < submissionNum; i++)
	{
		int id, problemIndex, score;
		cin >> id >> problemIndex >> score;
		if (users[id].id == 0)	//first submission to initialize the id
			users[id].id = id;	
		if (score == fullScores[problemIndex] && score > users[id].scores[problemIndex])
			users[id].num++;
		if (users[id].scores[problemIndex] < score)	//submit a higher score and update the score
		{
			users[id].totalscore += (score - users[id].scores[problemIndex]);
			users[id].scores[problemIndex] = score;
		}
		if (score != -1)
			users[id].pass = true;
		users[id].submit.set(problemIndex);
	}
	vector<User> vec;
	for (int i = 0; i < 10001; i++)
	{
		if (users[i].pass)
			vec.push_back(users[i]);
	}
	sort(vec.begin(),vec.end(), cmp);

	int score = full, rank = 1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].totalscore == score)
			vec[i].rank = rank;
		else
		{
			vec[i].rank = i + 1;
			rank = i + 1;
			score = vec[i].totalscore;
		}
	}
	for (int i = 0; i < vec.size(); i++)
	{
		printf("%d %.5d %d ", vec[i].rank, vec[i].id, vec[i].totalscore);
		for (int j = 1; j <= problemNum; j++)
		{
			if (vec[i].submit[j])
				cout << vec[i].scores[j];
			else
				cout << "-";
			if (j < problemNum)
				cout << " ";
			else
				cout << endl;
		}	
	}
}