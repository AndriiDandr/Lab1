#include "money.h"
#include <iostream>

using namespace std;

void dodavanya(Money &money, const Money &addMoney){
    money.grn += addMoney.grn;
    money.cop += addMoney.cop;
}

void mnozhenya(Money &money, int count)
{
    int totalCop = (money.grn * 100 + money.cop) * count;

    money.grn = totalCop / 100;
    money.cop = totalCop % 100;
}

void okryglenya(Money &money) {
    int remainder = money.cop % 10;    
    money.cop = (money.cop / 10) * 10; 

    if (remainder >= 8) {
        money.cop += 10; 
    }
}


void printMoney(const Money &money){
    cout << money.grn << "grn " << money.cop << "cop"<<endl; 
}

void total(const char *path){
    FILE *file;
    int err = fopen_s(&file, path, "r");
    
    Money money = {0, 0};
    if(err == 0 && file != nullptr){
        char buffer[256];
        int grn;
        short int cop;
        int count;
        char product[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            if (sscanf(buffer, "%s %u %hu %u", product, &grn, &cop, &count) == 4) {
                if(count < 0 || grn < 0 || cop < 0){
                    cout << "Неправильний формат вводу"<< endl;
                    fclose(file);
                    return;
                }
                Money newMoney = {grn, cop};

                mnozhenya(newMoney, count);
                dodavanya(money, newMoney);
            }
            else{
                cout << "Неправильний формат вводу"<< endl;
                fclose(file);
                return;
            }
        }

        if(money.cop >= 100){
            int newGrn = money.cop / 100;
            money.grn += newGrn;
            money.cop %= 100;
        }

        cout << "Сума: ";
        printMoney(money); 
        okryglenya(money);  
        
        cout << "Заокруглення: ";
        printMoney(money); 
        
        fclose(file);
    }
    else{
        cout << "Помилка відкриття файлу: " << err << endl;
        return;
    }
}