#ifndef TopMedicalStaff_hpp
#define TopMedicalStaff_hpp

#include "MedicalStaff.hpp"
#include "Utilities/Date.hpp"
#include <iostream>
#include <vector>
#include <map>

class ChiefMedicalOfficer : public TopMedicalStaff {
private:
    float budget;
public:
    ChiefMedicalOfficer(std::string name = std::string(), std::string surname = std::string(),
                        int age = 0, std::string education = std::string(),
                        int experience = 0, float salary = 0.0,
                        std::string specialization = std::string(), float budget = 0.0);
	ChiefMedicalOfficer(const TopMedicalStaff& other, float budget);
    ChiefMedicalOfficer(const ChiefMedicalOfficer& other);
    
	float getBudget() const;
    
    void setBudget(float budget);
    
    ChiefMedicalOfficer& operator= (const ChiefMedicalOfficer& other);
    
    void printInformation() const;
};

class Doctor : public TopMedicalStaff {
private:
    std::vector<std::shared_ptr<Person>> patients;
    int numberOfCuredPeople;
    std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments;
    
    bool dateAssigned(const Date& date) const;
public:
    Doctor(std::string name = std::string(), std::string surname = std::string(),
           int age = 0, std::string education = std::string(),
           int experience = 0, float salary = 0.0,
           std::string specialization = std::string(),
           std::vector<std::shared_ptr<Person>> patients = std::vector<std::shared_ptr<Person>>(),
           int numberOfCuredPeople =  0,
           std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments = std::vector<std::pair<Date, std::shared_ptr<Person>>>());
	Doctor(const TopMedicalStaff& other, std::vector<std::shared_ptr<Person>> patients,
		   int numberOfCuredPeople, std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments);
    Doctor(const Doctor& other);
    
    std::vector<std::shared_ptr<Person>> getPatients() const;
   	int getNumberOfCuredPeople() const;
    std::vector<std::pair<Date, std::shared_ptr<Person>>> getAppointments() const;
    
    void setPatients(std::vector<std::shared_ptr<Person>> patients);
    void setNumberOfCuredPeople(int numberOfCuredPeople);
    void setAppointments(std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments);
    
    void addPatient(std::shared_ptr<Person> patient);
    void removePatient(size_t index);
    std::shared_ptr<Person> getPatient(size_t index);
    
    void incrementNumberOfCuredPeople();
    
    void addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment);
    void removeAppointment(size_t index);
    std::pair<Date, std::shared_ptr<Person>> getAppointment(size_t index);
    void editAppointment(size_t index);
    
    Doctor& operator= (const Doctor& other);
    
    void printInformation() const;
};

#endif
