#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Fraction
{
    long a;
    long b;
};

Fraction Add(const Fraction& lhs, const Fraction& rhs)
{
    Fraction sum;
    sum.b = lhs.b*rhs.b;
    sum.a = lhs.a*rhs.b + rhs.a*lhs.b;

    return sum;
}

Fraction Sub(const Fraction& lhs, const Fraction& rhs)
{
    Fraction neg = rhs;
    neg.a = -neg.a;
    
    return Add(lhs, neg);
}

Fraction Mul(const Fraction& lhs, const Fraction& rhs)
{
    Fraction mul;
    mul.a = lhs.a * rhs.a;
    mul.b = lhs.b * rhs.b;

    return mul;
}

Fraction Div(const Fraction& lhs, const Fraction& rhs)
{
    Fraction rev;
    rev.a = rhs.b;
    rev.b = rhs.a;
    

    return Mul(lhs, rev);
}

string Reduction(Fraction fra)
{
    long min = abs(fra.a) < abs(fra.b) ? abs(fra.a) : abs(fra.b);
    long max = abs(fra.a) > abs(fra.b) ? abs(fra.a) : abs(fra.b);

    if (fra.a == 0)
        return "0";
    else if (fra.b == 0)
        return "Inf";
    if (fra.b < 0)
    {
        fra.a = -fra.a;
        fra.b = -fra.b;
    }
    while (max%min != 0)
    {
        long tmp = min;
        min = max % min;
        max = tmp;            
    }
    fra.a /= min;
    fra.b /= min;
    stringstream ss;
    if (fra.b == 1)
        ss << fra.a;
    else if (abs(fra.a) < abs(fra.b))
        ss << fra.a << "/" << fra.b;
    else
        ss << fra.a / fra.b << " " << abs(fra.a)%fra.b << "/" << fra.b;
    if (fra.a < 0)
        return "(" + ss.str() + ")";
    return ss.str();
}

int main()
{
    Fraction lhs, rhs;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '/')
            s[i] = ' ';
    stringstream ss;
    ss << s;
    ss >> lhs.a >> lhs.b >> rhs.a >> rhs.b;

    cout << Reduction(lhs) << " + " << Reduction(rhs) << " = " << Reduction(Add(lhs, rhs)) << endl;
    cout << Reduction(lhs) << " - " << Reduction(rhs) << " = " << Reduction(Sub(lhs, rhs)) << endl;
    cout << Reduction(lhs) << " * " << Reduction(rhs) << " = " << Reduction(Mul(lhs, rhs)) << endl;
    cout << Reduction(lhs) << " / " << Reduction(rhs) << " = " << Reduction(Div(lhs, rhs)) << endl;
}