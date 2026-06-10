#include "Employee.h"
#include <iostream>
#include <iomanip>

Employee::Employee(const std::string& name, int id, const std::string& address,
                   const std::string& role, const std::string& department, double salary)
    : Person(name, id, address), role(role), department(department), salary(salary) {}

// Getters
std::string Employee::getRole() const {
    return role;
}
std::string Employee::getDepartment() const {
    return department;
}
double Employee::getSalary() const {
    return salary;
}

// Setters
void Employee::setRole(const std::string& role) {
    if(role.empty())
        throw std::invalid_argument("Role cannot be empty!");
    this->role = role;
}
void Employee::setDepartment(const std::string& department) {
    if (department.empty())
        throw std::invalid_argument("Department cannot be empty!");
    this->department = department;
}
void Employee::setSalary(double salary) {
    if (salary < 0)
        std::cerr << "Salary cannot be a negative number!";
    this->salary = salary;
}

// Override virtual methods
void Employee::display() const {
    std::cout << "Employee: " << getName() << ", ID: " << getId() << ", Address: " << getAddress()
              << ", Role: " << getRole() << ", Department: " << getDepartment()
              << ", Salary: $" << std::fixed << std::setprecision(2) << getSalary() << std::endl;
}

// Return the type of person
std::string Employee::getType() const {
    return "Employee";
}

std::string Employee::toString() const {
    return Person::toString() + "," + role + "," + department + "," + std::to_string(salary);
}
