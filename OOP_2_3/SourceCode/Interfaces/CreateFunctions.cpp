#include "CreateFunctions.hpp"

using namespace std;

Clinic CreateClinic() {
    cout << "\nЗаполните информацию о главвраче: " << endl;
    auto chiefMedicalOfficer = CreateChiefMedicalOfficer();
    
    cout << "\nВведите количество докторов: ";
    auto numberOfDoctors = CorrectCin<size_t>();
    auto doctors = CreateDoctors(numberOfDoctors);
    
    cout << "\nВведите количество стоматологов: ";
    auto numberOfDentists = CorrectCin<size_t>();
    auto dentists = CreateDentists(numberOfDentists);
    
    cout << "\nВведите количество фельдшеров: ";
    auto numberOfParamedics = CorrectCin<size_t>();
    auto paramedics = CreateParamedics(numberOfParamedics);
    
    cout << "\nВведите количество медсестер: ";
    auto numberOfNurses = CorrectCin<size_t>();
    auto nurses = CreateNurses(numberOfNurses);
    
    cout << "\nЗаполните информацию о медрегистраторе: " << endl;
    auto medicalRecorder = CreateMedicalRecorder();
    
    cout << "\nВведите количество пациентов: ";
    auto numberOfPatients = CorrectCin<size_t>();
    auto patients = CreatePatients(numberOfPatients);
    
    return Clinic(chiefMedicalOfficer, doctors, dentists, paramedics, nurses, medicalRecorder, patients);
}

vector<Doctor> CreateDoctors(size_t numberOfDoctors) {
    vector<Doctor> doctors;
    for (auto i = 0; i < numberOfDoctors; ++i)
        doctors.push_back(CreateDoctor());
    return doctors;
}

vector<Paramedic> CreateParamedics(size_t numberOfParamedics) {
    vector<Paramedic> paramedics;
    for (auto i = 0; i < numberOfParamedics; ++i)
        paramedics.push_back(CreateParamedic());
    return paramedics;
}

vector<Dentist> CreateDentists(size_t numberOfDentists) {
    vector<Dentist> dentists;
    for (auto i = 0; i < numberOfDentists; ++i)
        dentists.push_back(CreateDentist());
    return dentists;
}

vector<Nurse> CreateNurses(size_t numberOfNurses) {
    vector<Nurse> nurses;
    for (auto i = 0; i < numberOfNurses; ++i)
        nurses.push_back(CreateNurse());
    return nurses;
}

vector<shared_ptr<Person>> CreatePatients(size_t numberOfPatients) {
    vector<shared_ptr<Person>> patients;
    for (auto i = 0; i < numberOfPatients; ++i)
        patients.push_back(make_shared<Person>(CreatePerson()));
    return patients;
}

ChiefMedicalOfficer CreateChiefMedicalOfficer() {
    auto topMedicalStaffEmployee = CreateTopMedicalStaffEmployee();
    cout << "Введите бюджет: ";
    auto budget = CorrectCin<float>();
    return ChiefMedicalOfficer(topMedicalStaffEmployee, budget);
}

Doctor CreateDoctor() {
    auto topMedicalStaffEmployee = CreateTopMedicalStaffEmployee();
    cout << "Введите количество пациентов: ";
    auto numberOfPatients = CorrectCin<size_t>();
    auto patients = CreatePatients(numberOfPatients);
    cout << "Введите количество вылеченных людей: ";
    auto numberOfCuredPeople = CorrectCin<int>();
    cout << "Введите количество приемов: ";
    auto numberOfAppointments = CorrectCin<size_t>();
    auto appointments = CreateAppointments(numberOfAppointments);
    return Doctor(topMedicalStaffEmployee, patients, numberOfCuredPeople, appointments);
}

Paramedic CreateParamedic() {
    auto medicalStaffEmployee = CreateMedicalStaffEmployee();
    string region;
    cout << "Введите район, за которым закреплен: ";
    getline(cin, region);
    cout << "Введите количество приемов: ";
    auto numberOfAppointments = CorrectCin<size_t>();
    auto appointments = CreateAppointments(numberOfAppointments);
    return Paramedic(medicalStaffEmployee, region, appointments);
}

