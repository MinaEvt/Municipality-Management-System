//the same as #pragma once, but more portable
#ifndef PERSON_H
#define PERSON_H

//
#include <string>
#include <iostream>

//abstract base class for Citizen and Employee
class Person {

protected:
    std::string name;
    int id;
    std::string address;

public:

    Person(const std::string& name = "", int id = 0, const std::string& address = "");

    virtual ~Person() = default;

    // Getters
    std::string getName() const;
    int getId() const;
    std::string getAddress() const;

    // Setters
    void setName(const std::string& name);
    void setId(int id);
    void setAddress(const std::string& address);

    // Virtual methods for polymorphism
    virtual void display() const = 0;
    virtual std::string getType() const = 0;

    // Operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    bool operator==(const Person& other) const;

    //Validation
    static bool validateName(const std::string& name);
    static bool validateId(int id);
    static bool validateAddress(const std::string& address);

};

#endif // PERSON_H