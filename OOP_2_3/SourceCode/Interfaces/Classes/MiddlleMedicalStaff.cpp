#include "MiddlleMedicalStaff.hpp"

using namespace std;

Paramedic::Paramedic(string name, string surname,
        int age, string education,
        int experience, float salary,
        string region,
        vector<pair<Date, shared_ptr<Person>>> appointments)
: MiddleMedicalStaff(name, surname, age, education, experience, salary) {
    this->region = region;
    this->appointments = appointments;
}

Paramedic::Paramedic(const MedicalStaff& other, string region, vector<pair<Date, shared_ptr<Person>>> appointments)
: MiddleMedicalStaff(other) {
	this->region = region;
	this->appointments = appointments;
}


Paramedic::Paramedic(const Paramedic& other) : MiddleMedicalStaff(other) {
    region = other.region;
    appointments = other.appointments;
}

std::string Paramedic::getRegion() const {
    return region;
}

std::vector<std::pair<Date, std::shared_ptr<Person>>> Paramedic::getAppointments() const {
    return appointments;
}

void Paramedic::setRegion(std::string region) {
    this->region = region;
}

void Paramedic::setAppointments(std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments) {
    this->appointments = appointments;
}

void Paramedic::addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment) {
    appointments.push_back(appointment);
}

void Paramedic::removeAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        appointments.erase(appointments.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
}

std::pair<Date, std::shared_ptr<Person>> Paramedic::getAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        return appointments[index];
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
    return pair<Date, shared_ptr<Person>>();
}

void Paramedic::editAppointmentDate(size_t index) {
	try {
		if (index < 0 || index >= appointments.size()) throw 1;
		cout << "Введите новую дату приема: ";
		Date date;
		cin >> date;
		while (dateAssigned(date)) {
			cout << "Новая дата приема занята, повторите ввод даты: ";
			cin >> date;
		}
		appointments[index].first = date;
	}
	catch (int) {
		cout << "Ошибка! Индекс вне диапазона" << endl;
	}
}

bool Paramedic::dateAssigned(const Date& date) const {
	for (auto& appointment: appointments) {
		if (appointment.first == date) return true;
	}
	return false;
}

Paramedic& Paramedic::operator= (const Paramedic& other) {
    MiddleMedicalStaff::operator=(other);
    region = other.region;
    appointments = other.appointments;
    return *this;
}

void Paramedic::printInformation() const {
    MiddleMedicalStaff::printInformation();
    cout << "Закрепленный район: " << region << endl;
    if (appointments.size() == 0) cout << "Список приема пуст" << endl;
    else {
        cout << "\nПриемы: ";
        for (size_t i = 0; i < appointments.size(); ++i) {
            cout << i << ") " << appointments[i].first << ":";
            appointments[i].second->printInformation();
        }
    }
}

Dentist::Dentist(string name, string surname,
        int age, string education,
        int experience, float salary,
        vector<pair<Date, shared_ptr<Person>>> appointments,
        map<string, float> priceList) :
MiddleMedicalStaff(name, surname, age, education, experience, salary) {
    this->appointments = appointments;
    this->priceList = priceList;
}

Dentist::Dentist(const MedicalStaff& other, std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments, std::map<std::string, float> priceList)
: MiddleMedicalStaff(other) {
	this->appointments = appointments;
	this->priceList = priceList;
}

Dentist::Dentist(const Dentist& other) : MiddleMedicalStaff(other) {
    appointments = other.appointments;
    priceList = other.priceList;
}

vector<pair<Date, shared_ptr<Person>>> Dentist::getAppointments() const {
    return appointments;
}

std::map<std::string, float> Dentist::getPriceList() const {
    return priceList;
}

void Dentist::setAppointmens(vector<std::pair<Date, shared_ptr<Person>>> appointments) {
    this->appointments = appointments;
}

void Dentist::setPriceList(map<string, float> priceList) {
    this->priceList = priceList;
}

void Dentist::addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment) {
    appointments.push_back(appointment);
}

void Dentist::removeAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        appointments.erase(appointments.begin() + index);
    }
    catch (int) {
        cout << "Ошибка! Индекс вне диапазона" << endl;
    }
}

pair<Date, shared_ptr<Person>> Dentist::getAppointment(size_t index) {
    try {
        if (index < 0 || index >= appointments.size()) throw 1;
        return appointments[index];
    }
    catch (int) {
        cout << "Ошибка! Индекст вне диапазона" << endl;
    }
    return pair<Date, shared_ptr<Person>>();
}

void Dentist::editAppointmentDate(size_t index) {
	try {
		if (index < 0 || index >= appointments.size()) throw 1;
		cout << "Введите новую дату приема: ";
		Date date;
		cin >> date;
		while (dateAssigned(date)) {
			cout << "Новая дата приема занята, повторите ввод даты: ";
			cin >> date;
		}
		appointments[index].first = date;
	}
	catch (int) {
		cout << "Ошибка! Индекс вне диапазона" << endl;
	}
}

bool Dentist::dateAssigned(const Date& date) const {
	for (auto& appointment: appointments) {
		if (appointment.first == date) return true;
	}
	return false;
}

void Dentist::addService(string name, float cost) {
    priceList[name] = cost;
}

void Dentist::removeService(string name) {
    auto service = priceList.find(name);
    if (service != priceList.end())
        priceList.erase(service);
    else cout << "Нет услуги с данным наименованием" << endl;
}

float Dentist::getCostOfTheService(string name) {
    auto service = priceList.find(name);
    if (service != priceList.end())
        return priceList[name];
    else cout << "Нет услуги с данным наименованием" << endl;
    return 0.0;
}

void Dentist::editPriceOfTheService(string name) {
    auto service = priceList.find(name);
    if (service != priceList.end()) {
        float price;
        cout << "Введите новую стоимость услуги: ";
        cin >> price;
        priceList[name] = price;
    }
    else cout << "Нет услуги с данным наименованием" << endl;
}

Dentist& Dentist::operator= (const Dentist& other) {
    MiddleMedicalStaff::operator=(other);
    appointments = other.appointments;
    priceList = other.priceList;
    return *this;
}

void Dentist::printInformation() const {
    MiddleMedicalStaff::printInformation();
    if (appointments.size() == 0) cout << "Список приема пуст" << endl;
    else {
        cout << "\nПриемы: ";
        for (size_t i = 0; i < appointments.size(); ++i) {
            cout << i << ") " << appointments[i].first << ":";
            appointments[i].second->printInformation();
        }
    }
    if (priceList.size() == 0) cout << "Список услуг пуст" << endl;
    else {
        cout << "Список услуг: ";
        for (auto& service: priceList)
            cout << service.first << " - " << service.second << endl;
    }
}
