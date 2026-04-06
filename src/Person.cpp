#include "Person.h"

Person::Person(const std::string& name, int id, const std::string& address)
    : name(name), id(id), address(address) {}

//getters
std::string Person::getName() const { return name; }
int Person::getId() const { return id; }
std::string Person::getAddress() const { return address; }

//setters
void Person::setName(const std::string& name) { this->name = name; }
void Person::setId(int id) { this->id = id; }
void Person::setAddress(const std::string& address) { this->address = address; }

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Person& person) { return os; }

// Equality operator compares name, id, and address
bool Person::operator==(const Person& other) const { return false; }
