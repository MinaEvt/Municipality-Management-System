#include "Citizen.h"
#include <iostream>

// Constructor initializes base class and member variables
Citizen::Citizen(const std::string& name, int id, const std::string& address,
                 const std::string& phoneNumber, const std::string& email)
    : Person(name, id, address), phoneNumber(phoneNumber), email(email) {}

// Getters
std::string Citizen::getPhoneNumber() const {
    return phoneNumber;
}

std::string Citizen::getEmail() const {
    return email;
}

// Setters
void Citizen::setPhoneNumber(const std::string& phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Citizen::setEmail(const std::string& email) {
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
