#include <iostream>
#include <string>

using namespace std;

int CalculateRadix(string &num)
{
    int i = 0;
    while (i < num.size())
    {
        if (num[i] == '.')
        {
            num.erase(i, 1);
            break;
        }
        i++;
    }

    return i;
}

int erasezero(string &num)
{
    int cnt = 0;
    string::iterator it = num.begin();
    while (it!=num.end()&& (*it) == '0')
    {
        it = num.erase(it);
        cnt++;
    }
    return cnt;
}

string CalculateCoeff(string num, int significantNum, int &radix)
{
    string coeff;
    radix -= erasezero(num);
    if (num.empty())
        radix = 0;
    if (num.size() >= significantNum)
        coeff.assign(num.begin(), num.begin() + significantNum);
    else
        coeff = num + string(significantNum - num.size(), '0');

    return "0." + coeff;
}

int main()
{
    string num1, num2;
    int significantNum;
    cin >> significantNum >> num1 >> num2;

    int radix1, radix2;
    radix1 = CalculateRadix(num1);
    radix2 = CalculateRadix(num2);
    
    string coeff1 = CalculateCoeff(num1, significantNum, radix1);
    string coeff2 = CalculateCoeff(num2, significantNum, radix2);

    if (coeff1 == coeff2&&radix1 == radix2)
        cout << "YES" << " " << coeff1 << "*10^" << radix1;
    else
        cout << "NO" << " " << coeff1 << "*10^" << radix1 << " " << coeff2 << "*10^" << radix2;
}