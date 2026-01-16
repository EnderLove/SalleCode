#include <stdio.h>
#include <unordered_map>
#include <string>
    
struct Item{
    std::string name;
    int qty;
};

int main(){
    
    std::unordered_map<int, Item> items = {
        {0, {"Watermelon", 0}},
        {1, {"Diamond"   , 0}},
        {2, {"Bone"      , 0}},
        {3, {"Sand Block", 0}},
        {4, {"Dirt Block", 0}},
        {5, {"Bedrock"   , 0}},
        {6, {"Wool"      , 0}},
        {7, {"Leather"   , 0}},
        {8, {"Arrow"     , 0}}
    };
    
    std::unordered_map<int, std::unordered_map<int, Item>> players;
    
    players[0] = {
        {0, {"Watermelon", 10}}
    };

    players[1] = {
        {0, {"Diamond", 4}}
    };


    printf("%s\n", players[1][0].name.c_str());
    return 0;
}
