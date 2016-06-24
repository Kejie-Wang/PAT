#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Student
{
private:
	char id[7];
	char name[9];
	int grade;
public:
	friend bool cmp(const Student& s1, const Student& s2);
	void read(){ scanf("%s%s%d", id, name, &grade); }
	void output(){ printf("%s %s %d", id, name, grade); }
	int GetGrade(){ return grade; }
};

int column;
Student students[100001];

bool cmp(const Student& s1, const Student& s2)
{
	if (column == 1)
		return strcmp(s1.id, s2.id) < 0;
	else if (column == 2)
	{
		if (strcmp(s1.name, s2.name))
			return strcmp(s1.name, s2.name) < 0;
		else
			return strcmp(s1.id, s2.id) < 0;
	}
	else
	{
		if (s1.grade != s2.grade)
			return s1.grade < s2.grade;
		else 
			return strcmp(s1.id, s2.id) < 0;
	}
}

int main()
{
	int recordNum;
	cin >> recordNum >> column;

	for (int i = 0; i < recordNum; i++)
	{
		Student stu;
		stu.read();
		students[i] = stu;
	}
	
	sort(students, students + recordNum, cmp);
	for (int i = 0; i < recordNum; i++)
	{
		students[i].output();
		if (i < recordNum - 1)
			cout << endl;
	}
}
