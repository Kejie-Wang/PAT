#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	string id;
	int score;
};

bool cmp(Student s1, Student s2)
{
	return s1.score < s2.score;
}

int main()
{
	int stuNum;
	cin >> stuNum;
	vector<Student> male, female;
	for (int i = 0; i < stuNum; i++)
	{
		Student stu;
		char gender;
		cin >> stu.name >> gender >> stu.id >> stu.score;
		if (gender == 'M')
			male.push_back(stu);
		else
			female.push_back(stu);
	}
	sort(male.begin(), male.end(), cmp);
	sort(female.begin(), female.end(), cmp);
	if (female.empty())
		cout << "Absent" << endl;
	else
		cout << female.back().name << " " << female.back().id << endl;
	if (male.empty())
		cout << "Absent" << endl;
	else
		cout << male.front().name << " " << male.front().id << endl;
	if (female.empty() || male.empty())
		cout << "NA";
	else
		cout << female.back().score - male.front().score;

}