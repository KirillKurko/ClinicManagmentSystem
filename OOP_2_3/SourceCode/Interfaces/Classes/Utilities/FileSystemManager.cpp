#include "FileSystemManager.hpp"

using namespace std;

FileSystemManager::FileSystemManager::FileSystemManager() {
    this->chiefMedicalOfficerFilename = "chiefMedicalOfficer.txt";
    this->doctorsFilename = "doctors.txt";
    this->dentistsFilename = "dentists.txt";
    this->paramedicsFilename = "paramedics.txt";
    this->nursesFilename = "nurses.txt";
    this->medicalRecorderFilename = "medicalRecorder.txt";
    this->patientsFilename = "patients.txt";
}

FileSystemManager::FileSystemManager::FileSystemManager(string chiefMedicalOfficerFilename,
                  string doctorsFilename, string dentistsFilename, string paramedicsFilename,
                  string nursesFilename, string medicalRecorderFilename, string patientsFilename) {
    this->chiefMedicalOfficerFilename = chiefMedicalOfficerFilename;
    this->doctorsFilename = doctorsFilename;
    this->dentistsFilename = dentistsFilename;
    this->paramedicsFilename = paramedicsFilename;
    this->nursesFilename = nursesFilename;
    this->medicalRecorderFilename = medicalRecorderFilename;
    this->patientsFilename = patientsFilename;
}

Clinic FileSystemManager::FileSystemManager::loadClinic() {
    auto chiefMedicalOfficer = loadChiefMedicalOfficer();
    auto doctors = loadDoctors();
    auto dentists = loadDentists();
    auto paramedics = loadParamedics();
    auto nurses = loadNurses();
    auto medicalRecorder = loadMedicalRecorder();
    auto patients = loadPatients();
    return Clinic(chiefMedicalOfficer, doctors, dentists, paramedics, nurses, medicalRecorder, patients);
}

void FileSystemManager::FileSystemManager::saveClinic(const Clinic& clinic) {
    saveChiefMedicalOfficer(clinic.getChiefMedicalOfficer());
    saveDoctors(clinic.getDoctors());
    saveDentsts(clinic.getDentists());
    saveParamedics(clinic.getParamedics());
    saveNurses(clinic.getNurses());
    saveMedicalRecorder(clinic.getMedicalRecorder());
    savePatients(clinic.getPatients());
    
}

ChiefMedicalOfficer FileSystemManager::FileSystemManager::loadChiefMedicalOfficer() {
    ifstream file;
    string data;
    file.open(chiefMedicalOfficerFilename, ios_base::in);
    if (file.is_open()) {
        getline(file, data);
        auto arguments = parseString(data);
        file.close();
        return ChiefMedicalOfficer(arguments[0], arguments[1], stoi(arguments[2]), arguments[3],
                                            stoi(arguments[4]), stof(arguments[5]), arguments[6], stof(arguments[7]));
    }
    return ChiefMedicalOfficer();
}

std::vector<Doctor> FileSystemManager::FileSystemManager::loadDoctors() {
    vector<Doctor> doctors;
    ifstream file;
    string data;
    file.open(doctorsFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            auto arguments = parseString(data);
            doctors.push_back(Doctor(arguments[0], arguments[1], stoi(arguments[2]), arguments[3], stoi(arguments[4]),
                                     stof(arguments[5]), arguments[6], std::vector<std::shared_ptr<Person>>(),
                                     stoi(arguments[7]), std::vector<std::pair<Date, std::shared_ptr<Person>>>()));
        }
        file.close();
    }
    return doctors;
}

std::vector<Dentist> FileSystemManager::FileSystemManager::loadDentists() {
    vector<Dentist> dentists;
    ifstream file;
    string data;
    file.open(dentistsFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            auto arguments = parseString(data);
            dentists.push_back(Dentist(arguments[0], arguments[1], stoi(arguments[2]), arguments[3],
                                       stoi(arguments[4]), stof(arguments[5]),
                                       vector<pair<Date, shared_ptr<Person>>>(), map<string, float>()));
        }
        file.close();
    }
    return dentists;
}

std::vector<Paramedic> FileSystemManager::FileSystemManager::loadParamedics() {
    vector<Paramedic> paramedics;
    ifstream file;
    string data;
    file.open(paramedicsFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            auto arguments = parseString(data);
            paramedics.push_back(Paramedic(arguments[0], arguments[1], stoi(arguments[2]),
                                           arguments[3], stoi(arguments[4]), stof(arguments[5]),
                                           arguments[6], vector<pair<Date, shared_ptr<Person>>>()));
        }
        file.close();
    }
    return paramedics;
}

