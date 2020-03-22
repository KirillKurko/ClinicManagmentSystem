#include "MedicalStaff.hpp"

using namespace std;

MedicalStaff::MedicalStaff(string name, string surname,
                           int age, string education,
                           int experience, float salary) : Person(name, surname, age) {
    this->education = education;
    this->experience = experience;
    this->salary = salary;
}

MedicalStaff::MedicalStaff(const Person& other, string education, int experience, float salary)
: Person(other) {
	this->education = education;
	this->experience = experience;
	this->salary = salary;
}

MedicalStaff::MedicalStaff(const MedicalStaff& other) : Person(other) {
    education = other.education;
    experience = other.experience;
    salary = other.salary;
}

string MedicalStaff::getEducation() const {
    return education;
}

int MedicalStaff::getExperince() const {
    return experience;
}

float MedicalStaff::getSalary() const {
    return salary;
}

void MedicalStaff::setEducation(string education) {
    this->education = education;
}

void MedicalStaff::setExperience(int experience) {
    this->experience = experience;
}

void MedicalStaff::setSalary(int salary) {
    this->salary = salary;
}

MedicalStaff& MedicalStaff::operator= (const MedicalStaff& other) {
    Person::operator=(other);
    education = other.education;
    experience = other.experience;
    salary = other.salary;
    return *this;
}

void MedicalStaff::printInformation() const {
    Person::printInformation();
    cout << "Образование: " << education << endl
    << "Опыт работы: " << experience << endl
    << "Зарплата: " << salary << endl;
}

TopMedicalStaff::TopMedicalStaff(string name, string surname,
                int age, string education,
                int experience, float salary,
                string specialization) :
MedicalStaff(name, surname, age, education, experience, salary) {
    this->specialization = specialization;
}

TopMedicalStaff::TopMedicalStaff(const MedicalStaff& other, string specialization)
: MedicalStaff(other) {
	this->specialization = specialization;
}

TopMedicalStaff::TopMedicalStaff(const TopMedicalStaff& other) : MedicalStaff(other) {
    specialization = other.specialization;
}

string TopMedicalStaff::getSpecialization() const {
    return specialization;
}

void TopMedicalStaff::setSpecialization(string specialization) {
    this->specialization = specialization;
}

TopMedicalStaff& TopMedicalStaff::operator= (const TopMedicalStaff& other) {
    MedicalStaff::operator=(other);
    specialization = other.specialization;
    return *this;
}

void TopMedicalStaff::printInformation() const {
    MedicalStaff::printInformation();
    cout << "Специализация: " << specialization << endl;
}

MiddleMedicalStaff::MiddleMedicalStaff(string name, string surname,
                   int age, string education,
                   int experience, float salary) :
MedicalStaff(name, surname, age, education, experience, salary) {
    
}

MiddleMedicalStaff::MiddleMedicalStaff(const MedicalStaff& other) : MedicalStaff(other) {
	
}

MiddleMedicalStaff::MiddleMedicalStaff(const MiddleMedicalStaff& other) : MedicalStaff(other) {
    
}

MiddleMedicalStaff& MiddleMedicalStaff::operator= (const MiddleMedicalStaff& other) {
    MedicalStaff::operator=(other);
    return *this;
}

NursingStaff::NursingStaff(string name, string surname,
             int age, string education,
             int experience, float salary) :
MedicalStaff(name, surname, age, education, experience, salary) {
    
}

NursingStaff::NursingStaff(const MedicalStaff& other) : MedicalStaff(other) {
	
}

NursingStaff::NursingStaff(const NursingStaff& other) : MedicalStaff(other) {
    
}

NursingStaff& NursingStaff::operator= (const NursingStaff& other) {
    MedicalStaff::operator=(other);
    return *this;
}
