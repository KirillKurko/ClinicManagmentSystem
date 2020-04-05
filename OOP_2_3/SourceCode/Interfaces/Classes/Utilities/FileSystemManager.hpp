#ifndef FileSystemManager_hpp
#define FileSystemManager_hpp

#include "Clinic.hpp"

ChiefMedicalOfficer chiefMedicalOfficer;

std::vector<Doctor> doctors;
std::vector<Dentist> dentists;
std::vector<Paramedic> paramedics;
std::vector<Nurse> nurses;

MedicalRecorder medicalRecorder;
std::vector<std::shared_ptr<Person>> patients;

namespace FileSystemManager {
    
    class FileSystemManager {
    private:
        
    public:
    };
}

#endif
