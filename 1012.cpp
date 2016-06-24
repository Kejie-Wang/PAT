#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Score
{
private:
	string id;
	int C, M, E, A;
	int CRank, MRank, ERank, ARank;
	int BestRank;
	char BestCourse;
public:
	friend bool Ccmp(const Score &s1, const Score &s2);
	friend bool Mcmp(const Score &s1, const Score &s2);
	friend bool Ecmp(const Score &s1, const Score &s2);
	friend bool Acmp(const Score &s1, const Score &s2);
	friend bool Idcmp(const Score &s1, const Score &s2);
	friend istream& operator>>(istream &is, Score &s);
	void SetCRank(int Rank){ CRank = Rank; }
	void SetMRank(int Rank){ MRank = Rank; }
	void SetERank(int Rank){ ERank = Rank; }
	void SetARank(int Rank){ ARank = Rank; }
	void SetBest();
	string GetId(){ return id; }
	int GetC(){ return C; }
	int GetM(){ return M; }
	int GetE(){ return E; }
	int GetA(){ return A; }
	int GetBestRank(){ return BestRank; }
	char GetBestCourse(){ return BestCourse; }
};

bool Ccmp(const Score &s1, const Score &s2)
{
	return s1.C > s2.C;
}
bool Mcmp(const Score &s1, const Score &s2)
{
	return s1.M > s2.M;
}
bool Ecmp(const Score &s1, const Score &s2)
{
	return s1.E > s2.E;
}
bool Acmp(const Score &s1, const Score &s2)
{
	return s1.A > s2.A;
}
bool Idcmp(const Score &s1, const Score &s2)
{
	return s1.id < s2.id;
}

istream& operator>>(istream &is, Score &s)
{
	is >> s.id >> s.C >> s.M >> s.E;
	s.A = (s.C + s.M + s.E) / 3;

	return is;
}

void Score::SetBest()
{
	if (ARank <= CRank&&ARank <= MRank&&ARank <= ERank)
	{
		BestRank = ARank;
		BestCourse = 'A';
	}
	else if (CRank <= MRank&&CRank <= ERank)
	{
		BestRank = CRank;
		BestCourse = 'C';
	}
	else if (MRank <= ERank)
	{
		BestRank = MRank;
		BestCourse = 'M';
	}
	else
	{
		BestRank = ERank;
		BestCourse = 'E';
	}
}

int find(string &id, vector<Score> &Scores, int left, int right)
{
	int middle = (left + right) / 2;

	if (left == right&&Scores[middle].GetId() != id)
		return -1;
	else if (Scores[middle].GetId() == id)
		return middle;
	else if (Scores[middle].GetId() > id)
		return find(id, Scores, left, middle);
	else
		return find(id, Scores, middle+1, right);
}

int main()
{
	vector<Score> Scores;
	Score tmp;
	int ScoreNum, QueryNum;
	
	cin >> ScoreNum >> QueryNum;
	while (ScoreNum--)
	{
		cin >> tmp;
		Scores.push_back(tmp);
	}
	int lastScore, lastRank;
	//set C-programming Rank
	lastScore = lastRank = -1;
	sort(Scores.begin(), Scores.end(), Ccmp);
	for (int i = 0; i < Scores.size(); i++)
	{
		if (Scores[i].GetC() == lastScore)
			Scores[i].SetCRank(lastRank);
		else
		{
			Scores[i].SetCRank(i + 1);
			lastScore = Scores[i].GetC();
			lastRank = i + 1;
		}
	}
	//set Mathematics rank
	lastScore = lastRank = -1;
	sort(Scores.begin(), Scores.end(), Mcmp);
	for (int i = 0; i < Scores.size(); i++)
	{
		if (Scores[i].GetM() == lastScore)
			Scores[i].SetMRank(lastRank);
		else
		{
			Scores[i].SetMRank(i + 1);
			lastScore = Scores[i].GetM();
			lastRank = i + 1;
		}
	}
	//set English Rank
	lastScore = lastRank = -1;
	sort(Scores.begin(), Scores.end(), Ecmp);
	for (int i = 0; i < Scores.size(); i++)
	{
		if (Scores[i].GetE() == lastScore)
			Scores[i].SetERank(lastRank);
		else
		{
			Scores[i].SetERank(i + 1);
			lastScore = Scores[i].GetE();
			lastRank = i + 1;
		}
	}
	//set average rank
	lastScore = lastRank = -1;
	sort(Scores.begin(), Scores.end(), Acmp);
	for (int i = 0; i < Scores.size(); i++)
	{
		if (Scores[i].GetA() == lastScore)
			Scores[i].SetARank(lastRank);
		else
		{
			Scores[i].SetARank(i + 1);
			lastScore = Scores[i].GetA();
			lastRank = i + 1;
		}
	}
	for (int i = 0; i < Scores.size(); i++)
		Scores[i].SetBest();
	sort(Scores.begin(), Scores.end(), Idcmp);
	
	for (int i = 0; i < QueryNum; i++)
	{
		string id;
		cin >> id;
		int index = find(id, Scores, 0, Scores.size()-1);
		if (index == -1)
			cout << "N/A";
		else
			cout << Scores[index].GetBestRank() << " " << Scores[index].GetBestCourse();
		if (i != QueryNum - 1)
			cout << endl;
	}
}