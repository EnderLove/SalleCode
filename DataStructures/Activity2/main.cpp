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
            
            if (head == nullptr){
                head= new Student(code, name, type, prio, head);
            }
            else {
                Student *temp = head;

                while (temp != nullptr){
                    if (prio <= temp->m_prio){
                        temp = temp->m_next;
                    } 
                }
                temp = new Student(code, name, type, prio, temp);
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

    tramitList.insert(192378, "Joaquin" , "Beca"      , 3);
    tramitList.insert(192378, "Leonardo", "Nose"      , 1);
    tramitList.insert(192378, "Ruku"    , "Aplazado"  , 4);
    tramitList.insert(192378, "Genkozzz", "Aplazado"  , 4);
    tramitList.insert(192378, "BayBay"  , "Retiro"    , 1);
    tramitList.insert(192378, "Xhull"   , "Titulacion", 3);

    tramitList.showList();

    return 0;
}
