#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	string id;
	int grade;
};

bool cmp(const Student& s1, const Student& s2)
{
	return s1.grade > s2.grade;
}

vector<Student> students(101);

int main()
{
	int stuNum;
	cin >> stuNum;

	for (int i = 0; i < stuNum; i++)
		cin >> students[i].name >> students[i].id >> students[i].grade;
	sort(students.begin(), students.end(), cmp);
	int grade1, grade2;
	cin >> grade1 >> grade2;
	bool flag = false;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].grade >= grade1&&students[i].grade <= grade2)
		{
			cout << students[i].name << " " << students[i].id << endl;
			flag = true;
		}
		if (students[i].grade < grade1)
			break;
	}
	if (!flag)
		cout << "NONE";

}