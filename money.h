#ifndef MONEY_H
#define MONEY_H
#include <iostream>

struct Money 
{
    int grn;
    short int cop;
};

void dodavanya(Money &money, const Money &addMoney);
void mnozhenya(Money &money, int count);
void okryglenya(Money &money);
void printMoney(const Money &money);
void total(const char *path);

#endif