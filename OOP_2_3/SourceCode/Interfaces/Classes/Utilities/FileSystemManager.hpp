#ifndef FileSystemManager_hpp
#define FileSystemManager_hpp

#include "Clinic.hpp"
#include "StringParser.hpp"

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
        
        ChiefMedicalOfficer loadChiefMedicalOfficer();
        std::vector<Doctor> loadDoctors();
        std::vector<Dentist> loadDentists();
        std::vector<Paramedic> loadParamedics();
        std::vector<Nurse> loadNurses();
        MedicalRecorder loadMedicalRecorder();
        std::vector<std::shared_ptr<Person>> loadPatients();
        
        void saveChiefMedicalOfficer();
        void saveDoctors(const std::vector<Doctor> doctors);
        void saveDentsts(const std::vector<Dentist>& dentists);
        void saveParamedics(const std::vector<Paramedic>& paramedics);
        void saveNurses(const std::vector<Nurse>& nurses);
        void saveMedicalRecorder(const MedicalRecorder& medicalRecorder);
        void savePatients(const std::vector<std::shared_ptr<Person>>& patients);
        
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
        void saveClinic(const Clinic& clinic);
    };
}

#endif
