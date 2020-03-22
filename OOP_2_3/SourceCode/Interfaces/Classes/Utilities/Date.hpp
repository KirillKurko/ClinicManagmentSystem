#ifndef Date_hpp
#define Date_hpp

#include <iostream>
#include "Time.hpp"

class Date {
    friend std::ostream& operator<< (std::ostream& out, const Date& date);
	friend std::istream& operator>> (std::istream& in, Date& date);
private:
    Time time;
    int day;
    int month;
    int year;
public:
    Date(Time time = Time(), int day = 0, int month = 0, int year = 0); 
    Date(const Date& other);
    
    Time getTime() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void setTime(Time time);
	void setDay(int day);
	void setMonth(int month);
    void setYear(int year);
    
    bool operator!= (const Date& other) const;
    bool operator== (const Date& other) const;
    bool operator> (const Date& other) const;
    bool operator< (const Date& other) const;
    
    Date& operator= (const Date& other);
};

#endif
