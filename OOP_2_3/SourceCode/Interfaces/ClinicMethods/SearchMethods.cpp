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
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string region;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате"
        << "\n7 - Поиск по закрепленному региону\n8 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getName() == name)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getSurname() == surname)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getAge() == age)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getEducation() == education)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getExperince() == experience)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getSalary() == salary)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            case 7:
                cout << "Введите закрепленный регион: ";
                getline(cin, region);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getRegion() == region)
                        paramedic.printInformation();
                    cout << "\n";
                }
                break;
            default:
                return;
        }
    }
}

void Clinic::searchNurses() const {
    int selection;
    string name;
    string surname;
    string education;
    int experience;
    float salary;
    int age;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате\n7 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& nurse: nurses) {
                    if (nurse.getName() == name)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& nurse: nurses) {
                    if (nurse.getSurname() == surname)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& nurse: nurses) {
                    if (nurse.getAge() == age)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& nurse: nurses) {
                    if (nurse.getEducation() == education)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& nurse: nurses) {
                    if (nurse.getExperince() == experience)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& nurse: nurses) {
                    if (nurse.getSalary() == salary)
                        nurse.printInformation();
                    cout << "\n";
                }
                break;
            default:
                return;
        }
    }
}
void Clinic::searchPatients() const {
    int selection;
    string name;
    string surname;
    int age;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту\n4 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& patient: patients) {
                    if (patient->getName() == name)
                        patient->printInformation();
                    cout << "\n";
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& patient: patients) {
                    if (patient->getSurname() == surname)
                        patient->printInformation();
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& patient: patients) {
                    if (patient->getAge() == age)
                        patient->printInformation();
                    cout << "\n";
                }
                break;
            default:
                return;
        }
    }
}
