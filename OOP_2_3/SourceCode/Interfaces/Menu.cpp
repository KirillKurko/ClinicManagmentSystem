#include "Menu.hpp"

using namespace std;

Clinic* clinic = nullptr;

void terminate_func() {
    cout << "Собственная функция завершения: возникло необработанное исключение" << endl;
    exit(-1);
}

int mainMenu() {
    int selection;
    set_terminate(terminate_func);
    while (true) {
        cout << "\n1 - Создать клинику\n2 - Просмотреть\n3 - Добавить\n4 - Удалить\n5 - Поиск"
        << "\n6 - Редактирование\n7 - Задание\n8 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                try {
                    if (clinic != nullptr) throw -1;
                    if (!(clinic = new Clinic(CreateClinic()))) throw bad_alloc();
                }
                catch (bad_alloc exception) {
                    cout << "Ошибка создания клиники: " << exception.what() << endl;
                }
                break;
            case 2:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                viewMenu();
                break;
            case 3:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                add();
                break;
            case 4:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                remove();
                break;
            case 5:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                search();
                break;
            case 6:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                edit();
                break;
            case 7:
                task();
                break;
            default:
                cout << "Работа завершена" << endl;
                delete clinic;
                return 0;
        }
    }
}

void viewMenu() {
    int selection;
    while (true) {
        cout << "\n1 - Главврач\n2 - Врачи\n3 - Стоматологи\n4 - Фельдшеры\n5 - Медсестры\n6 - Медрегистратор\n7 - Пациенты\n8 - Назад" << endl;
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

void add() {
    int selection;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->addDoctor(CreateDoctor());
                break;
            case 2:
                clinic->addDentist(CreateDentist());
                break;
            case 3:
                clinic->addParamedic(CreateParamedic());
                break;
            case 4:
                clinic->addNurse(CreateNurse());
                break;
            case 5:
                clinic->addPatient(make_shared<Person>(CreatePerson()));
                break;
            default:
                cout << "Добавление завершено" << endl;
                return;
        }
    }
}

void remove() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeDoctor(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeDentist(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 3:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeParamedic(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeNurse(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 5:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removePatient(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                cout << "Удаление завершено" << endl;
                return;
        }
    }
}

void edit() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Главврач\n2 - Врач\n3 - Стоматолог\n4 - Фельдшер" <<
        "\n5 - Медрегистратор\n6 - Медсестра\n7 - Пациент\n8 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                editChiefMedicalOfficer(clinic->getChiefMedicalOfficer());
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editDoctor(clinic->getDoctor(index));
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 3:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editDentist(clinic->getDentist(index));
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editParamedic(clinic->getParamedic(index));
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 5:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editMedicalRecorder(clinic->getMedicalRecorder());
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 6:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editNurse(clinic->getNurse(index));
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 7:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    editPatient(clinic->getPatient(index));
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                cout << "Редактирование завершено" << endl;
                return;
        }
    }
}

void editChiefMedicalOfficer(ChiefMedicalOfficer& chiefMedicalOfficer) {
    
}

void editDoctor(Doctor& doctor) {
    
}

void editDentist(Dentist& dentist) {
    
}

void editParamedic(Paramedic& paramedic) {
    
}

void editMedicalRecorder(MedicalRecorder& medicalRecorder) {
    
}

void editNurse(Nurse& nurse) {
    
}

void editPatient(std::shared_ptr<Person> patient) {
    int selection;
    string name;
    string surname;
    int age;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст\n4 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                patient->setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                patient->setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                patient->setAge(age);
                break;
            default:
                return;
        }
    }
}

void task() {
    int input = 0;
    cout << "Вопрос: для чего необходимо использовать абсолютный обработчик?" << endl
    << "Чтобы просмотреть ответ нажмите 1: ";
    input = CorrectCin<int>();
    while (input != 1) {
        cout << "Неверный ввод, повторите попытку: ";
        input = CorrectCin<int>();
    }
    cout << "Ответ: абсолютный обработчик используемя для перехвата исключений любых типов" << endl;
    return;
}

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
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате"
        << "\n7 - Поиск по специализации\n8 - Поиск по количеству вылеченных людей\n8 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& doctor: doctors) {
                    if (doctor.getName() == name)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& doctor: doctors) {
                    if (doctor.getSurname() == surname)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getAge() == age)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& doctor: doctors) {
                    if (doctor.getEducation() == education)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getExperince() == experience)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& doctor: doctors) {
                    if (doctor.getSalary() == salary)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 7:
                cout << "Введите специализацию: ";
                getline(cin, specialization);
                for (auto& doctor: doctors) {
                    if (doctor.getSpecialization() == specialization)
                        doctor.printInformation();
                    cout << "\n";
                }
                break;
            case 8:
                cout << "Введите количество вылеченных людей: ";
                numberOfCuredPeople = CorrectCin<int>();
                for (auto& doctor: doctors) {
                    if (doctor.getNumberOfCuredPeople() == numberOfCuredPeople)
                        doctor.printInformation();
                    cout << "\n";
                }
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
    while (true) {
        cout << "\n1 - Поиск по имени\n2 - Поиск по фамилии\n3 - Поиск по возрасту" <<
        "\n4 - Поиск по образованию\n5 - Поиск по опыту работы\n6 - Поиск по зарплате\n7 - Назад" << endl;
        cout << "Выберите критерий поиска: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите имя: ";
                getline(cin, name);
                for (auto& dentist: dentists) {
                    if (dentist.getName() == name)
                        dentist.printInformation();
                    cout << "\n";
                }
                break;
            case 2:
                cout << "Введите фамилию: ";
                getline(cin, surname);
                for (auto& dentist: dentists) {
                    if (dentist.getSurname() == surname)
                        dentist.printInformation();
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Введите возраст: ";
                age = CorrectCin<int>();
                for (auto& dentist: dentists) {
                    if (dentist.getAge() == age)
                        dentist.printInformation();
                    cout << "\n";
                }
                break;
            case 4:
                cout << "Введите образованиие: ";
                getline(cin, education);
                for (auto& dentist: dentists) {
                    if (dentist.getEducation() == education)
                        dentist.printInformation();
                    cout << "\n";
                }
                break;
            case 5:
                cout << "Введите опыт работы: ";
                experience = CorrectCin<int>();
                for (auto& dentist: dentists) {
                    if (dentist.getExperince() == experience)
                        dentist.printInformation();
                    cout << "\n";
                }
                break;
            case 6:
                cout << "Введите зарплату: ";
                salary = CorrectCin<float>();
                for (auto& dentist: dentists) {
                    if (dentist.getSalary() == salary)
                        dentist.printInformation();
                    cout << "\n";
                }
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

void searchNurses() {
    auto nurses = clinic->getNurses();
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
void searchPatients() {
    auto patients = clinic->getPatients();
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

