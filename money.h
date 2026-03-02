#ifndef MONEY_H
#define MONEY_H
#include <iostream>

struct Money
{
    int grn;
    short int cop;
};

void dodavanya(Money *money, Money *addMoney), 
    mnozhenya(Money *money, int count), 
    okryglenya(Money *money), 
    printMoney(Money *money),
    total(const char *path);

#endif