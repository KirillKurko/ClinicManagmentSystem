#ifndef CreateFunctions_hpp
#define CreateFunctions_hpp

#include "Clinic.hpp"
#include "Classes/Utilities/CorrectCin.hpp"
#include "Classes/Utilities/FileLogger.hpp"

Clinic CreateClinic();

std::vector<Doctor> CreateDoctors(size_t numberOfDoctors);
std::vector<Paramedic> CreateParamedics(size_t numberOfParamedics);
std::vector<Dentist> CreateDentists(size_t numberOfDentists);
std::vector<Nurse> CreateNurses(size_t numberOfNurses);
std::vector<std::shared_ptr<Person>> CreatePatients(size_t numberOfPatients);

ChiefMedicalOfficer CreateChiefMedicalOfficer();
Doctor CreateDoctor();
Paramedic CreateParamedic();
Dentist CreateDentist();
MedicalRecorder CreateMedicalRecorder();
Nurse CreateNurse(std::shared_ptr<Doctor> doctor = nullptr);

TopMedicalStaff CreateTopMedicalStaffEmployee();
MedicalStaff CreateMedicalStaffEmployee();
Person CreatePerson();

std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> CreateRegistrationBook(size_t numberOfAppointments);
std::vector<std::pair<Date, std::shared_ptr<Person>>> CreateAppointments(size_t numberOfAppointments);
std::pair<Date, std::shared_ptr<Person>> CreateAppointment();

std::map<std::string, float> CreatePriceList(size_t numberOfServices);

Date CreateDate();
Time CreateTime();

#endif
