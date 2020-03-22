#include "Date.hpp"

Date::Date(Time time, int day, int month, int year) {
    this->time = time;
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date& other) {
    time = other.time;
    day = other.day;
    month = other.month;
    year = other.year;
}

Time Date::getTime() const {
    return time;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setTime(Time time) {
    this->time = time;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

bool Date::operator!= (const Date& other) const {
    return time != other.time || day != other.day || month != other.month || year != other.year;
}

bool Date::operator== (const Date& other) const {
    return !(*this != other);
}

bool Date::operator> (const Date& other) const {
    return year > other.year ? true :
    month > other.month ? true :
    day > other.day ? true :
    time > other.time ? true : false;
}

bool Date::operator< (const Date& other) const {
    return year < other.year ? true :
    month < other.month ? true :
    day < other.day ? true :
    time < other.time ? true : false;
}

Date& Date::operator=(const Date& other) {
    time = other.time;
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Date& date) {
    out << date.time << " " << date.day << "." << date.month << "." << date.year;
    return out;
}

std::istream& operator>> (std::istream& in, Date& date) {
	in >> date.time >> date.day >> date.month >> date.year;
	return in;
}
