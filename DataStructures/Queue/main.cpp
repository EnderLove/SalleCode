#include <iostream>
#include <unordered_map>
#include "queue.h"

class Hospital{
    private:
        struct Patient{
            std::string m_dni;
            std::string m_name;
            std::string m_info;
            Patient() {}
            Patient(std::string dni, std::string name, std::string info) : m_dni(dni), m_name(name), m_info(info) {}
        };
        QueuePrio<std::string, int> waitList;
        std::unordered_map<std::string, Patient> patientLog;

    public:
        void addPatient(std::string dni, std::string name, std::string info, int prio){
            patientLog[dni] = Patient(dni, name, info);
            waitList.enqueue(dni, prio);
        }

        void attendNext(){
            if (waitList.isEmpty()) return;
            waitList.dequeue();
        }

        void showWaitList(){
            if (waitList.isEmpty()) return;

            printf("%10s | %12s | %15s | %5s\n", "DNI", "NAME", "INFO", "PRIO\n------------------------------------------------------");

            auto current = waitList.getFront(); 
            while (current != nullptr){
                std::string currentDni = current->m_data;
                
                Patient &p = patientLog[currentDni];
                printf("%10s | %12s | %15s | %1d\n",
                        p.m_dni.c_str(), p.m_name.c_str(), p.m_info.c_str(), current->m_prio);
                
                current = current->m_next;
            }
            auto highPrioDni= waitList.getMaxPrio();
            Patient &p = patientLog[highPrioDni->m_data];

            printf("\nNEXT PATIENT: [%12s : %10s]", p.m_name.c_str(), p.m_dni.c_str());
        }

        void showLog(){
            if (patientLog.empty()) return;

            for (const auto &patient : patientLog){
                const std::string &dni = patient.first;
                const Patient &data    = patient.second;
                printf("DNI: %10s | NAME: %12s | INFO: %s\n", dni.c_str(), data.m_name.c_str(), data.m_info.c_str());
            }
        }
};

int main(){
    
    Hospital hospital;
    
    int uInput = 0;
    int prio   = 0;

    std::string pName = "";
    std::string pDni;
    std::string pInfo;
    
    hospital.addPatient("72725412", "Joaquin" , "Intoxicado"     , 0);
    hospital.addPatient("72725413", "Sasha"   , "Dolor de cabeza", 3);
    hospital.addPatient("72725414", "Jhonatan", "Drogas"         , 2);
    hospital.addPatient("72725415", "Claudio" , "Tumor"          , 0);
    hospital.addPatient("72725416", "Jorge"   , "Paro cardiaco"  , 1);
    hospital.addPatient("72725410", "Miguel"  , "Quemadura"      , 3);
   
    while (true){
        system("clear");
        hospital.showWaitList();

        std::cout << "\n\n[0] NEW PATIENT\t[1] ATTANDACE\t[2] LOG\n";
        std::cin >> uInput;

        if (uInput == 0){
            std::cout << "PATIENT DNI: ";
            std::cin >> pDni;
            std::cout << "PATIENT NAME: ";
            std::cin >> pName;
            std::cout << "PATIENT INFO: ";
            std::cin >> pInfo;
            std::cout << "[0]SOFT\n[1]NORMAL\n[2]URGENT\n[3]EMERGENCY\n";
            std::cin >> prio;

            hospital.addPatient(pDni, pName, pInfo, prio);
        }
        else if (uInput == 1){
            hospital.attendNext();
        }
        else {
            std::cout << "\n";
            hospital.showLog();
            std::cin.get();
            std::cin.get();
        }
    }
    return 0;
}
