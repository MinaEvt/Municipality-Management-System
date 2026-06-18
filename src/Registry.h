#ifndef REGISTRY_H
#define REGISTRY_H

#include "Citizen.h"
#include "Employee.h"
#include "ServiceRequest.h"
#include <vector>
#include <memory>
#include <string>

class Registry {
private:
    std::vector<std::unique_ptr<Citizen>> citizens;
    std::vector<std::unique_ptr<Employee>> employees;
    std::vector<std::unique_ptr<ServiceRequest>> requests;

    int nextCitizenId = 1;
    int nextEmployeeId = 1;
    int nextRequestId = 1;

public:
    Registry();

    // Citizen management
    void addCitizen(std::unique_ptr<Citizen> citizen);
    Citizen* findCitizen(int id);
    Citizen* findCitizen(const std::string& name);
    void displayCitizens() const;
    int getNextCitizenId() const { return nextCitizenId; }

    // Employee management
    void addEmployee(std::unique_ptr<Employee> employee);
    Employee* findEmployee(int id);
    Employee* findEmployee(const std::string& name);
    void displayEmployees() const;
    int getNextEmployeeId() const { return nextEmployeeId; }

    // Service request management
    void addServiceRequest(std::unique_ptr<ServiceRequest> request);
    ServiceRequest* findServiceRequest(int id);
    void displayServiceRequests() const;
    void updateRequestStatus(int requestId, RequestStatus status);
    int getNextRequestId() const { return nextRequestId; }

    // File operations
    void saveToFiles() const;
    void loadFromFiles();

    // Reports
    void generateReport() const;
};

#endif // REGISTRY_H