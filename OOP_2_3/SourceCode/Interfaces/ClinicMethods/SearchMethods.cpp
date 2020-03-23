#include "Clinic.hpp"

using namespace std;

void Clinic::search() const {
    int selection;
    while (true) {
        cout << "\n1 - Врачи\n2 - Стоматологи\n3 - Фельдшеры\n4 - Медсестры\n5 - Пациенты\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection =  CorrectCin<int>();
        switch (selection) {
            case 1:
                searchDoctors();
                break;
            case 2:
                searchDentists();
                break;
            case 3:
                searchParamedics();
                break;
            case 4:
                searchNurses();
                break;
            case 5:
                searchPatients();
                break;
            default:
                cout << "Поиск завершен" << endl;
        }
    }
}

void Clinic::searchDoctors() const {
    
}

void Clinic::searchDentists() const {
    
}
void Clinic::searchParamedics() const {
    
}
void Clinic::searchNurses() const {
    
}
void Clinic::searchPatients() const {
    
}
