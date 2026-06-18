#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
//#include <string> // Already included in Person.h

// Employee class inherits from Person and adds role, department, and salary
class Employee : public Person {

private:
    std::string role;
    std::string department;
    double salary;

public:

// Constructor initializes base class and member variables
    Employee(const std::string& name = "", int id = 0, const std::string& address = "",
             const std::string& role = "", const std::string& department = "", double salary = 0.0);

    // Getters
    std::string getRole() const;
    std::string getDepartment() const;
    double getSalary() const;

    // Setters
    void setRole(const std::string& role);
    void setDepartment(const std::string& department);
    void setSalary(double salary);

    // Override virtual methods
    void display() const override;
    std::string getType() const override;
    std::string toString() const override;
};

#endif // EMPLOYEE_H