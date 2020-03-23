#include "Menu.hpp"

using namespace std;

extern Clinic* clinic;

void viewMenu() {
    int selection;
    while (true) {
        cout << "\n1 - Главврач\n2 - Врачи\n3 - Стоматологи\n4 - Фельдшеры\n5 - Медсестры" <<
        "\n6 - Медрегистратор\n7 - Пациенты\n8 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->getChiefMedicalOfficer().printInformation();
                break;
            case 2:
                viewDoctors();
                break;
            case 3:
                viewDentist();
                break;
            case 4:
                viewParamedics();
                break;
            case 5:
                viewNurses();
                break;
            case 6:
                clinic->getMedicalRecorder().printInformation();
                break;
            case 7:
                viewPatients();
                break;
            default:
                cout << "Просмотр заверешен" << endl;
                return;
        }
    }
    
}

void viewDoctors() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все врачи\n2 - Врач по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->printInformationAboutDoctors();
                break;
            case 2:
                cout << "Введите индекс:";
                index = CorrectCin<size_t>();
                try {
                    auto doctor = clinic->getDoctor(index);
                    doctor.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                return;
        }
    }
}

void viewDentist() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все стоматологи\n2 - Стоматолог по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->printInformationAboutDentists();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                try {
                    auto dentist = clinic->getDentist(index);
                    dentist.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                return;
        }
    }
}

void viewParamedics() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все фельдшеры\n2 - Фельдшер по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->printInformationAboutParamedics();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                try {
                    auto paramedic = clinic->getParamedic(index);
                    paramedic.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                return;
        }
    }
}

void viewNurses() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все медсестры\n2 - Медсестра по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->printInformationAboutNurses();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                try {
                    auto nurse = clinic->getNurse(index);
                    nurse.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                return;
        }
    }
}

void viewPatients() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все пациенты\n2 - Пациент по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->printInformationAboutPatients();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                try {
                    auto patient = clinic->getPatient(index);
                    patient->printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                return;
        }
    }
}

