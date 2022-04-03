#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>
#include <QString>

using namespace std;


enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

struct root
{
    number x1;
    number x2;
    int flag;
};



class TPolinom
{
    number a, b, c;
    EPrintMode printMode;
public:
    TPolinom(number, number, number);
    friend ostream& operator<< (ostream&, TPolinom&);
    number value(number);
    void setPrintMode(EPrintMode);
    root roots();
    void printRoots(struct root);

    friend QString& operator<< (QString&, TPolinom&);

};

#endif // TPOLINOM_H
