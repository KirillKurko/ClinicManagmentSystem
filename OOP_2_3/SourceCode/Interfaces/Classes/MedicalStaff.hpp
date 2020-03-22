#ifndef MedicalStaff_hpp
#define MedicalStaff_hpp

#include "Person.hpp"
#include <iostream>
#include <string>

class MedicalStaff : public Person {
protected:
    std::string education;
    int experience;
    float salary;
public:
    MedicalStaff(std::string name = std::string(), std::string surname = std::string(),
                 int age = 0, std::string education = std::string(),
                 int experience = 0, float salary = 0.0);
	MedicalStaff(const Person& other, std::string education, int experience, float salary);
    MedicalStaff(const MedicalStaff& other);
    
    std::string getEducation() const;
    int getExperince() const;
	float getSalary() const;
    
    void setEducation(std::string education);
    void setExperience(int experience);
    void setSalary(int salary);
    
    MedicalStaff& operator= (const MedicalStaff& other);
    
    void printInformation() const;
};

class TopMedicalStaff : public MedicalStaff {
protected:
    std::string specialization;
public:
    TopMedicalStaff(std::string name = std::string(), std::string surname = std::string(),
                    int age = 0, std::string education = std::string(),
                    int experience = 0, float salary = 0.0,
                    std::string specialization = std::string());
	TopMedicalStaff(const MedicalStaff& other, std::string specialization);
    TopMedicalStaff(const TopMedicalStaff& other);
    
    std::string getSpecialization() const;
    
    void setSpecialization(std::string specialization);
    
    TopMedicalStaff& operator= (const TopMedicalStaff& other);
    
    void printInformation() const;
};

class MiddleMedicalStaff : public MedicalStaff {
public:
    MiddleMedicalStaff(std::string name = std::string(), std::string surname = std::string(),
                    int age = 0, std::string education = std::string(),
					int experience = 0, float salary = 0.0);
	MiddleMedicalStaff(const MedicalStaff& other);
    MiddleMedicalStaff(const MiddleMedicalStaff& other);
    
    MiddleMedicalStaff& operator= (const MiddleMedicalStaff& other);
};

class NursingStaff : public MedicalStaff {
public:
    NursingStaff(std::string name = std::string(), std::string surname = std::string(),
                       int age = 0, std::string education = std::string(),
                       int experience = 0, float salary = 0.0);
	NursingStaff(const MedicalStaff& other);
    NursingStaff(const NursingStaff& other);
    
    NursingStaff& operator= (const NursingStaff& other);
};

#endif
