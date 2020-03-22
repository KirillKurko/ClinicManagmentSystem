#include "LessThanZeroException.hpp"

LessThanZero::LessThanZero(std::string message) {
    this->message = message;
}

std::string LessThanZero::what() const {
    return message;
}
