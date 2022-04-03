#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <QString>

using namespace std;


class rational
{
    static QChar SEPARATOR;

    int a;
    int b;
public:
    rational();
    rational(const int&);
    rational(double, double);
    rational(const QByteArray&);

    void NOD();
    friend ostream& operator<<(ostream&, rational);
    friend istream& operator>>(istream&, rational&);

    friend QString& operator<<(QString&, rational);
    friend QByteArray& operator>>(QByteArray&,rational&);

    friend rational sqrt(rational);
    friend rational abs(rational);
    rational operator*(rational);
    rational operator*(int);
    rational operator+(rational);
    bool operator==(rational);
    rational operator/(rational);
    bool operator>=(rational);
    bool operator<=(rational);
    bool operator<(rational);
    rational operator-();
    rational operator-(rational);
    operator QString ();
    static void setSeparator(QChar);

};

#endif // RATIONAN_H
