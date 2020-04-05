#include "FileSystemManager.hpp"

using namespace std;

vector<shared_ptr<Person>> FileSystemManager::FileSystemManager::loadPatients() {
    vector<shared_ptr<Person>> patients;
    ifstream file;
    string data;
    file.open(patientsFilename, ios_base::in);
    while (getline(file, data)) {
        auto arguments = parseString(data);
        patients.push_back(make_shared<Person>(Person(arguments[0], arguments[1], stoi(arguments[2]))));
        
    }
    file.close();
    return patients;
}

void FileSystemManager::FileSystemManager::savePatients(const vector<shared_ptr<Person>>& patients) {
    ofstream file;
    file.open(patientsFilename, ios_base::out);
    for (auto patient: patients) {
        file << patient->getName() << " " << patient->getSurname() << " " << patient->getAge() << endl;
    }
    file.close();
}

FileSystemManager::FileSystemManager::FileSystemManager(string chiefMedicalOfficerFilename,
                  string doctorsFilename, string dentistsFilename, string paramedicsFilename,
                  string nursesFulename, string medicalRecorderFilename, string patientsFilename) {
    this->chiefMedicalOfficerFilename = chiefMedicalOfficerFilename;
    this->doctorsFilename = doctorsFilename;
    this->dentistsFilename = dentistsFilename;
    this->paramedicsFilename = paramedicsFilename;
    this->nursesFulename = nursesFulename;
    this->medicalRecorderFilename = medicalRecorderFilename;
    this->patientsFilename = patientsFilename;
}

Clinic FileSystemManager::FileSystemManager::loadClinic() {
    auto chiefMedicalOfficer = 
    auto patients = loadPatients();
    return Clinic()
}
