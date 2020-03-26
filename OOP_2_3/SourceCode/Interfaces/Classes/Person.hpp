#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <string>
#include "Utilities/Exceptions/LessThanZeroException.hpp"
#include "Utilities/FileLogger.hpp"

class Person {
protected:
    std::string name;
    std::string surname;
    int age;
public:
    Person(std::string name = std::string(), std::string surname = std::string(), int age = 0);
    Person(const Person& other);
    
	std::string getName() const;
	std::string getSurname() const;
	int getAge() const;
    
    void setName(std::string name);
    void setSurname(std::string surname);
    void setAge(int age);
    
    Person& operator= (const Person& other);
    
    void printInformation() const;
};

#endif
