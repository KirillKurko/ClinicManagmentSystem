#include "Clinic.hpp"

using namespace std;

void Clinic::printInformation() const {
    cout << "Главный врач: " << endl;
    chiefMedicalOfficer.printInformation();
    cout << "Доктора: " << endl;
    printInformationAboutDoctors();
    cout << "Стоматологи: " << endl;
    printInformationAboutDentists();
    cout << "Фельдшеры: " << endl;
    printInformationAboutParamedics();
    cout << "Медсестры: " << endl;
    printInformationAboutNurses();
    cout << "Пациенты: " << endl;
    printInformationAboutPatients();
}

void Clinic::printInformationAboutDoctors() const {
    if (doctors.size() == 0) cout << "Список докторов пуст" << endl;
    else {
        for (size_t i = 0; i < doctors.size(); ++i) {
            cout << i + 1 << ")" << endl;
            doctors[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutDentists() const {
    if (dentists.size() == 0) cout << "Список стоматологов пуст" << endl;
    else {
        for (size_t i = 0; i < dentists.size(); ++i) {
            cout << i + 1 << ")" << endl;
            dentists[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutParamedics() const {
    if (paramedics.size() == 0) cout << "Список фельдшеров пуст" << endl;
    else {
        for (size_t i = 0; i < paramedics.size(); ++i) {
            cout << i + 1 << ")" << endl;
            paramedics[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutNurses() const {
    if (nurses.size() == 0) cout << "Список медсесер пуст" << endl;
    else {
        for (size_t i = 0; i < nurses.size(); ++i) {
            cout << i + 1 << ")" << endl;
            nurses[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutPatients() const {
    if (patients.size() == 0) cout << "Список пациентов пуст" << endl;
    else {
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << i + 1 << ")" << endl;
            patients[i]->printInformation();
            cout << "\n";
        }
    }
}

