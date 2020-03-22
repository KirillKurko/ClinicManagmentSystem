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
