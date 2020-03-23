#ifndef Menu_hpp
#define Menu_hpp

#include "CreateFunctions.hpp"

int mainMenu();

void viewMenu();
void viewDoctors();
void viewParamedics();
void viewDentist();
void viewNurses();
void viewPatients();

void search();
void searchDoctors();
void searchDentists();
void searchParamedics();
void searchNurses();
void searchPatients();

void edit();
void editChiefMedicalOfficer(ChiefMedicalOfficer& chiefMedicalOfficer);
void editDoctor(Doctor& doctor);
void editDentist(Dentist& dentist);
void editParamedic(Paramedic& paramedic);
void editMedicalRecorder(MedicalRecorder& medicalRecorder);
void editNurse(Nurse& nurse);
void editPatient(std::shared_ptr<Person> patient);

void add();
void remove();

void task();


#endif 
