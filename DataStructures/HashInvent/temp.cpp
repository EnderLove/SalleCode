#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>

struct Item{
    std::string name;
    int qty;
};

void showPlayers(const std::unordered_map<int, std::vector<Item>> &players){
    for (auto &player : players){
        printf("\n====== Player %d ======\n", player.first);
        for (auto &item : player.second){
            printf("Name: %10s || Qty: %2d\n", item.name.c_str(), item.qty);
        }      
    }
}

void showPlay(const std::unordered_map<int, Item*> &ply, int size){
    for (auto player : ply){
        printf("\n====== Player %d ======\n", player.first);
        for (int i = 0; i < size; i++){
            printf("Name %s || Qty: %d\n", player.second->name.c_str(), player.second->qty);
        }
    }
}

int main(){
   
    int size = 5;
    Item *inventory= new Item[size];
    
    std::unordered_map<int, std::vector<Item>> players;

    players[0] = {
        {"Watermelon", 10},
        {"Diamond"   , 2 },
        {"Bone"      , 23},
    };

    players[1] = {
        {"Bedrock"   , 10},
        {"Diamond"   , 2 },
        {"Leather"   , 23},
    };
    
    players[2] = {
        {"Sand Block", 10},
        {"Wool"      , 2 },
        {"Arrow"     , 23},
    };

    std::unordered_map<int, Item*> ply;

    ply[0] = new Item[size];
    ply[1] = new Item[size];


    showPlay(ply, size);

    showPlayers(players);

    return 0; 
}
