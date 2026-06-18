#include "Person.h"

Person::Person(const std::string& name, int id, const std::string& address) {
    setName(name);
    setId(id);
    setAddress(address);
}

//getters
std::string Person::getName() const { 
    return name; 
}
int Person::getId() const {
     return id; 
    }
std::string Person::getAddress() const {
     return address; 
    }

//setters
void Person::setName(const std::string& name) { 
    if (!validateName(name))
        throw std::invalid_argument("Invalid name: " + name);
    this->name = name; 
}
void Person::setId(int id) { 
    if (!validateId(id))
        throw std::invalid_argument("Invalid ID: " + std::to_string(id));
    this->id = id; 
}
void Person::setAddress(const std::string& address) { 
    if (!validateAddress(address))
        throw std::invalid_argument("Invalid address: " + address);
    this->address = address; }

// Operator overloading
std::ostream& operator<<(std::ostream& os, const Person& person) { 
    os << person.getType() << ": " << person.getName() << ", ID: " << person.getId() 
       << ", Address: " << person.getAddress();
    return os; 
}

// Equality operator compares name, id, and address
bool Person::operator==(const Person& other) const { 
    
    return name == other.name && id == other.id && address == other.address; 
}

bool Person::validateName(const std::string& name) {
    // Example validation: Name should not be empty and should not contain only spaces

   if (name.empty())
    return false;
   

   if(name.find_first_not_of(' ')==std::string::npos)
    return false;
   

    //name should not contain numbers or special characters
   for (size_t i = 0; i < name.length(); ++i) {
       if (!std::isalpha(name[i]) && name[i] != ' ')
            return false;
    }
    return true;
}

bool Person::validateId(int id) {
    // Example validation: ID should be a positive integer
    return id > 0;
}

bool Person::validateAddress(const std::string& address) {
    // Example validation: Address should not be empty and should not contain only spaces
    return !address.empty() && address.find_first_not_of(' ') != std::string::npos;
}

std::string Person::toString() const {
    return getType() + "," + getName() + "," + std::to_string(getId()) + "," + getAddress();
}
