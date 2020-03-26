#include "Menu.hpp"

using namespace std;

extern Clinic* clinic;
extern Logger::FileLogger logger;

void viewMenu() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра");
    int selection;
    while (true) {
        cout << "\n1 - Главврач\n2 - Врачи\n3 - Стоматологи\n4 - Фельдшеры\n5 - Медсестры" <<
        "\n6 - Медрегистратор\n7 - Пациенты\n8 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
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
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр завершен");
                cout << "Просмотр заверешен" << endl;
                return;
        }
    }
    
}

void viewDoctors() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра докторов");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все врачи\n2 - Врач по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                clinic->printInformationAboutDoctors();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    auto doctor = clinic->getDoctor(index);
                    doctor.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр докторов завершен");
                return;
        }
    }
}

void viewDentist() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра стоматологов");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все стоматологи\n2 - Стоматолог по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                clinic->printInformationAboutDentists();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    auto dentist = clinic->getDentist(index);
                    dentist.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр стоматологов завершен");
                return;
        }
    }
}

void viewParamedics() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра фельдшеров");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все фельдшеры\n2 - Фельдшер по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                clinic->printInformationAboutParamedics();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    auto paramedic = clinic->getParamedic(index);
                    paramedic.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр фельдшеров завершен");
                return;
        }
    }
}

void viewNurses() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра медсестер");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все медсестры\n2 - Медсестра по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                clinic->printInformationAboutNurses();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    auto nurse = clinic->getNurse(index);
                    nurse.printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр медсестер завершен");
                return;
        }
    }
}

void viewPatients() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции просмотра пациентов");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Все пациенты\n2 - Пациент по индексу\n3 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                clinic->printInformationAboutPatients();
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<size_t>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    auto patient = clinic->getPatient(index);
                    patient->printInformation();
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Просмотр пациентов завершен");
                return;
        }
    }
}

