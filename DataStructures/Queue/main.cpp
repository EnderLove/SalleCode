#include <iostream>
#include "queue.h"

class Hospital : public QueuePrio<std::string>{
    
    public:
        
        void showQueue(){
            Node *temp = m_front;

            int format = temp->m_data.length();

            while (temp != nullptr){

                printf("NAME: %*s || PRIO: %d\n", format, temp->m_data.c_str(), temp->m_prio);

                temp = temp->m_next;
            }
        }
};

int main(){
    
    Hospital hospital;
    
    int uInput = 0;
    int prio = 0;

    std::string pName = "";

    hospital.enqueue("Sasha"  , 2);
   
    while (true){
        system("clear");
        hospital.showQueue();

        std::cout << "[0] NEW PACIENT\t[1] ATTANDACE\n";
        std::cin >> uInput;

        if (uInput == 0){
            std::cout << "PATIENT NAME: ";
            std::cin >> pName;

            std::cout << "[0]SOFT\n[1]NORMAL\n[2]URGENT\n[3]EMERGENCY\n";
            std::cin >> prio;

            hospital.enqueue(pName, prio);
        }
        else {
            hospital.dequeue();
        }
    }
    // LEVE, NORMAL, URGENTE, EMERGENCIA

    std::cout << "\nDEQUEUE\n";

    return 0;
}
