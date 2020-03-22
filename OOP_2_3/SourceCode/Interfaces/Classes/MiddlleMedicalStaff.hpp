#ifndef MiddlleMedicalStaff_hpp
#define MiddlleMedicalStaff_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "MedicalStaff.hpp"
#include "Utilities/Date.hpp"

class Paramedic : public MiddleMedicalStaff {
private:
    std::string region;
    std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments;
	
	bool dateAssigned(const Date& date) const;
public:
    Paramedic(std::string name = std::string(), std::string surname = std::string(),
              int age = 0, std::string education = std::string(),
              int experience = 0, float salary = 0.0,
              std::string region = std::string(),
              std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments = std::vector<std::pair<Date, std::shared_ptr<Person>>>());
	Paramedic(const MedicalStaff& other, std::string region, std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments);
    Paramedic(const Paramedic& other);
    
	std::string getRegion() const;
	std::vector<std::pair<Date, std::shared_ptr<Person>>> getAppointments() const;
    
	void setRegion(std::string region);
	void setAppointments(std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments);
    
    void addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment);
    void removeAppointment(size_t index);
    std::pair<Date, std::shared_ptr<Person>> getAppointment(size_t index);
    void editAppointmentDate(size_t index);
	
    Paramedic& operator= (const Paramedic& other);
    
    void printInformation() const;
};

class Dentist : public MiddleMedicalStaff {
private:
    std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments;
    std::map<std::string, float> priceList;
	
	bool dateAssigned(const Date& date) const;
public:
    Dentist(std::string name = std::string(), std::string surname = std::string(),
            int age = 0, std::string education = std::string(),
            int experience = 0, float salary = 0.0,
            std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments = std::vector<std::pair<Date, std::shared_ptr<Person>>>(),
			std::map<std::string, float> priceList = std::map<std::string, float>());
	Dentist(const MedicalStaff& other, std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments, std::map<std::string, float> priceList);
    Dentist(const Dentist& other);
    
    std::vector<std::pair<Date, std::shared_ptr<Person>>> getAppointments() const;
    std::map<std::string, float> getPriceList() const;
    
    void setAppointmens(std::vector<std::pair<Date, std::shared_ptr<Person>>> appointments);
	void setPriceList(std::map<std::string, float> priceList);
    
    void addAppointment(std::pair<Date, std::shared_ptr<Person>> appointment);
    void removeAppointment(size_t index);
    std::pair<Date, std::shared_ptr<Person>> getAppointment(size_t index);
    void editAppointmentDate(size_t index);
	
    void addService(std::string name, float cost);
    void removeService(std::string name);
    float getCostOfTheService(std::string name);
    void editPriceOfTheService(std::string name);
    
    Dentist& operator= (const Dentist& other);
    
    void printInformation() const;
};

#endif
