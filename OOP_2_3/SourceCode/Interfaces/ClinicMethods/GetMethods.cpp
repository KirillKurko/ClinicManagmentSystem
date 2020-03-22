#include "Clinic.hpp"

using namespace std;

Doctor Clinic::getDoctor(size_t index) {
    try {
        if (index < 0 || index >= doctors.size()) throw 1;
        return doctors[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return Doctor();
}

Dentist Clinic::getDentist(size_t index) {
    try {
        if (index < 0 || index >= dentists.size()) throw 1;
        return dentists[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return Dentist();
}

Paramedic Clinic::getParamedic(size_t index) {
    try {
        if (index < 0 || index >= paramedics.size()) throw 1;
        return paramedics[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return Paramedic();
}

Nurse Clinic::getNurse(size_t index) {
    try {
        if (index < 0 || index >= nurses.size()) throw 1;
        return nurses[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return Nurse();
}

std::shared_ptr<Person> Clinic::getPatient(size_t index) {
    try {
        if (index < 0 || index >= patients.size()) throw 1;
        return patients[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
        throw;
    }
    return nullptr;
}