std::vector<Nurse> FileSystemManager::FileSystemManager::loadNurses() {
    vector<Nurse> nurses;
    ifstream file;
    string data;
    file.open(nursesFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            auto arguments = parseString(data);
            nurses.push_back(Nurse(arguments[0], arguments[1], stoi(arguments[2]), arguments[3],
                                   stoi(arguments[4]), stof(arguments[5]), nullptr));
        }
        file.close();
    }
    return nurses;
}

MedicalRecorder FileSystemManager::FileSystemManager::loadMedicalRecorder() {
    ifstream file;
    string data;
    file.open(medicalRecorderFilename, ios_base::in);
    if (file.is_open()) {
        getline(file, data);
        auto arguments = parseString(data);
        file.close();
        return MedicalRecorder(arguments[0], arguments[1], stoi(arguments[2]), arguments[3],
                               stoi(arguments[4]), stof(arguments[5]), vector<pair<string, pair<Date, shared_ptr<Person>>>>());
    }
    return MedicalRecorder();
}

vector<shared_ptr<Person>> FileSystemManager::FileSystemManager::loadPatients() {
    vector<shared_ptr<Person>> patients;
    ifstream file;
    string data;
    file.open(patientsFilename, ios_base::in);
    if (file.is_open()) {
        while (getline(file, data)) {
            auto arguments = parseString(data);
            patients.push_back(make_shared<Person>(Person(arguments[0], arguments[1], stoi(arguments[2]))));
            
        }
        file.close();
    }
    return patients;
}

void FileSystemManager::FileSystemManager::saveChiefMedicalOfficer(const ChiefMedicalOfficer& chiefMedicalOfficer) {
    ofstream file;
    file.open(chiefMedicalOfficerFilename, ios_base::out);
    if (file.is_open()) {
        file << chiefMedicalOfficer.getName() << " " << chiefMedicalOfficer.getSurname() << " " << chiefMedicalOfficer.getAge() << " " <<
        chiefMedicalOfficer.getEducation() << " " << chiefMedicalOfficer.getExperince() << chiefMedicalOfficer.getSalary() << " " <<
        chiefMedicalOfficer.getSpecialization() << " " << chiefMedicalOfficer.getBudget() << endl;
        file.close();
    }
}

void FileSystemManager::FileSystemManager::saveDoctors(const std::vector<Doctor> doctors) {
    ofstream file;
    file.open(doctorsFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& doctor: doctors) {
            file << doctor.getName() << " " << doctor.getSurname() << " " << doctor.getAge() << " " <<
            doctor.getEducation() << " " << doctor.getExperince() << doctor.getSalary() << " " <<
            doctor.getSpecialization() << " " << doctor.getNumberOfCuredPeople() << endl;
        }
        file.close();
    }
}

void FileSystemManager::FileSystemManager::saveDentsts(const std::vector<Dentist>& dentists) {
    ofstream file;
    file.open(dentistsFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& dentist: dentists) {
            file << dentist.getName() << " " << dentist.getSurname() << " " << dentist.getAge() << " " <<
            dentist.getEducation() << " " << dentist.getExperince() << dentist.getSalary() << endl;
        }
        file.close();
    }
}

void FileSystemManager::FileSystemManager::saveParamedics(const std::vector<Paramedic>& paramedics) {
    ofstream file;
    file.open(paramedicsFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& paramedic: paramedics) {
            file << paramedic.getName() << " " << paramedic.getSurname() << " " << paramedic.getAge() << " " <<
            paramedic.getEducation() << " " << paramedic.getExperince() << paramedic.getSalary() << " " <<
            paramedic.getRegion() << endl;
        }
        file.close();
    }
}

void FileSystemManager::FileSystemManager::saveNurses(const std::vector<Nurse>& nurses) {
    ofstream file;
    file.open(nursesFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& nurse: nurses) {
            file << nurse.getName() << " " << nurse.getSurname() << " " << nurse.getAge() << " " <<
            nurse.getEducation() << " " << nurse.getExperince() << " " << nurse.getSalary() << endl;
        }
        file.close();
    }
}

void FileSystemManager::FileSystemManager::saveMedicalRecorder(const MedicalRecorder& medicalRecorder) {
    ofstream file;
    file.open(medicalRecorderFilename, ios_base::out);
    if (file.is_open()) {
        file << medicalRecorder.getName() << " " << medicalRecorder.getSurname() << " " << medicalRecorder.getAge() << " " <<
        medicalRecorder.getEducation() << " " << medicalRecorder.getExperince() << " " << medicalRecorder.getSalary() << endl;
        file.close();
    }
}

void FileSystemManager::FileSystemManager::savePatients(const vector<shared_ptr<Person>>& patients) {
    ofstream file;
    file.open(patientsFilename, ios_base::out);
    if (file.is_open()) {
        for (auto& patient: patients) {
            file << patient->getName() << " " << patient->getSurname() << " " << patient->getAge() << endl;
        }
        file.close();
    }
}
