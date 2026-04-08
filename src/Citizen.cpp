#include "Citizen.h"
#include <iostream>

// Constructor initializes base class and member variables
Citizen::Citizen(const std::string& name, int id, const std::string& address,
                 const std::string& phoneNumber, const std::string& email)
    : Person(name, id, address){
    setPhoneNumber(phoneNumber);
    setEmail(email);
    }

// Getters
std::string Citizen::getPhoneNumber() const {
    return phoneNumber;
}

std::string Citizen::getEmail() const {
    return email;
}

// Setters
void Citizen::setPhoneNumber(const std::string& phoneNumber) {
    if (!validatePhoneNumber(phoneNumber))
        throw std::invalid_argument("Invalid phone number: " + phoneNumber);
    this->phoneNumber = phoneNumber;
}

void Citizen::setEmail(const std::string& email) {
    if (!validateEmail(email))
        throw std::invalid_argument("Invalid email: " + email);
    this->email = email;
}

// Override virtual methods
void Citizen::display() const {
    std::cout << "Citizen: " << getName() << ", ID: " << getId() << ", Address: " << getAddress()
              << ", Phone: " << getPhoneNumber() << ", Email: " << getEmail() << std::endl;
}

// Return the type of person
std::string Citizen::getType() const {
    return "Citizen";
}

bool Citizen::validatePhoneNumber(const std::string& phoneNumber){
    //Phone number should not be empty and should contain only digits and dashes
    if (phoneNumber.empty())
        return false;
    for (size_t i = 0; i < phoneNumber.length(); ++i){
        if(!std::isdigit(phoneNumber[i]) && phoneNumber[i] != ' ')
            return false;
    }
    return true;
}

bool Citizen::validateEmail(const std::string& email){
    //Email should not be empty and should contain @ and .
    if (email.empty())
        return false;
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.');
    if (atPos == std::string::npos || dotPos == std::string::npos || atPos >= dotPos)
        return false;
    return true;
}
