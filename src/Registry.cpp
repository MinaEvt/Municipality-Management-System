#include "Registry.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <sstream>

// Constructor initializes empty registry
Registry::Registry() {}

// Citizen management
void Registry::addCitizen(std::unique_ptr<Citizen> citizen) {}

// Find citizen by ID
Citizen* Registry::findCitizen(int id) { return nullptr; }

// Find citizen by name
Citizen* Registry::findCitizen(const std::string& name) { return nullptr; }

// Display all citizens in the registry
void Registry::displayCitizens() const {}

// Employee management
void Registry::addEmployee(std::unique_ptr<Employee> employee) {}

// Find employee by ID
Employee* Registry::findEmployee(int id) { return nullptr; }

// Find employee by name
Employee* Registry::findEmployee(const std::string& name) { return nullptr; }

// Display all employees in the registry
void Registry::displayEmployees() const {}

// Service request management
void Registry::addServiceRequest(std::unique_ptr<ServiceRequest> request) {}

// Find service request by ID
ServiceRequest* Registry::findServiceRequest(int id) { return nullptr; }

// Display all service requests in the registry
void Registry::displayServiceRequests() const {}

// Update the status of a service request by ID
void Registry::updateRequestStatus(int requestId, RequestStatus status) {}

// File operations
void Registry::saveToFiles() const {
    //Save citizens to txt file
    //Using txt file because we want it to be human readable
    //The program is for administrative systems

    std::ofstream outFile("../data/citizens_registry.txt");
    if(!outFile){
        std::cerr << "Error opening file for writing: citizens_registry.txt\n";
        return;
    }
    for (size_t i = 0; i < citizens.size(); i++){
        outFile << citizens[i]->toString() << "\n";
    }
}

// Load data from files into the registry
void Registry::loadFromFiles() {
//TODO - add error handling, file format validation, etc.

    std::ifstream inFile("../data/citizens_registry.txt");
    if(!inFile){
        std::cerr << "Error opening file for reading: citizens_registry.txt\n";
        return;
    }
    std::string line;
    while(std::getline(inFile, line)){
        std::stringstream ss(line);
        std::string name, address, phoneNumber, email;
        int id;
        std::getline(ss, name, ',');
        ss >> id;
        ss.ignore(); // ignore the comma
        std::getline(ss, address, ',');
        std::getline(ss, phoneNumber, ',');
        std::getline(ss, email, ',');

    }
}

// Generate a report of all citizens, employees, and service requests
void Registry::generateReport() const {}
