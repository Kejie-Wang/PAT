#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct Applicant
{
    int id;
    int EGrade;
    int IGrade;
    double final;
    int choice[6];
    int rank;
};

Applicant applicants[40000];

bool cmp(const Applicant& lhs, const Applicant& rhs)
{
    if (lhs.final == rhs.final)
        return lhs.EGrade > rhs.EGrade;
    return lhs.final > rhs.final;
}

int main()
{
    int applicantNum, schoolNum, choiceNum;
    cin >> applicantNum >> schoolNum >> choiceNum;
    int quota[100];
    for (int i = 0; i < schoolNum; i++)
        cin >> quota[i];
    for (int i = 0; i < applicantNum; i++)
    {
        applicants[i].id = i;
        cin >> applicants[i].EGrade >> applicants[i].IGrade;
        applicants[i].final = (applicants[i].EGrade + applicants[i].IGrade) / 2.0;
        for (int j = 0; j < choiceNum; j++)
            cin >> applicants[i].choice[j];
    }
    sort(applicants, applicants + applicantNum, cmp);
    //set the rank of the all applicants
    int final=0, EGrade=0, rank = 1;
    for (int i = 0; i < applicantNum; i++)
    {
        if (applicants[i].final == final&&applicants[i].EGrade == EGrade)
            applicants[i].rank = rank;
        else
        {
            final = applicants[i].final;
            EGrade = applicants[i].EGrade;
            rank = i + 1;
            applicants[i].rank = rank;
        }
    }
    bitset<100000> empty;
    vector<int> vec[100];
    for (int i = 0; i < schoolNum; i++)
        if (quota[i] <= 0)
            empty.set(i);
    int i = 0;
    rank = 1;
    while (1)
    {
        //admit the applicants with same rank
        while (i < applicantNum&&applicants[i].rank == rank)
        {
            for (int j = 0; j < choiceNum; j++)
            {
                if (!empty[applicants[i].choice[j]])
                {
                    quota[applicants[i].choice[j]]--;
                    vec[applicants[i].choice[j]].push_back(applicants[i].id);
                    break;
                }
            }
            i++;
        }
        if (i == applicantNum)
            break;
        else
            rank = applicants[i].rank;    //next rank
    
        for (int j = 0; j < schoolNum; j++)
            if (quota[j] <= 0)
                empty.set(j);
    }
    for (int i = 0; i < schoolNum; i++)
    {
        sort(vec[i].begin(), vec[i].end());
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
            if (j < vec[i].size() - 1)
                cout << " ";
        }
        cout << endl;
    }
}