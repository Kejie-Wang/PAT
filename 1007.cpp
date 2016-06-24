#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;
	while (n--)
	{
		int num;
		cin >> num;
		vec.push_back(num);
	}

	int max = 0, endMax = 0;
	int start_max = 0, end_max = 0;
	int start_endMax = 0, end_endMax = 0;

	for (int i = 0; i<vec.size(); i++)
	{
		//update the endMax
		if (endMax < 0 || i == 0)
		{
			endMax = vec[i];
			start_endMax = vec[i];
			end_endMax = vec[i];
		}
		else
		{
			endMax += vec[i];
			end_endMax = vec[i];
		}

		//update the max
		if (endMax > max)
		{
			max = endMax;
			start_max = start_endMax;
			end_max = end_endMax;
		}
	}
	
	if (*max_element(vec.begin(), vec.end()) < 0)
	{
		start_max = vec.front();
		end_max = vec.back();
	}

	cout << max << " " << start_max << " " << end_max;
}