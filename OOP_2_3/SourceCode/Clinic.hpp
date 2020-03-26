#ifndef Clinic_hpp
#define Clinic_hpp

#include "Interfaces/Classes/TopMedicalStaff.hpp"
#include "Interfaces/Classes/MiddlleMedicalStaff.hpp"
#include "Interfaces/Classes/NursingStaff.hpp"
#include "Interfaces/Classes/Utilities/CorrectCin.hpp"
#include "Interfaces/Classes/Utilities/FileLogger.hpp"

class Clinic {
private:
    ChiefMedicalOfficer chiefMedicalOfficer;
    
    std::vector<Doctor> doctors;
    std::vector<Dentist> dentists;
    std::vector<Paramedic> paramedics;
    std::vector<Nurse> nurses;
    
    MedicalRecorder medicalRecorder;
    std::vector<std::shared_ptr<Person>> patients;
    
public:
    Clinic(ChiefMedicalOfficer chiefMedicalOfficer = ChiefMedicalOfficer(),
           std::vector<Doctor> doctors = std::vector<Doctor>(),
           std::vector<Dentist> dentists = std::vector<Dentist>(),
           std::vector<Paramedic> paramedics = std::vector<Paramedic>(),
           std::vector<Nurse> nurses = std::vector<Nurse>(),
           MedicalRecorder medicalRecorder = MedicalRecorder(),
           std::vector<std::shared_ptr<Person>> patients = std::vector<std::shared_ptr<Person>>());
    Clinic(const Clinic& other);
    
    ChiefMedicalOfficer getChiefMedicalOfficer() const;
    std::vector<Doctor> getDoctors() const;
    std::vector<Dentist> getDentists() const;
    std::vector<Paramedic> getParamedics() const;
    std::vector<Nurse> getNurses() const;
    MedicalRecorder getMedicalRecorder() const;
    std::vector<std::shared_ptr<Person>> getPatients() const;
    
    void setChiefMedicalOfficer(ChiefMedicalOfficer chiefMedicalOfficer);
    void setDoctors(std::vector<Doctor> doctors);
    void setDentists(std::vector<Dentist> dentists);
    void setParamedics(std::vector<Paramedic> paramedics);
    void setNurses(std::vector<Nurse> nurses);
    void setMedicalRecorder(MedicalRecorder medicalRecorder);
    void setPatients(std::vector<std::shared_ptr<Person>> patients);
    
    ChiefMedicalOfficer& getChiefMedicalOfficer();
    Doctor& getDoctor(size_t index);
    Dentist& getDentist(size_t index);
    Paramedic& getParamedic(size_t index);
    Nurse& getNurse(size_t index);
    MedicalRecorder& getMedicalRecorder();
    std::shared_ptr<Person> getPatient(size_t index);
    
    void addDoctor(Doctor doctor);
    void addDentist(Dentist dentist);
    void addParamedic(Paramedic paramedic);
    void addNurse(Nurse nurse);
    void addPatient(std::shared_ptr<Person> patient);
    
    Doctor removeDoctor(size_t index);
    Dentist removeDentist(size_t index);
    Paramedic removeParamedic(size_t index);
    Nurse removeNurse(size_t index);
    std::shared_ptr<Person> removePatient(size_t index);
    
    void printInformation() const;
    void printInformationAboutDoctors() const;
    void printInformationAboutDentists() const;
    void printInformationAboutParamedics() const;
    void printInformationAboutNurses() const;
    void printInformationAboutPatients() const;
};

#endif
