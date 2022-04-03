#include "rational.h"
#include <QtMath>
#include "common.h"

QChar rational::SEPARATOR = separator;

rational::rational()
{
    a = 1;
    b = 1;
}


rational::rational(const int& i)
{
    a = i;
    b = 1;
}

rational::rational(double i, double j)
{
    a = i;
    b = j;
    NOD();
}


void rational::NOD()
{
    int aa = abs(a);
    int bb = abs(b);
    int nod = 0;
    while(aa > 0 && bb > 0)

            if(aa > bb)
                aa %= bb;

            else
                bb %= aa;
    nod = aa+bb;
    a = a / nod;
    b = b / nod;
}

ostream& operator<<(ostream& os, rational r)
{
    os<<"("<<r.a<<"/"<<r.b<<")";
    return os;
}

istream& operator>>(istream& is, rational& r)
{
    is>>r.a>>r.b;
    while (r.b <= 0)
    {
        cout << "please write b > 0" << endl;
        is>>r.a>>r.b;
    }
    r.NOD();
    return is;
}

rational::rational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    a = arr.left(p).toDouble();
    b = arr.right(arr.length()-p-1).toDouble();
}

QByteArray& operator>>(QByteArray& arr, rational& c)
{
    int p = arr.indexOf(rational::SEPARATOR);
    p = arr.indexOf(rational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = rational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

QString& operator<<(QString& s, rational r)
{
    s += "(" ;
    s += QString().setNum(r.a);
    s +="/";
    s += QString().setNum (r.b);
    s+= ")";
    return s;
}

rational abs(rational r)
{
    r.a = abs(r.a);
    return r;
}

rational sqrt(rational r)
{
    r.a = sqrt(r.a);
    r.b = sqrt(r.b);
    return r;
}

rational rational::operator*(rational r)
{
    rational s;
    s.a = a * r.a;
    s.b = b * r.b;
    s.NOD();
    return s;
}

rational rational::operator*(int i)
{
    rational r;
    r.a = a * i;
    r.b = b;
    r.NOD();
    return r;
}

rational rational::operator/(rational r)
{
    rational s;
    s.a = a * r.b;
    s.b = b * r.a;
    s.NOD();
    return s;
}

rational rational::operator+(rational r)
{
    rational s;
    s.a = a*r.b+b*r.a;
    s.b = b*r.b;
    s.NOD();
    return s;
}

bool rational::operator==(rational r)
{
    return (a == r.a && b == r.b);
}

bool rational::operator>=(rational r)
{
    return (a*r.b >= r.a*b);
}

bool rational::operator<=(rational r)
{
    return (a*r.b <= r.a*b);
}

bool rational::operator<(rational r)
{
    return (a*r.b < r.a*b);
}

rational rational::operator-()
{
    rational r;
    r.a = -a;
    r.b = b;
    return r;
}

rational rational::operator-(rational r)
{
    rational s;
    s.a = a*r.b-b*r.a;
    s.b = b*r.b;
    s.NOD();
    return s;
}

rational::operator QString ()
{
    QString s = "(";
    s += QString().setNum(a);
    s += "/";
    s += QString().setNum(b);
    s += ")";
    return s;
}

void rational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}


