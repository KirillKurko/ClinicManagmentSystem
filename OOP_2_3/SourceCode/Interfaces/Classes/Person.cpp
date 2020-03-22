#include "Person.hpp"

using namespace std;

Person::Person(string name, string surname, int age) {
    this->name = name;
    this->surname = surname;
	if (age < 0) throw LessThanZero("Возраст не может быть отрицательным");
    this->age = age;
}

Person::Person(const Person& other) {
    name = other.name;
    surname = other.surname;
    age = other.age;
}

string Person::getName() const {
	return name;
}

string Person::getSurname() const {
	return surname;
}

int Person::getAge() const {
	return age;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setSurname(string surname) {
    this->surname = surname;
}

void Person::setAge(int age) {
    this->age = age;
}

Person& Person::operator= (const Person& other) {
    name = other.name;
    surname = other.surname;
    age = other.age;
    return *this;
}

void Person::printInformation() const {
    cout << "\nИмя: " << name << endl
    << "Фамилия: " << surname << endl
    << "Возраст: " << age << endl;
}
