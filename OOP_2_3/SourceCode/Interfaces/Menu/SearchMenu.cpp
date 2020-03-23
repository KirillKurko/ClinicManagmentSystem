#include "Menu.hpp"

extern Clinic* clinic;

using namespace std;

void search() {
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
                return;
        }
    }
}

void searchDoctors() {
    auto doctors = clinic->getDoctors();
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string specialization;
    int numberOfCuredPeople;
    bool found;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате"
        << "\n7 - Поиск по специализации\n8 - Поиск по количеству вылеченных людей\n8 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        found = false;
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& doctor: doctors) {
                    if (doctor.getName() == name) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данным именем" << endl;
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& doctor: doctors) {
                    if (doctor.getSurname() == surname) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данной фамилией" << endl;
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getAge() == age) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данным возрастом" << endl;
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& doctor: doctors) {
                    if (doctor.getEducation() == education) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                cout << "Нет докторов с данным образованием" << endl;
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getExperince() == experience) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данным опытом работы" << endl;
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& doctor: doctors) {
                    if (doctor.getSalary() == salary) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет доктров с данной зарплатой" << endl;
                break;
            case 7:
                cout << "Введите специализацию: ";
                getline(cin, specialization);
                for (auto& doctor: doctors) {
                    if (doctor.getSpecialization() == specialization) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данной специализацией" << endl;
                break;
            case 8:
                cout << "Введите количество вылеченных людей: ";
                numberOfCuredPeople = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getNumberOfCuredPeople() == numberOfCuredPeople) {
                        doctor.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет докторов с данным количеством вылеченных людей" << endl;
                break;
            default:
                return;
        }
    }
}

void searchDentists() {
    auto dentists = clinic->getDentists();
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    bool found;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате\n7 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        found = false;
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& dentist: dentists) {
                    if (dentist.getName() == name) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов с данным именем" << endl;
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& dentist: dentists) {
                    if (dentist.getSurname() == surname) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов с данной фамилией" << endl;
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& dentist: dentists) {
                    if (dentist.getAge() == age) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов данного возраста" << endl;
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& dentist: dentists) {
                    if (dentist.getEducation() == education) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов с данным образованием" << endl;
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& dentist: dentists) {
                    if (dentist.getExperince() == experience) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов с данным опытом работы" << endl;
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& dentist: dentists) {
                    if (dentist.getSalary() == salary) {
                        dentist.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет стоматологов с данной зарплатой" << endl;
                break;
            default:
                return;
        }
    }
}

void searchParamedics() {
    auto paramedics = clinic->getParamedics();
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string region;
    bool found;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате"
        << "\n7 - Поиск по закрепленному региону\n8 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        found = false;
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getName() == name) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                    if (!found) cout << "Нет фельдшеров с данным именем" << endl;
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getSurname() == surname) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров с данной фамлией" << endl;
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getAge() == age) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров данного возраста" << endl;
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getEducation() == education) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров с данным образованием" << endl;
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getExperince() == experience) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров с данным опытом работы" << endl;
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& paramedic: paramedics) {
                    if (paramedic.getSalary() == salary) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров с данной зарплатой" << endl;
                break;
            case 7:
                cout << "Введите закрепленный регион: ";
                getline(cin, region);
                for (auto& paramedic: paramedics) {
                    if (paramedic.getRegion() == region) {
                        paramedic.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет фельдшеров с данным закрепленным регионов" << endl;
                break;
            default:
                return;
        }
    }
}

void searchNurses() {
    auto nurses = clinic->getNurses();
    int selection;
    string name;
    string surname;
    string education;
    int experience;
    float salary;
    int age;
    bool found;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате\n7 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        found = false;
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& nurse: nurses) {
                    if (nurse.getName() == name) {
                        nurse.printInformation();
                        found =  true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данным именем" << endl;
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& nurse: nurses) {
                    if (nurse.getSurname() == surname) {
                        nurse.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данной фамилией" << endl;
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& nurse: nurses) {
                    if (nurse.getAge() == age) {
                        nurse.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данным возрастом" << endl;
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& nurse: nurses) {
                    if (nurse.getEducation() == education) {
                        nurse.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данным образованием" << endl;
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& nurse: nurses) {
                    if (nurse.getExperince() == experience) {
                        nurse.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данным опытом работы" << endl;
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& nurse: nurses) {
                    if (nurse.getSalary() == salary) {
                        nurse.printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет медсестер с данной зарплатой" << endl;
                break;
            default:
                return;
        }
    }
}
void searchPatients() {
    auto patients = clinic->getPatients();
    int selection;
    string name;
    string surname;
    int age;
    bool found;
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту\n4 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        found = false;
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& patient: patients) {
                    if (patient->getName() == name) {
                        patient->printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет пациентов с данным именем" << endl;
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& patient: patients) {
                    if (patient->getSurname() == surname) {
                        patient->printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет пациентов с данной фамилией" << endl;
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& patient: patients) {
                    if (patient->getAge() == age) {
                        patient->printInformation();
                        found = true;
                    }
                    cout << "\n";
                }
                if (!found) cout << "Нет пациентов данного возраста" << endl;
                break;
            default:
                return;
        }
    }
}

