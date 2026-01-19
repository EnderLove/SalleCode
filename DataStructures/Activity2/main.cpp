// CODIGO, NOMBRE, TIPO DE TRAMITE, PRIORIDAD ( ALTA, MEDIA, BAJA )
// INSERTAR SOLICITUD, MOSTRAR SOLICITUD, BUSCAR POR CODIGO, ELIMINAR SOLICITUD
#include <iostream>
#include <string>

struct Student{ //NODO
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

            if (head == nullptr || prio < head->m_prio){
                newNode->m_next = head; 
                head = newNode;
            }
            else {
                Student *temp = head;

                while (temp->m_next != nullptr && temp->m_next->m_prio <= prio){
                    temp = temp->m_next;
                }
                newNode->m_next = temp->m_next;
                temp->m_next = newNode;
            }
        }

        void showList(){
            Student *temp = head;
            while (temp->m_next != nullptr){
                std::cout << "CODE: " << temp->m_code << " || NAME: " << temp->m_name << " || TYPE: " << temp->m_type << " || PRIO: " << temp->m_prio << std::endl;
                temp = temp->m_next;
            }
        }
};

int main(){
    TramitList tramitList;

    std::cout << "HELLO WORLD\n";
    tramitList.insert(192378, "Joaquin" , "Beca"      , 3);
    tramitList.insert(192378, "Leonardo", "Nose"      , 1);
    tramitList.insert(192378, "Ruku"    , "Aplazado"  , 4);
    tramitList.insert(192378, "Genkozzz", "Aplazado"  , 4);
    tramitList.insert(192378, "BayBay"  , "Retiro"    , 1);
    tramitList.insert(192378, "Xhull"   , "Titulacion", 3);


    std::cout << "HELLO WORLD\n";
    tramitList.showList();

    return 0;
}
