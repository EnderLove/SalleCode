// CODIGO, NOMBRE, TIPO DE TRAMITE, PRIORIDAD ( ALTA, MEDIA, BAJA )
// INSERTAR SOLICITUD, MOSTRAR SOLICITUD, BUSCAR POR CODIGO, ELIMINAR SOLICITUD
#include <iostream>
#include <string>

struct Student{ //
    int m_code;
    std::string m_name;
    std::string m_type;
    int m_prio;
    Student *m_next;
    Student(int code, std::string name, std::string type, int prio, Student *next = nullptr) : m_code(code), m_name(name), m_type(type), m_prio(prio), m_next(next) {}
};

class TramitList{
    public: 
        Student *head = nullptr;

        void insert(int code, std::string name, std::string type, int prio){

            Student *newNode = new Student(code, name, type, prio);

            if (head == nullptr || prio > head->m_prio){  // WE VERIFY IF THE HIGH PRIO IS AT THE BEGGINING
                newNode->m_next = head; 
                head = newNode;
            }
            else {
                Student *temp = head;

                while (temp->m_next != nullptr && temp->m_next->m_prio >= prio){
                    temp = temp->m_next;
                }
                newNode->m_next = temp->m_next;
                temp->m_next = newNode;
            }
        }

        void pop(int pos){
            if (head == nullptr) return;

            Student *temp = head;
            if (pos == 0){
                head = head->m_next;
                delete (temp);
            }
            for (int i = 0; i < pos - 1; i++){
                temp = temp->m_next; 
            }
            temp->m_next = temp->m_next->m_next;
        }

        void showList(){
            Student *temp = head;
            int i = 0;
            while (temp->m_next != nullptr){
                printf("POS: %d || CODE: %6d || NAME: %11s || TYPE: %12s || PRIO: %d\n",
                        i, temp->m_code, temp->m_name.c_str(), temp->m_type.c_str(), temp->m_prio);
                temp = temp->m_next;
                i++;
            }
        }
};

int main(){
    TramitList tramitList;

    tramitList.insert(192378, "Joaquin" , "Beca"      , 3);
    tramitList.insert(192378, "Leonardo", "Nose"      , 1);
    tramitList.insert(192378, "Ruku"    , "Aplazado"  , 4);
    tramitList.insert(192378, "Genkozzz", "Aplazado"  , 4);
    tramitList.insert(192378, "BayBay"  , "Retiro"    , 1);
    tramitList.insert(192378, "Xhull"   , "Titulacion", 3);

    tramitList.showList();
    std::cout << "\n";
    tramitList.pop(4);
    tramitList.showList();

    return 0;
}
