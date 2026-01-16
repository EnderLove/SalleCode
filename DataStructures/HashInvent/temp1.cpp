#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>

struct Item{
    std::string name;
    int qty;
};

void showPlayer(Item* inventory, int size){
    printf("\n====== PLAYER INVENTORY ======\n");
    for (int i = 0; i < size; i++){
        printf("POS: %2d || NAME: %11s || QTY: %2d\n", i, inventory[i].name.c_str(), inventory[i].qty);
    }
}

int main(){
   
    int pAmount = 0;
    std::string objName;
    int objQty = 0;
    int playerID = 0;
    int pos = 3;
    std::unordered_map<int, Item*> players;
    
    printf("\nSET THE AMOUNT OF PLAYERS\n");
    scanf("%d", &pAmount);

    int *size = new int[pAmount];
    
    for (int i = 0; i < pAmount; i++)
    {
        printf("SET THE IVENTORY SIZE OF PLAYER %d\n", i);
        scanf("%d", &size[i]);

        players[i] = new Item[size[i]];
    }

    for (int i = 0; i < pAmount; i++) showPlayer(players[i], size[i]);
    
    while (true){
        printf("\nSELECT A PLAYER FROM ID %d - %d: ", 0, pAmount);
        std::cin >> playerID;

        printf("\nINSERT AN ITEM:\n NAME: ");
        std::cin >> objName;
        printf("\nQTY: ");
        std::cin >> objQty;
        
        printf("\nSELECT A POS FROM %d - %d", 0, size[playerID] - 1);
        std::cin >> pos;

        players[playerID][pos].qty = objQty;
        
        players[playerID][pos].name = objName;

        for (int i = 0; i < pAmount; i++) showPlayer(players[i], size[i]);
    }
        return 0; 
}
