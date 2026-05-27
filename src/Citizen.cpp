#include "Citizen.h"
#include <iostream>
#include <regex>

// Constructor initializes base class and member variables
Citizen::Citizen(const std::string& name, int id, const std::string& address,
                 const std::string& phoneNumber, const std::string& email, std::string countryCode)
    : Person(name, id, address){
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setCountryCode(countryCode);
    }

// Getters
std::string Citizen::getPhoneNumber() const {
    return phoneNumber;
}

std::string Citizen::getEmail() const {
    return email;
}
// added getter for country code
std::string Citizen::getCountryCode() const {
    return countryCode;
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
//added setter for country code 
void Citizen::setCountryCode(const std::string& countryCode) {
    if (!validateCountryCode(countryCode))
        throw std::invalid_argument("Invalid country code: " + countryCode);
    this->countryCode = countryCode;
}

// Override virtual methods
void Citizen::display() const {
    std::cout << "Citizen: " << getName() << ", ID: " << getId() << ", Address: " << getAddress()
              << ", Phone: " << getPhoneNumber() << ", Email: " << getEmail() << ", Country Code: " << getCountryCode() << std::endl;
}

// Return the type of person
std::string Citizen::getType() const {
    return "Citizen";
}

bool Citizen::validatePhoneNumber(const std::string& phoneNumber) {
    std::regex phonePattern(R"(^\s*(?=(?:\D*\d){4,12}\D*$)[\d-]+(?:\s+[\d-]+)*\s*$)"); 
    /*- white spaces allowed at the very front and very back, 
    4-12 digits exluding the separators, 
    only digits and dashes allowed*/ 

    if (phoneNumber.empty())
        return false;
    if (!std::regex_match(phoneNumber, phonePattern))
        return false;
    return true;
}

bool Citizen::validateEmail(const std::string& email) {
    //Email should not be empty or too long (64 cap for local, 254 cap total)
    if (email.empty() || email.length() > 254)
        return false;
    size_t atPos = email.find('@');
    if (atPos == std::string::npos)
        return false;
    std::string localPart = email.substr(0, atPos);
    if (localPart.length() > 64)
        return false;
    std::regex emailPattern(R"(^ ?[\w.!#$%&'*+=?^_`{|}~-]{1,64}@([\w-]+\.)+[a-zA-Z]{2,4} ?$)"); 
    /* - white spaces allowed at the very front and very back, 
    1-64 characters before @, 1-254 characters total, 
    domain name with 2-4 characters */

    //Email should match the pattern
    if (!std::regex_match(email, emailPattern))
        return false;
    return true;
}

bool Citizen::validateCountryCode(const std::string& countryCode) {

    std::regex countryCodePattern(R"(^\+(\d{1,3}|\d{1}-\d{3})$)");
    /* accepts country codes with a strict pattern in both popular 
    formats - +1, +44, +123, +1-385, +359, +1-374, еtc*/

    // Country code should not be empty
    if (countryCode.empty())
        return false;

    // Country code should start with a plus sign followed by digits, match the pattern
    if (!std::regex_match(countryCode, countryCodePattern))
        return false;
    return true;
}
