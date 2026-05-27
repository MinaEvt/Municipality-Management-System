#ifndef CITIZEN_H
#define CITIZEN_H

#include "Person.h"
//#include <string> // Already included in Person.h

// Citizen class inherits from Person and adds phone number and email
class Citizen : public Person {

private:
    std::string phoneNumber;
    std::string email;
    std::string countryCode; // New member variable for country code

public:
    Citizen(const std::string& name = "", int id = 0, const std::string& address = "",
            const std::string& phoneNumber = "", const std::string& email = "", std::string countryCode = "+359");

    // Getters
    std::string getPhoneNumber() const;
    std::string getEmail() const;
    std::string getCountryCode() const;

    // Setters
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);
    void setCountryCode(const std::string& countryCode);

    // Override virtual methods
    void display() const override;
    std::string getType() const override;

    static bool validatePhoneNumber(const std::string& phoneNumber);
    static bool validateEmail(const std::string& email);
    static bool validateCountryCode(const std::string& countryCode);
};

#endif // CITIZEN_H