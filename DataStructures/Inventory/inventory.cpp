#include <stdio.h>
#include "inventory.h"

void format(Item hotBar[], int i){
    printf("\t%3d || %2d || %3d || %s\n", i, hotBar[i].ID, hotBar[i].amount, hotBar[i].name.c_str());
}

void printBar(Item hotBar[], int SIZE){
    printf("\tPOS || ID || QTY ||    NAME\n\t-----------------------------\n");
    for (int i = 0; i < SIZE; i++) format(hotBar, i);
}

const std::map<int, std::string> loot = {
    {13, "Ender Pearl"},
    {29, "Carrot"     },
    {31, "Iron Block" },
    {48, "Wool"       },
    {14, "Diamond"    }
};

void showLoot(){
    for (const auto &it : loot) printf("\n\t%d --> %s", it.first, it.second.c_str());
}
