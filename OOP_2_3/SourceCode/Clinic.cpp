#include "Clinic.hpp"

using namespace std;

Clinic::Clinic(ChiefMedicalOfficer chiefMedicalOfficer,
               vector<Doctor> doctors,
               vector<Dentist> dentists,
               vector<Paramedic> paramedics,
               vector<Nurse> nurses,
               MedicalRecorder medicalRecorder,
               vector<shared_ptr<Person>> patients) {
    this->chiefMedicalOfficer = chiefMedicalOfficer;
    this->doctors = doctors;
    this->dentists = dentists;
    this->paramedics = paramedics;
    this->nurses = nurses;
    this->medicalRecorder = medicalRecorder;
    this->patients = patients;
}

Clinic::Clinic(const Clinic& other) {
    chiefMedicalOfficer = other.chiefMedicalOfficer;
    doctors = other.doctors;
    dentists = other.dentists;
    paramedics = other.paramedics;
    nurses = other.nurses;
    medicalRecorder = other.medicalRecorder;
    patients = other.patients;
}

ChiefMedicalOfficer Clinic::getChiefMedicalOfficer() const {
    return chiefMedicalOfficer;
}

std::vector<Doctor> Clinic::getDoctors() const {
    return doctors;
}

std::vector<Dentist> Clinic::getDentists() const {
    return dentists;
}

std::vector<Paramedic> Clinic::getParamedics() const {
    return paramedics;
}

std::vector<Nurse> Clinic::getNurses() const {
    return nurses;
}

MedicalRecorder Clinic::getMedicalRecorder() const {
    return medicalRecorder;
}

std::vector<std::shared_ptr<Person>> Clinic::getPatients() const {
    return patients;
}

void Clinic::setChiefMedicalOfficer(ChiefMedicalOfficer chiefMedicalOfficer) {
    this->chiefMedicalOfficer = chiefMedicalOfficer;
}

void Clinic::setDoctors(std::vector<Doctor> doctors) {
    this->doctors = doctors;
}

void Clinic::setDentists(std::vector<Dentist> dentists) {
    this->dentists = dentists;
}

void Clinic::setParamedics(std::vector<Paramedic> paramedics) {
    this->paramedics = paramedics;
}

void Clinic::setNurses(std::vector<Nurse> nurses) {
    this->nurses = nurses;
}

void Clinic::setMedicalRecorder(MedicalRecorder medicalRecorder) {
    this->medicalRecorder = medicalRecorder;
}

void Clinic::setPatients(std::vector<std::shared_ptr<Person>> patients) {
    this->patients = patients;
}

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

void Clinic::addDoctor(Doctor doctor) {
    doctors.push_back(doctor);
}

void Clinic::addDentist(Dentist dentist) {
    dentists.push_back(dentist);
}

void Clinic::addParamedic(Paramedic paramedic) {
    paramedics.push_back(paramedic);
}

void Clinic::addNurse(Nurse nurse) {
    nurses.push_back(nurse);
}

void Clinic::addPatient(std::shared_ptr<Person> patient) {
    patients.push_back(patient);
}

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

void Clinic::printInformation() const {
    cout << "Главный врач: " << endl;
    chiefMedicalOfficer.printInformation();
    cout << "Доктора: " << endl;
    printInformationAboutDoctors();
    cout << "Стоматологи: " << endl;
    printInformationAboutDentists();
    cout << "Фельдшеры: " << endl;
    printInformationAboutParamedics();
    cout << "Медсестры: " << endl;
    printInformationAboutNurses();
    cout << "Пациенты: " << endl;
    printInformationAboutPatients();
}

void Clinic::printInformationAboutDoctors() const {
    if (doctors.size() == 0) cout << "Список докторов пуст" << endl;
    else {
        for (size_t i = 0; i < doctors.size(); ++i) {
            cout << i + 1 << ")" << endl;
            doctors[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutDentists() const {
    if (dentists.size() == 0) cout << "Список стоматологов пуст" << endl;
    else {
        for (size_t i = 0; i < dentists.size(); ++i) {
            cout << i + 1 << ")" << endl;
            dentists[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutParamedics() const {
    if (paramedics.size() == 0) cout << "Список фельдшеров пуст" << endl;
    else {
        for (size_t i = 0; i < paramedics.size(); ++i) {
            cout << i + 1 << ")" << endl;
            paramedics[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutNurses() const {
    if (nurses.size() == 0) cout << "Список медсесер пуст" << endl;
    else {
        for (size_t i = 0; i < nurses.size(); ++i) {
            cout << i + 1 << ")" << endl;
            nurses[i].printInformation();
            cout << "\n";
        }
    }
}

void Clinic::printInformationAboutPatients() const {
    if (patients.size() == 0) cout << "Список пациентов пуст" << endl;
    else {
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << i + 1 << ")" << endl;
            patients[i]->printInformation();
            cout << "\n";
        }
    }
}
