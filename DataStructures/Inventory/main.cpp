#include <stdio.h>
#include "inventory.h"

void insert(Item hotBar[], int SIZE, int &qty, int pos, int choice){
    int ID = 0;
    for (int i = qty + 1; i > pos; i--){
        hotBar[i] = hotBar[i - 1];
        ID = i;
    }
    qty++;
}

bool searchID(Item hotBar[], int SIZE, int ID){
    for (int i = 0; i < SIZE; i++){
        if (hotBar[i].ID == ID){
           format(hotBar, i); 
           return true;
        }  
    }
    return false;
}

int getID(Item hotBar[], int SIZE, int choice){
    int ID = 0; 
    for (int i = 0; i < SIZE; i++) if (hotBar[i].ID == choice) ID = i;
    return ID;
}

int main(){
    const int SIZE = 10;
    
    int ID     = 0;
    int choice = 0;
    int pos    = 0;
    int qty    = 4;

    Item hotBar[SIZE] = {
        {23, 04, "Dirt Block"},
        {14, 34, "Diamond"   },
        {69, 20, "Potatoe"   },
        {22, 15, "Bedrock"   }
    };
    
    while (true){
        printBar(hotBar, SIZE);
        printf("\n\t===== OPTIONS =====\n\t1)SEARCH\n\t2)INSERT\n\t3)DELETE\n\t4)EXIT\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\n\tSEARCH CODE: ");
                scanf("%d", &ID); // std::cin >> ID;
                searchID(hotBar, SIZE, ID);
                break;

            case 2:
                showLoot();
                printf("\n\tSELECT AN ITEM: ");
                scanf("%d", &choice);
                
                if(searchID(hotBar, SIZE, choice)){
                    ID = getID(hotBar, SIZE, choice);
                    printf("\nID: %d\n", ID);
                    hotBar[ID].amount++;
                } else {
                    printf("\n\tSELECT A POS: ");
                    scanf("%d", &pos);

                    insert(hotBar, SIZE, qty, pos, choice);
                }
                break;
        }
    }

    printf("\n");
    return 0;
}
