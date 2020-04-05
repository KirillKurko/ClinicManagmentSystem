#ifndef StringParser_hpp
#define StringParser_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::string> parseString(const std::string& data) {
    std::istringstream iss(data);
    std::vector<std::string> arguments((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    return arguments;
}

#endif
