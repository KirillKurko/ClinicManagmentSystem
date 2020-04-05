#ifndef FileSystemManager_hpp
#define FileSystemManager_hpp

#include "Clinic.hpp"

//ChiefMedicalOfficer chiefMedicalOfficer;
//
//std::vector<Doctor> doctors;
//std::vector<Dentist> dentists;
//std::vector<Paramedic> paramedics;
//std::vector<Nurse> nurses;
//
//MedicalRecorder medicalRecorder;
//std::vector<std::shared_ptr<Person>> patients;

namespace FileSystemManager {
    
    class FileSystemManager {
    private:
        std::string chiefMedicalOfficerFilename;
        std::string doctorsFilename;
        std::string dentistsFilename;
        std::string paramedicsFilename;
        std::string nursesFulename;
        std::string medicalRecorderFilename;
        std::string patientsFilename;
        
        
    public:
        FileSystemManager() = default;
        FileSystemManager(std::string chiefMedicalOfficerFilename,
                          std::string doctorsFilename,
                          std::string dentistsFilename,
                          std::string paramedicsFilename,
                          std::string nursesFulename,
                          std::string medicalRecorderFilename,
                          std::string patientsFilename);
        
        Clinic loadClinic();
        
        std::vector<std::shared_ptr<Person>> loadPatients();
        void savePatients(const std::vector<std::shared_ptr<Person>>& patients);
        
    };
}

#endif
