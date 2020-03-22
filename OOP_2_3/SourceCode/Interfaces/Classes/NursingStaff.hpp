#ifndef NursingStaff_hpp
#define NursingStaff_hpp

#include "Person.hpp"
#include "MedicalStaff.hpp"
#include "TopMedicalStaff.hpp"
#include "Utilities/Date.hpp"
#include <string>
#include <iostream>
#include <vector>

class MedicalRecorder : public NursingStaff {
private:
    std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> appointments;
public:
    MedicalRecorder(std::string name = std::string(), std::string surname = std::string(),
                    int age = 0, std::string education = std::string(),
                    int experience = 0, float salary = 0.0,
                    std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> appointments =
                    std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>>());
    MedicalRecorder(const NursingStaff& other, std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> appointments);
    MedicalRecorder(const MedicalRecorder& other);
    
    std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> getAppointments() const;
    
    void setAppointments(std::vector<std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>>> appointments);
    
    void addAppointment(std::pair<std::string, std::pair<Date, std::shared_ptr<Person>>> appointment);
    void removeAppointment(size_t index);

    MedicalRecorder& operator= (const MedicalRecorder& other);
    
    void printInformation() const;
};

class Nurse : public NursingStaff {
private:
    std::shared_ptr<Doctor> doctor;
public:
    Nurse(std::string name = std::string(), std::string surname = std::string(),
          int age = 0, std::string education = std::string(),
          int experience = 0, float salary = 0.0,
          std::shared_ptr<Doctor> doctor = std::shared_ptr<Doctor>());
    Nurse(const NursingStaff& other, std::shared_ptr<Doctor> doctor);
    Nurse(const Nurse& other);
    
    std::shared_ptr<Doctor> getDoctor() const;
    
    void setDoctor(std::shared_ptr<Doctor> doctor);
    
    Nurse& operator= (const Nurse& other);
    
    void printInformation() const;
};

#endif
