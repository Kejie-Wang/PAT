#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int Msize;
bitset<11000> isinsert;

bool isPrime(int num)
{
    if (num == 2)
        return true;
    else if (num == 0 || num == 1 || num % 2 == 0)
        return false;
    int upper = sqrt(num);
    for (int i = 3; i <= upper; i++)
        if (num%i == 0)
            return false;
    return true;
}

void DecideSize()
{
    while (!isPrime(Msize))
        Msize++;
}

int HashFunction(int num)
{
    int index = num%Msize;
    int i = 0;
    while (isinsert[index])
    {
        index += (2 * i + 1);
        index %= Msize;
        if (index == num%Msize)
            return -1;
        i++;
    }
    isinsert.set(index);
    return index;
}

int main()
{
    int n;
    cin >> Msize >> n;
    DecideSize();
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int index = HashFunction(num);
        if (index == -1)
            cout << "-";
        else
            cout << index;
        if (i < n - 1)
            cout << " ";
    }
}