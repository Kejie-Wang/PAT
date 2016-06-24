#include <iostream>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

set<string> title[10000];
set<string> author[10000];
set<string> keyword[1001];
set<string> publisher[1001];
set<string> year[2001];

int main()
{
    int recordNum;
    cin >> recordNum;
    getchar();
    int titleLast, authorLast, keywordLast, publisherLast, yearLast;
    titleLast = authorLast = keywordLast = publisherLast = yearLast = 0;
    map<string, int> titleIndex, authorIndex, keywordIndex, publisherIndex;
    for (int i = 0; i < recordNum; i++)
    {
        int y;
        string id, t, a, k, p;
        getline(cin, id);
        getline(cin, t);
        getline(cin, a);
        getline(cin, k);
        getline(cin, p);
        cin >> y;
        getchar();
        //title
        if (titleIndex.find(t) == titleIndex.end())
        {
            title[titleLast].insert(id);
            titleIndex[t] = titleLast++;
        }
        else
        {
            int index = titleIndex[t];
            title[index].insert(id);
        }
        //author
        if (authorIndex.find(a) == authorIndex.end())
        {
            author[authorLast].insert(id);
            authorIndex[a] = authorLast++;
        }
        else
        {
            int index = authorIndex[a];
            author[index].insert(id);
        }
        //keyword
        string key;
        stringstream ss;
        ss << k;
        while (ss >> key)
        {
            if (keywordIndex.find(key) == keywordIndex.end())
            {
                keyword[keywordLast].insert(id);
                keywordIndex[key] = keywordLast++;
            }
            else
            {
                int index = keywordIndex[key];
                keyword[index].insert(id);
            }
        }
        //publisher
        if (publisherIndex.find(p) == publisherIndex.end())
        {
            publisher[publisherLast].insert(id);
            publisherIndex[p] = publisherLast++;
        }
        else
        {
            int index = publisherIndex[p];
            publisher[index].insert(id);
        }
        //year
        year[y - 1000].insert(id);
    }

    int queryNum;
    string query;
    cin >> queryNum;
    getchar();
    for (int i = 0; i < queryNum; i++)
    {
        getline(cin, query);
        string key(query.begin() + 3, query.end());
        cout << query << endl;
        if (query[0] == '1')
        {
            if (titleIndex.find(key) == titleIndex.end())
                cout << "Not Found" << endl;
            else
            {
                int index = titleIndex[key];
                for (set<string>::iterator it = title[index].begin(); it != title[index].end();it++)
                    cout << *it << endl;
            }
        }
        else if (query[0] == '2')
        {
            if (authorIndex.find(key) == authorIndex.end())
                cout << "Not Found" << endl;
            else
            {
                int index = authorIndex[key];
                for (set<string>::iterator it = author[index].begin(); it != author[index].end(); it++)
                    cout << *it << endl;
            }
        }
        else if (query[0] == '3')
        {
            if (keywordIndex.find(key) == keywordIndex.end())
                cout << "Not Found" << endl;
            else
            {
                int index = keywordIndex[key];
                for (set<string>::iterator it = keyword[index].begin(); it != keyword[index].end(); it++)
                    cout << *it << endl;
            }
        }
        else if (query[0] == '4')
        {
            if (publisherIndex.find(key) == publisherIndex.end())
                cout << "Not Found" << endl;
            else
            {
                int index = publisherIndex[key];
                for (set<string>::iterator it = publisher[index].begin(); it != publisher[index].end(); it++)
                    cout << *it << endl;
            }
        }
        else
        {
            stringstream ss;
            int y;
            ss << key;
            ss >> y;
            if (y<1000 || y>3000 || year[y - 1000].size() == 0)
                cout << "Not Found" << endl;    
            else
            {
                for (set<string>::iterator it = year[y - 1000].begin(); it != year[y - 1000].end(); it++)
                    cout << *it << endl;
            }
        }
    }    
}