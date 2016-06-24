#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
private:
	string registerNum;
	int score;
	int finalRank;
	int localRank;
	int locationNum;
public:
	Student(){};
	~Student(){};
	friend bool cmp(const Student& s1, const Student& s2);
	friend bool OutCmp(const Student& s1, const Student& s2);
	friend istream& operator>>(istream& is, Student& stu);
	friend ostream& operator<<(ostream& os, const Student& stu);
	void SetLocalRank(int rank){ localRank = rank; }
	void SetLocationNum(int num){ locationNum = num; }
	void SetFinalRank(int rank){ finalRank = rank; }
	int GetScore(){ return score; }
};

//the compare of the score
bool cmp(const Student& s1, const Student& s2)
{
	return s1.score > s2.score;
}

//the compare of the output
bool OutCmp(const Student& s1, const Student& s2)
{
	if (s1.finalRank == s2.finalRank)
		return s1.registerNum < s2.registerNum;
	else
		return s1.finalRank < s2.finalRank;
}

//input the testee information
istream& operator>>(istream& is, Student& stu)
{
	is >> stu.registerNum >> stu.score;

	return is;
}

//output the testee information
ostream& operator<<(ostream& os, const Student& stu)
{
	os << stu.registerNum << " " << stu.finalRank << " " << stu.locationNum << " " << stu.localRank;

	return os;
}

int main()
{
	int locationNum;
	cin >> locationNum;
	vector<Student> final;

	for (int i = 1; i <= locationNum; i++)
	{
		int StuNum;
		cin >> StuNum;
		vector<Student> local;

		for (int j = 0; j < StuNum; j++)
		{
			Student stu;
			cin >> stu;
			stu.SetLocationNum(i);
			local.push_back(stu);
		}
		//set the rank of single local room rank
		sort(local.begin(), local.end(), cmp);
		int score = 101;
		int rank = 0;
		for (int j = 0; j < local.size(); j++)
		{
			if (local[j].GetScore() < score)
			{
				local[j].SetLocalRank(j + 1);
				score = local[j].GetScore();
				rank = j + 1;
			}
			else 
				local[j].SetLocalRank(rank);
		}
		final.insert(final.begin(), local.begin(), local.end());
	}
	//set the final rank
	sort(final.begin(), final.end(), cmp);
	int score = 101;
	int rank = 0;
	for (int i = 0; i < final.size(); i++)
	{
		if (final[i].GetScore() < score)
		{
			final[i].SetFinalRank(i + 1);
			score = final[i].GetScore();
			rank = i + 1;
		}
		else
			final[i].SetFinalRank(rank);

	}
	sort(final.begin(), final.end(), OutCmp);
	cout << final.size() << endl;
	for (int i = 0; i < final.size(); i++)
	{
		cout << final[i];
		if (i < final.size() - 1)
			cout << endl;
	}
}