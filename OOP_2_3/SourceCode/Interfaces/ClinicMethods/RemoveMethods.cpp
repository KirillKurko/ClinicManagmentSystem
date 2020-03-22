#include "Clinic.hpp"

using namespace std;

Doctor Clinic::removeDoctor(size_t index) {
    Doctor doctor;
    try {
        if (index < 0 || index >= doctors.size()) throw 1;
        doctor = doctors[index];
        doctors.erase(doctors.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return doctor;
}

Dentist Clinic::removeDentist(size_t index) {
    Dentist dentist;
    try {
        if (index < 0 || index >= dentists.size()) throw 1;
        dentist = dentists[index];
        dentists.erase(dentists.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return dentist;
}
Paramedic Clinic::removeParamedic(size_t index) {
    Paramedic paremedic;
    try {
        if (index < 0 || index >= paramedics.size()) throw 1;
        paremedic = paramedics[index];
        paramedics.erase(paramedics.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return paremedic;
}

Nurse Clinic::removeNurse(size_t index) {
    Nurse nurse;
    try {
        if (index < 0 || index >= nurses.size()) throw 1;
        nurse = nurses[index];
        nurses.erase(nurses.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return nurse;
}

std::shared_ptr<Person> Clinic::removePatient(size_t index) {
    shared_ptr<Person> patient;
    try {
        if (index < 0 || index >= patients.size()) throw 1;
        patient = patients[index];
        patients.erase(patients.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return patient;
}
