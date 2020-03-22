#ifndef Time_hpp
#define Time_hpp

#include <iostream>

class Time {
    friend std::ostream& operator<< (std::ostream& out, const Time& time);
	friend std::istream& operator>> (std::istream& in, Time& time);
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    Time(const Time& other);
    
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    
    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);
    
    bool operator!= (const Time& other) const;
    bool operator== (const Time& other) const;
    bool operator> (const Time& other) const;
    bool operator< (const Time& other) const;
    
    Time& operator= (const Time& other);
};

#endif
