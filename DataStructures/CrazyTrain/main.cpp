#include <iostream>
#include <cstdlib>
#include <unordered_map>

#define DNI   int
#define COUNT int 

std::unordered_map<DNI, COUNT> dniRecord;

class Wagon{
    private:
        int    m_dni;
        Wagon *m_next;

    public:
        Wagon(int dni, Wagon *next = nullptr) : m_dni(dni), m_next(next) {}
        ~Wagon() { std::cout << "WAGON DESTROYED!" << std::endl; }

        int    getDni()  const { return m_dni;  }
        Wagon *getNext() const { return m_next; }

        void setNext(Wagon* next) { m_next = next; }
};

class Train{
    private:
        Wagon *m_locomotive;
        Wagon *m_tail;

    public:
        Train() : m_locomotive(nullptr), m_tail(nullptr) {}
        ~Train() { 
            while (m_locomotive != nullptr){
                delFirst(); 
            }
            std::cout << "\n\t============= YOU KILL THEM ALL! =============\n\t============== TRAIN DESTROYED!!! ============\n";
        }

        void createEnd(int dni){
            
            if (dniRecord.find(dni) != dniRecord.end()) { return; }
            else dniRecord[dni];

            Wagon *newWagon = new Wagon(dni);

            if (m_locomotive == nullptr){
                newWagon->setNext(m_locomotive);
                m_locomotive = newWagon;
                m_tail = newWagon;
                return;
            }
            m_tail->setNext(newWagon);
            m_tail = newWagon; 
        } 

        void delFirst(){
            if (m_locomotive == nullptr){
                m_tail = nullptr;
                return;
            } 
            Wagon* temp = m_locomotive;

            dniRecord.erase(temp->getDni());

            m_locomotive = m_locomotive->getNext();
            delete(temp);
        }

        void showTrain(){
            Wagon *temp = m_locomotive;
            int i = 1;
            while (temp != nullptr){
                std::cout << "\tWAGON: " << i << " || DNI: " << temp->getDni() << std::endl;
                temp = temp->getNext();
                i++;
            }
        }
};

int main(){
    
    Train train;
    
    int choice = 0;
    int dni    = 0;

    while (choice != 3){
        system("clear"); 
        train.showTrain();

        std::cout << "\n\nSELECT AN OPTION: \n1) ADD TO END\n2) DEL FIRST\n3) EXIT\n";
        std::cin >> choice;

        if (choice == 1){
            std::cout << "INSERT THE DNI OF THE PASSANGER: " << std::endl;
            std::cin >> dni;
            train.createEnd(dni);
        }
        if (choice == 2){
            train.delFirst();
        }
    }
    std::cout << "\n\n";
    return 0;
}
