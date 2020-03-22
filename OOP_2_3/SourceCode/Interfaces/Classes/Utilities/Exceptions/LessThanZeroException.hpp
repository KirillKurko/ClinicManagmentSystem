#ifndef LessThanZeroException_hpp
#define LessThanZeroException_hpp

#include <iostream>
#include <string>

class LessThanZero {
private:
    std::string message;
public:
    LessThanZero(std::string message);
    
    std::string what() const;
};

#endif
