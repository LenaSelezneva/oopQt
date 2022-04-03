#include "polinom.h"
#include <QtMath>

TPolinom::TPolinom(number x, number y, number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}

ostream& operator<< (ostream& os, TPolinom& p)
{
    struct root r;
    r = p.roots();
    if (p.printMode == EPrintModeClassic)
    {
        char s2='-', s3='-';
        if (p.b >= 0)
            s2 = '+';
        if (p.c >= 0)
            s3 = '+';
        os<<p.a<<"x^2"<<s2<<abs(p.b)<<"x"<<s3<<abs(p.c);
    }
    else
    {
        if(r.flag == 0)
        {
            char s1='-', s2='-';
            if (r.x1 < 0)
                s1 = '+';
            if (r.x2 < 0)
                s2= '+';
            if (r.x1 == r.x2)
                os<<p.a<<"(x"<<s1<<abs(r.x1)<<")^2"<<endl;
            else
                os<<p.a<<"(x"<<s1<<abs(r.x1)<<")(x"<<s2<<abs(r.x2)<<")"<<endl;
        }
        else
            os<<"no such form, because of no roots";
    }
    return os;
}

number TPolinom::value(number x)
{
    return a*x*x+b*x+c;
}

void TPolinom::setPrintMode(EPrintMode m)
{
    printMode = m;
}

root TPolinom::roots()
{
    number d;
    struct root r;
    d = b * b - a * c * 4;
    if (d >= 0)
    {     
            r.x1 = ((-b) + sqrt(d)) / (a * 2);
            r.x2 = ((-b) - sqrt(d)) / (a * 2);
            if (value(r.x1) == 0 && value(r.x2) == 0)
            {
                r.flag = 0;
                return r;
            }
            else
            {
                r.flag = -1;
                return r;
            }
    }
    else
    {
        r.flag = -1;
        return r;
    }
}

void TPolinom::printRoots(struct root r)
{
    if (r.flag == 0)
    {
        cout << "x1 = " << r.x1 <<endl;
        cout << "x2 = " << r.x2 <<endl;
    }
    else
        cout << "no roots"<<endl;
}

QString& operator<< (QString& s, TPolinom& p)
{
    struct root r;
    r = p.roots();
    if (p.printMode == EPrintModeClassic)
    {
        char s2='-', s3='-';
        if (p.b >= 0)
            s2 = '+';
        if (p.c >= 0)
            s3 = '+';
        s << p.a;
        s += "x^2";
        s += s2;
        s << abs(p.b);
        s += "x";
        s += s3;
        s << abs(p.c);
    }
    else
    {
        if(r.flag == 0)
        {
            char s1='-', s2='-';
            if (r.x1 < 0)
                s1 = '+';
            if (r.x2 < 0)
                s2= '+';
            if (r.x1 == r.x2){
                s << p.a;
                s += "(x";
                s += s1;
                s << abs(r.x1);
                s += ")^2";
            }
            else
            {
                s << p.a;
                s += "(x";
                s += s1;
                s << abs(r.x1);
                s += ")(x";
                s += s2;
                s << abs(r.x2);
                s += ")";
            }
        }
        else
            s = "no such form, because of no roots";
    }
    return s;
}
