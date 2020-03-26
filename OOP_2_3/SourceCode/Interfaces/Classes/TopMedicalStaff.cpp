#include "TopMedicalStaff.hpp"

using namespace std;

extern Logger::FileLogger logger;

ChiefMedicalOfficer::ChiefMedicalOfficer(string name, string surname,
                    int age, string education,
                    int experience, float salary,
                    string specialization, float budget) :
TopMedicalStaff(name, surname, age, education, experience, salary, specialization) {
    this->budget = budget;
}

ChiefMedicalOfficer::ChiefMedicalOfficer(const TopMedicalStaff& other, float budget)
: TopMedicalStaff(other) {
	this->budget = budget;
}

ChiefMedicalOfficer::ChiefMedicalOfficer(const ChiefMedicalOfficer& other) : TopMedicalStaff(other) {
    budget = other.budget;
}

float ChiefMedicalOfficer::getBudget() const {
    return budget;
}

void ChiefMedicalOfficer::setBudget(float budget) {
    this->budget = budget;
}

ChiefMedicalOfficer& ChiefMedicalOfficer::operator= (const ChiefMedicalOfficer& other) {
    TopMedicalStaff::operator=(other);
    budget = other.budget;
    return *this;
}

void ChiefMedicalOfficer::printInformation() const {
    TopMedicalStaff::printInformation();
    cout << "Бюджет: " << budget << endl;
}

Doctor::Doctor(string name, string surname,
			int age, string education,
			int experience, float salary,
			string specialization, std::vector<std::shared_ptr<Person>> patients,
			int numberOfCuredPeople, std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments) :
TopMedicalStaff(name, surname, age, education, experience, salary, specialization) {
    this->patients = patients;
    this->numberOfCuredPeople = numberOfCuredPeople;
    this->appointments = appointments;
}

Doctor::Doctor(const TopMedicalStaff& other, vector<shared_ptr<Person>> patients,
	   int numberOfCuredPeople, vector<pair<Date, shared_ptr<Person>>> appointments)
: TopMedicalStaff(other) {
	this->patients = patients;
	this->numberOfCuredPeople = numberOfCuredPeople;
	this->appointments = appointments;
}

Doctor::Doctor(const Doctor& other) : TopMedicalStaff(other) {
    patients = other.patients;
    numberOfCuredPeople = other.numberOfCuredPeople;
    appointments = other.appointments;
}

std::vector<std::shared_ptr<Person>> Doctor::getPatients() const {
    return patients;
}

int Doctor::getNumberOfCuredPeople() const {
    return numberOfCuredPeople;
}

std::vector<std::pair<Date, std::shared_ptr<Person>>> Doctor::getAppointments() const {
    return appointments;
}

void Doctor::setPatients(std::vector<std::shared_ptr<Person>> patients) {
    this->patients = patients;
}

void Doctor::setNumberOfCuredPeople(int numberOfCuredPeople) {
    this->numberOfCuredPeople = numberOfCuredPeople;
}

void Doctor::setAppointments(std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments) {
    this->appointments = appointments;
}

void Doctor::addPatient(std::shared_ptr<Person> patient) {
    patients.push_back(patient);
}

void Doctor::removePatient(size_t index) {
    try {
        if (index < 0 || index >= patients.size()) throw 1;
        patients.erase(patients.begin() + index);
    }
    catch (int) {
		logger << make_pair(Logger::FileLogger::LOG_ERROR, "Ошибка! Индекс вне диапазона");
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
}

shared_ptr<Person> Doctor::getPatient(size_t index) {
    try {
        if (index < 0 || index >= patients.size()) throw 1;
        return patients[index];
    }
    catch (int) {
		logger << make_pair(Logger::FileLogger::LOG_ERROR, "Ошибка! Индекс вне диапазона");
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
    return nullptr;
}


void Doctor::incrementNumberOfCuredPeople() {
    numberOfCuredPeople++;
}

void Doctor::addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment) {
    appointments.push_back(appointment);
}

void Doctor::removeAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        appointments.erase(appointments.begin() + index);
    }
    catch (int) {
		logger << make_pair(Logger::FileLogger::LOG_ERROR, "Ошибка! Индекс вне диапазона");
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
}

pair<Date, shared_ptr<Person>> Doctor::getAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        return appointments[index];
    }
    catch (int) {
		logger << make_pair(Logger::FileLogger::LOG_ERROR, "Ошибка! Индекс вне диапазона");
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
    return pair<Date, shared_ptr<Person>>();
}

void Doctor::editAppointment(size_t index) {
    
}

Doctor& Doctor::operator= (const Doctor& other) {
    TopMedicalStaff::operator=(other);
    patients = other.patients;
    numberOfCuredPeople = other.numberOfCuredPeople;
    appointments = other.appointments;
    return *this;
}

void Doctor::printInformation() const {
    TopMedicalStaff::printInformation();
    if (patients.size() == 0) cout << "Список пациентов пуст" << endl;
    else {
        cout << "\nПациенты: ";
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << i << ")";
            patients[i]->printInformation();
        }
    }
    cout << "Количество вылеченных людей: " << numberOfCuredPeople << endl;
    if (appointments.size() == 0) cout << "Список приема пуст" << endl;
    else {
        cout << "\nПриемы: ";
        for (size_t i = 0; i < appointments.size(); ++i) {
            cout << i << ") " << appointments[i].first << ":";
            appointments[i].second->printInformation();
        }
    }
}

bool Doctor::dateAssigned(const Date& date) const {
    for (auto& appointment: appointments)
        if (appointment.first == date) return true;
    return false;
}
