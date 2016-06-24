#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class HPrecision
{
private:
    std::string num;
public:
    HPrecision(){}
    ~HPrecision(){}
    HPrecision(std::string num){ this->num = num; }
    HPrecision(long long integer);
    HPrecision& operator=(const HPrecision &hp){ this->num = hp.num; return *this; }
    friend std::istream& operator>>(std::istream &is, HPrecision &in);
    friend std::ostream& operator<<(std::ostream &os, const HPrecision &out);
    friend HPrecision operator+(const HPrecision &lhs, const HPrecision &rhs);
    friend HPrecision operator-(const HPrecision &lhs, const HPrecision &rhs);
    friend HPrecision operator*(const HPrecision &lhs, const HPrecision &rhs);
    friend HPrecision operator/(const HPrecision &lhs, const HPrecision &rhs);
    HPrecision& operator+=(const HPrecision &hp){ *this = *this + hp; return *this; }
    HPrecision& operator-=(const HPrecision &hp){ *this = *this - hp; return *this; }
    friend bool operator<(const HPrecision &lhs, const HPrecision &rhs);
    friend bool operator<=(const HPrecision &lhs, const HPrecision &rhs);
    friend bool operator>(const HPrecision &lhs, const HPrecision &rhs);
    friend bool operator>=(const HPrecision &lhs, const HPrecision &rhs);
    friend bool operator==(const HPrecision &lhs, const HPrecision &rhs);
    friend bool operator!=(const HPrecision &lhs, const HPrecision &rhs);
    HPrecision reverse();
};

HPrecision::HPrecision(long long integer)
{
    std::stringstream ss;
    ss << integer;
    this->num = ss.str();
}

std::istream& operator>>(std::istream &is, HPrecision &in)
{
    is >> in.num;
    return is;
}

std::ostream& operator<<(std::ostream &os, const HPrecision &out)
{
    os << out.num;
    return os;
}

HPrecision operator+(const HPrecision &lhs, const HPrecision &rhs)
{
    HPrecision sum;
    HPrecision op1, op2;
    op1 = lhs;
    op2 = rhs;

    if (op1.num[0] == '-'&&op2.num[0] == '-')    //all negative
    {
        op1.num.erase(op1.num.begin());
        op2.num.erase(op2.num.begin());
        sum = op1 + op2;
        sum.num = std::string("-") + sum.num;
        return sum;
    }
    else if (op1.num[0] == '-')    //left operand is negative
    {
        op1.num.erase(op1.num.begin());
        return op2 - op1;
    }
    else if (op2.num[0] == '-')    //right operand is negative
    {
        op2.num.erase(op2.num.begin());
        return op1 - op2;
    }

    int i = op1.num.size() - 1;
    int j = op2.num.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0 && j >= 0)
        {
            int sumdigit;
            sumdigit = (op1.num[i] - '0') + (op2.num[j] - '0') + carry;
            sum.num = std::string(1, sumdigit % 10 + '0') + sum.num;
            carry = sumdigit / 10;
            i--;
            j--;
        }
        else if (i >= 0)
        {
            int sumdigit;
            sumdigit = (op1.num[i] - '0') + carry;
            sum.num = std::string(1, sumdigit % 10 + '0') + sum.num;
            carry = sumdigit / 10;
            i--;
        }
        else
        {
            int sumdigit;
            sumdigit = (op2.num[j] - '0') + carry;
            sum.num = std::string(1, sumdigit % 10 + '0') + sum.num;
            carry = sumdigit / 10;
            j--;
        }
    }
    if (carry != 0)
        sum.num = std::string("1") + sum.num;

    return sum;
}

HPrecision operator-(const HPrecision &lhs, const HPrecision &rhs)
{
    HPrecision diff;
    HPrecision op1, op2;
    op1 = lhs;
    op2 = rhs;

    if (op1.num[0] == '-'&&op2.num[0] == '-')    //all negative
    {
        op1.num.erase(op1.num.begin());
        op2.num.erase(op2.num.begin());
        return op2 - op1;
    }
    else if (op1.num[0] == '-')    //left operand is negative
    {
        op1.num.erase(op1.num.begin());
        diff = op2 + op1;
        diff.num = std::string("-") + diff.num;
        return diff;
    }
    else if (op2.num[0] == '-')    //right operand is negative
    {
        op2.num.erase(op2.num.begin());
        return op1 + op2;
    }
    if (op1.num.size() < op2.num.size() || (op1.num.size() == op2.num.size() && op1.num < op2.num))    //small - big
    {
        diff = op2 - op1;
        diff.num = std::string("-") + diff.num;
        return diff;
    }
    if (op1.num == op2.num)
        return HPrecision(std::string("0"));

    while (op2.num.size() < op1.num.size())
        op2.num = std::string("0") + op2.num;
    int borrow = 0;
    int i = op1.num.size() - 1;
    while (i >= 0)
    {
        int diffdigit;
        diffdigit = op1.num[i] - op2.num[i] - borrow;
        if (diffdigit < 0)
        {
            diffdigit += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        diff.num = std::string(1, diffdigit + '0') + diff.num;
        i--;
    }
    std::string::iterator it = diff.num.begin();
    while (*it == '0')
        diff.num.erase(it);

    return diff;
}

HPrecision operator*(const HPrecision &lhs, const HPrecision &rhs)
{
    HPrecision mul = 0;
    HPrecision op1, op2;
    op1 = lhs; op2 = rhs;
    if (op1.num[0] == '-'&&op2.num[0] == '-')    //all negative
    {
        op1.num.erase(op1.num.begin());
        op2.num.erase(op2.num.begin());
        return op1 * op2;
    }
    else if (op1.num[0] == '-')    //left operand is negative
    {
        op1.num.erase(op1.num.begin());
        mul = op1 * op2;
        mul.num = std::string("-") + mul.num;
        return mul;
    }
    else if (op2.num[0] == '-')    //right operand is negative
    {
        op2.num.erase(op2.num.begin());
        mul = op1 * op2;
        mul.num = std::string("-") + mul.num;
        return mul;
    }
    int i = 0;
    while (i < op2.num.size())
    {

        HPrecision tmp = 0;
        for (int j = '0'; j < op2.num[i]; j++)
            tmp += op1;

    }
}

bool operator<(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num < rhs.num;
}
bool operator<=(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num <= rhs.num;
}
bool operator>(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num > rhs.num;
}
bool operator>=(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num >= rhs.num;
}
bool operator==(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num == rhs.num;
}
bool operator!=(const HPrecision &lhs, const HPrecision &rhs)
{
    return lhs.num != rhs.num;
}

HPrecision HPrecision::reverse()
{
    std::string num = this->num;

    std::string reversenum;
    reversenum.assign(num.rbegin(), num.rend());

    return HPrecision(reversenum);
}
bool Is_Palindromic(HPrecision num)
{
    HPrecision reversenum = num.reverse();
    if (reversenum == num)
        return true;
    return false;
}
int main()
{
    HPrecision num;
    int steps;
    cin >> num >> steps;

    for (int i = 0; i < steps; i++)
    {
        if (Is_Palindromic(num))
        {
            cout << num << "\n" << i;
            return 0;
        }
        num = num.reverse() + num;
    }
    cout << num << "\n" << steps;
}