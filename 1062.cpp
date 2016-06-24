#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct MenInfo
{
	string id;
	int virtue;
	int talent;
};

int upper, bound;

int Rank(const MenInfo& men)
{
	if (men.talent >= upper&&men.virtue >= upper)	//sages
		return 1;
	else if (men.virtue >= upper)	//nobleman
		return 2;
	else if (men.virtue >= men.talent)	//fool men
		return 3;
	else
		return 4;
}

bool cmp(const MenInfo& m1, const MenInfo& m2)
{
	if (Rank(m1) == Rank(m2))
	{
		if (m1.virtue + m1.talent == m2.virtue + m2.talent&&m1.virtue == m2.virtue)
			return m1.id < m2.id;
		else if (m1.virtue + m1.talent == m2.virtue + m2.talent)
			return m1.virtue > m2.virtue;
		else
			return m1.virtue + m1.talent > m2.virtue + m2.talent;
	}
	else
		return Rank(m1) < Rank(m2);
}

int main()
{
	int recordNum;
	cin >> recordNum >> bound >> upper;
	vector<MenInfo> vec;

	for (int i = 0; i < recordNum; i++)
	{
		MenInfo men;
		char s[9];
		scanf("%s%d%d", s, &men.virtue, &men.talent);
		men.id = string(s);
		//cin >> men.id >> men.virtue >> men.talent;
		if (men.virtue >= bound&&men.talent >= bound)
			vec.push_back(men);
	}
	sort(vec.begin(), vec.end(), cmp);
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++)
		printf("%s %d %d\n", vec[i].id.c_str(), vec[i].virtue, vec[i].talent);
		//cout << vec[i].id << " " << vec[i].virtue << " " << vec[i].talent << endl;
}