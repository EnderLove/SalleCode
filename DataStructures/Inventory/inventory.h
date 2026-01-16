#ifndef IVENTORY_H
#define IVENTORY_H

#include <string>
#include <map>

struct Item{
    int ID;
    int amount;
    std::string name;
};

extern const std::map<int, std::string> loot;
void format(Item hotBar[], int i);
void printBar(Item hotBar[], int SIZE);
    
void showLoot();

#endif // IVENTORY_H!
