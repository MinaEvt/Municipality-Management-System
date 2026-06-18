#ifndef CITIZEN_H
#define CITIZEN_H

#include "Person.h"
//#include <string> // Already included in Person.h

// Citizen class inherits from Person and adds phone number and email
class Citizen : public Person {

private:
    std::string phoneNumber;
    std::string email;

public:
    Citizen(const std::string& name = "", int id = 0, const std::string& address = "",
            const std::string& phoneNumber = "", const std::string& email = "");

    // Getters
    std::string getPhoneNumber() const;
    std::string getEmail() const;

    // Setters
    void setPhoneNumber(const std::string& phoneNumber);
    void setEmail(const std::string& email);

    // Override virtual methods
    void display() const override;
    std::string getType() const override;

    static bool validatePhoneNumber(const std::string& phoneNumber);
    static bool validateEmail(const std::string& email);

    //operator
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Citizen& c);

};

#endif // CITIZEN_H