Dentist CreateDentist() {
    auto medicalStaffEmployee = CreateMedicalStaffEmployee();
    cout << "Введите количество приемов: ";
    auto numberOfAppointments = CorrectCin<size_t>();
    auto appointments = CreateAppointments(numberOfAppointments);
    cout << "Введите количество услуг: ";
    auto numberOfServices = CorrectCin<size_t>();
    auto priceList = CreatePriceList(numberOfServices);
    return Dentist(medicalStaffEmployee, appointments, priceList);
}

MedicalRecorder CreateMedicalRecorder() {
    auto medicalStaffEmployee = CreateMedicalStaffEmployee();
    cout << "Введите количество приемов: ";
    auto numberOfAppointments = CorrectCin<size_t>();
    auto appointments = CreateRegistrationBook(numberOfAppointments);
    return MedicalRecorder(medicalStaffEmployee, appointments);
}

Nurse CreateNurse(shared_ptr<Doctor> doctor) {
    auto medicalStaffEmployee = CreateMedicalStaffEmployee();
    return Nurse(medicalStaffEmployee, doctor);
}

TopMedicalStaff CreateTopMedicalStaffEmployee() {
    auto medicalStaffEmployee = CreateMedicalStaffEmployee();
    string specialization;
    cout << "Введите специализацию: ";
    getline(cin, specialization);
    return TopMedicalStaff(medicalStaffEmployee, specialization);
}

MedicalStaff CreateMedicalStaffEmployee() {
    Person person;
    bool noErrors = false;
    while (noErrors == false) {
        try {
            person = CreatePerson();
            noErrors = true;
        }
        catch (LessThanZero exception) {
            cout << "Возникло исключение: " << exception.what() << endl;
        }
    }
    string education;
    cout << "Введите образование: ";
    getline(cin, education);
    cout << "Введите опыт работы: ";
    auto experience = CorrectCin<int>();
    cout << "Введите размер заработной платы: ";
    auto salary = CorrectCin<float>();
    return MedicalStaff(person, education, experience, salary);
}

Person CreatePerson() {
    string name;
    string surname;
    cout << "Введите имя: ";
    getline(cin, name);
    cout << "Введите фамилию: ";
    getline(cin, surname);
    cout << "Введите возраст: ";
    auto age = CorrectCin<int>();
    return Person(name, surname, age);
}

vector<pair<string, pair<Date, shared_ptr<Person>>>> CreateRegistrationBook(size_t numberOfAppointments) {
    string name;
    vector<pair<string, pair<Date, shared_ptr<Person>>>> appointments;
    for (auto i = 0; i < numberOfAppointments; ++i) {
        cout << "Введите имя врача: ";
        getline(cin, name);
        auto appointment = CreateAppointment();
        appointments.push_back(make_pair(name, appointment));
    }
    return appointments;
}

vector<pair<Date, shared_ptr<Person>>> CreateAppointments(size_t numberOfAppointments) {
    vector<pair<Date, shared_ptr<Person>>> appointments;
    for (auto i = 0; i < numberOfAppointments; ++i) {
        appointments.push_back(CreateAppointment());
    }
    return appointments;
}

pair<Date, shared_ptr<Person>> CreateAppointment() {
    cout << "Введите дату приема: ";
    auto date = CreateDate();
    cout << "Введите информацию о пациенте: " << endl;
    auto patient = make_shared<Person>(CreatePerson());
    return make_pair(date, patient);
}

map<string, float> CreatePriceList(size_t numberOfServices) {
    map<string, float> services;
    string serviceName;
    bool exists;
    float cost;
    for (auto i = 0; i < numberOfServices; ++i) {
        exists = true;
        cout << "Введите название услуги: ";
        getline(cin, serviceName);
        while (exists) {
            if (services.find(serviceName) != services.end()) {
                cout << "Данная услуга уже существует, введите другое название: ";
                getline(cin, serviceName);
                continue;
            }
            exists = false;
        }
        cout << "Введите стоимость услуги: ";
        cost = CorrectCin<float>();
    }
    return services;
}

Date CreateDate() {
    auto time = CreateTime();
    cout << "Введите день: ";
    auto day = CorrectCin<int>();
    cout << "Введите месяц: ";
    auto month = CorrectCin<int>();
    cout << "Введите год: ";
    auto year = CorrectCin<int>();
    return Date(time, day, month, year);
}

Time CreateTime() {
    cout << "Введите часы: ";
    auto hours = CorrectCin<int>();
    cout << "Введите минуты: ";
    auto minutes = CorrectCin<int>();
    cout << "Введите секунды: ";
    auto seconds = CorrectCin<int>();
    return Time(hours, minutes, seconds);
}
