#include "Menu.hpp"

using namespace std;

extern Clinic* clinic;

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
                return;
        }
    }
}

void editDoctor(Doctor& doctor) {
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
                return;
        }
    }
}

void editDentist(Dentist& dentist) {
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
                return;
        }
    }
}

void editParamedic(Paramedic& paramedic) {
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
                return;
        }
    }
}

void editMedicalRecorder(MedicalRecorder& medicalRecorder) {
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
                return;
        }
    }
}

void editNurse(Nurse& nurse) {
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
                return;
        }
    }
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
