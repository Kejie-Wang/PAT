#include <iostream>
#include <algorithm>

using namespace std;

long long sequence[100000];
long long p;

int main()
{
    long long n;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    sort(sequence, sequence + n);
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxLength >= n - i)
            break;
        int left = i, right = n - 1;
        if (sequence[i] * p >= sequence[right] && maxLength < n - i)
            maxLength = n - i;
        else
        {
            while (right - left != 1)
            {
                int middle = (left + right) / 2;
                if (sequence[i] * p >= sequence[middle])
                    left = middle;
                else
                    right = middle;
            }
            if (right - i > maxLength)
                maxLength = right - i;
        }
    }
    cout << maxLength;
}