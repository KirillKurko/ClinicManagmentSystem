#include "NursingStaff.hpp"

using namespace std;

MedicalRecorder::MedicalRecorder(string name, string surname,
                int age, string education,
                int experience, float salary,
                vector<pair<string, pair<Date, shared_ptr<Person>>>> appointments)
: NursingStaff(name, surname, age, education, experience, salary) {
    this->appointments = appointments;
}

MedicalRecorder::MedicalRecorder(const NursingStaff& other, std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> appointments)
: NursingStaff(other) {
    this->appointments = appointments;
}

MedicalRecorder::MedicalRecorder(const MedicalRecorder& other) : NursingStaff(other) {
    appointments = other.appointments;
}

vector<pair<string, pair<Date, shared_ptr<Person>>>> MedicalRecorder::getAppointments() const {
    return appointments;
}

void MedicalRecorder::setAppointments(vector<pair<string, pair<Date, shared_ptr<Person>>>> appointments) {
    this->appointments = appointments;
}

void MedicalRecorder::addAppointment(pair<string, pair<Date, shared_ptr<Person>>> appointment) {
    appointments.push_back(appointment);
}

void MedicalRecorder::removeAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        appointments.erase(appointments.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
}

MedicalRecorder& MedicalRecorder::operator= (const MedicalRecorder& other) {
    NursingStaff::operator=(other);
    appointments = other.appointments;
    return *this;
}

void MedicalRecorder::printInformation() const {
    NursingStaff::printInformation();
    if (appointments.size() == 0) cout << "Список приемов пуст" << endl;
    else {
        cout << "Приемы: ";
        for (size_t i = 0; i < appointments.size(); ++i) {
            cout << i + 1 << ") " << endl <<
            "Лечащий врач: " << appointments[i].first <<
            "Дата: " << appointments[i].second.first <<
            "Пациент: " << endl;
            appointments[i].second.second->printInformation();
        }
    }
}

Nurse::Nurse(string name, string surname,
             int age, string education,
             int experience, float salary,
             shared_ptr<Doctor> doctor)
: NursingStaff(name, surname, age, education, experience, salary) {
    this->doctor = doctor;
}

Nurse::Nurse(const NursingStaff& other, std::shared_ptr<Doctor> doctor) : NursingStaff(other) {
    this->doctor = doctor;
}

Nurse::Nurse(const Nurse& other) : NursingStaff(other) {
    doctor = other.doctor;
}

std::shared_ptr<Doctor> Nurse::getDoctor() const {
    return doctor;
}

void Nurse::setDoctor(std::shared_ptr<Doctor> doctor) {
    this->doctor = doctor;
}

Nurse& Nurse::operator= (const Nurse& other) {
    NursingStaff::operator=(other);
    doctor = other.doctor;
    return *this;
}

void Nurse::printInformation() const {
    NursingStaff::printInformation();
    cout << "Доктор, за которым закреплена: " << endl;
    doctor->printInformation();
}
