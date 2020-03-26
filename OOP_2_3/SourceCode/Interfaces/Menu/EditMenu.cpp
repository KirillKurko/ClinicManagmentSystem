#include "Menu.hpp"

using namespace std;

extern Clinic* clinic;
extern Logger::FileLogger logger;

void edit() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Главврач\n2 - Врач\n3 - Стоматолог\n4 - Фельдшер" <<
        "\n5 - Медрегистратор\n6 - Медсестра\n7 - Пациент\n8 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                editChiefMedicalOfficer(clinic->getChiefMedicalOfficer());
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editDoctor(clinic->getDoctor(index));
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 3:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editDentist(clinic->getDentist(index));
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editParamedic(clinic->getParamedic(index));
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 5:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editMedicalRecorder(clinic->getMedicalRecorder());
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 6:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editNurse(clinic->getNurse(index));
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 7:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    editPatient(clinic->getPatient(index));
                }
                catch (...) {
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование завершено");
                cout << "Редактирование завершено" << endl;
                return;
        }
    }
}

void editChiefMedicalOfficer(ChiefMedicalOfficer& chiefMedicalOfficer) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования главврача");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string specialization;
    float budget;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы" <<
        "\n6 - Редактировать зарплату\n7 - Редактировать специализацию\n8 - Редактировать бюджет\n9 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                chiefMedicalOfficer.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                chiefMedicalOfficer.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                chiefMedicalOfficer.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                chiefMedicalOfficer.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                chiefMedicalOfficer.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            case 7:
                cout << "Введите новое значение специализации: ";
                getline(cin, specialization);
                chiefMedicalOfficer.setSpecialization(specialization);
                break;
            case 8:
                cout << "Введите новое значение бюджета: ";
                budget = CorrectCin<float>();
                chiefMedicalOfficer.setBudget(budget);
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование главврача завершено");
                return;
        }
    }
}

void editDoctor(Doctor& doctor) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования доктора");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string specialization;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы" <<
        "\n6 - Редактировать зарплату\n7 - Редактировать специализацию\n8 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                doctor.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                doctor.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                doctor.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                doctor.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                doctor.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            case 7:
                cout << "Введите новое значение специализации: ";
                getline(cin, specialization);
                doctor.setSpecialization(specialization);
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование врача завершено");
                return;
        }
    }
}

void editDentist(Dentist& dentist) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования стоматолога");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы\n6 - Редактировать зарплату\n7 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                dentist.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                dentist.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                dentist.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                dentist.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                dentist.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактиорование стоматолога заверешено");
                return;
        }
    }
}

void editParamedic(Paramedic& paramedic) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования фельдшера");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    string region;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы" <<
        "\n6 - Редактировать зарплату\n7 - Редактировать регион\n8 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                paramedic.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                paramedic.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                paramedic.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                paramedic.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                paramedic.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            case 7:
                cout << "Введите новое значение закрепленного региона: ";
                getline(cin, region);
                paramedic.setRegion(region);
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование фельдшера завеершено");
                return;
        }
    }
}

void editMedicalRecorder(MedicalRecorder& medicalRecorder) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования медрегистратора");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы\n6 - Редактировать зарплату\n7 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                medicalRecorder.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                medicalRecorder.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                medicalRecorder.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                medicalRecorder.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                medicalRecorder.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование медрегистратора завершено");
                return;
        }
    }
}

void editNurse(Nurse& nurse) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования медсестры");
    int selection;
    string name;
    string surname;
    int age;
    string education;
    int experience;
    float salary;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст" <<
        "\n4 - Редактировать образование\n5 - Редактировать опыт работы\n6 - Редактировать зарплату\n7 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите новое значение имени: ";
                getline(cin, name);
                nurse.setName(name);
                break;
            case 2:
                cout << "Введите новое значение фамилии: ";
                getline(cin, surname);
                nurse.setSurname(surname);
                break;
            case 3:
                cout << "Введите новое значение возраста: ";
                age = CorrectCin<int>();
                nurse.setAge(age);
                break;
            case 4:
                cout << "Введите новое значение образования: ";
                getline(cin, education);
                nurse.setEducation(education);
                break;
            case 5:
                cout << "Введите новое значение опыта работы: ";
                experience = CorrectCin<int>();
                nurse.setExperience(experience);
                break;
            case 6:
                cout << "Введите новое значение зарплаты: ";
                salary = CorrectCin<float>();
                break;
            default:
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование медсестры завершено");
                return;
        }
    }
}

void editPatient(std::shared_ptr<Person> patient) {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции редактирования пациента");
    int selection;
    string name;
    string surname;
    int age;
    while (true) {
        cout << "\n1 - Редактировать имя\n2 - Редактировать фамилию\n3 - Редактировать возраст\n4 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
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
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Редактирование пациента завершено");
                return;
        }
    }
}
