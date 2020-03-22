#include "Time.hpp"

Time::Time(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

Time::Time(const Time& other) {
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return  minutes;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setHours(int hours) {
    this->hours = hours;
}

void Time::setMinutes(int minutes) {
    this->minutes = minutes;
}

void Time::setSeconds(int seconds) {
    this->seconds = seconds;
}

bool Time::operator!= (const Time& other) const {
    return hours != other.hours || minutes != other.minutes || seconds != other.seconds;
}

bool Time::operator== (const Time& other) const {
    return !(*this != other);
}

bool Time::operator> (const Time& other) const {
    return hours > other.hours ? true :
    minutes > other.minutes ? true :
    seconds > other.seconds ? true : false;
}

bool Time::operator< (const Time& other) const {
    return (hours < other.hours) ? true :
    (minutes < other.minutes) ? true :
    (seconds < other.seconds) ? true : false;
}

Time& Time::operator= (const Time& other) {
    hours = other.hours;
    minutes = other.minutes;
    seconds = other.seconds;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Time& time) {
    out << time.hours << ":" << time.minutes << ":" << time.seconds;
    return out;
}

std::istream& operator>> (std::istream& in, Time& time) {
	in >> time.hours >> time.minutes >> time.seconds;
	return in;
}

