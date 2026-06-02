#include "Registry.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <sstream>

// Constructor initializes empty registry
Registry::Registry()
    : citizens()
    , employees()
    , requests()
    , nextCitizenId(1)
    , nextEmployeeId(1)
    , nextRequestId(1) {}

// Citizen management
void Registry::addCitizen(std::unique_ptr<Citizen> citizen) {
    if (!citizen){
        std::cerr << "There was no citizen provided!\n";
        return;
    }

    if (!Person::validateName(citizen->getName())) {
        std::cerr << "Citizen's name is not valid!\n";
        return;
    }

    if (!Person::validateAddress(citizen->getAddress())) {
        std::cerr << "Invalid address!\n";
        return;
    }

    if (!Citizen::validatePhoneNumber(citizen->getPhoneNumber())) {
        std::cerr << "Invalid phone number!\n";
        return;
    }

    if (!Citizen::validateEmail(citizen->getEmail())) {
        std::cerr << "Invalid emil address!\n";
    }

    if (citizen->getId() > 0) {
        if (findCitizen(citizen->getId())) {
            std::cerr << "Citizen alredy has Id: " << citizen->getId() << "\n";
            return;
        }
        if (citizen->getId() >= nextCitizenId) {
            nextCitizenId = citizen->getId() + 1;
        }
    }
    else {
        citizen->setId(nextCitizenId++);
    }

    citizens.push_back(std::move(citizen));
}

// Find citizen by ID
Citizen* Registry::findCitizen(int id) {
    auto it = std::find_if(citizens.begin(), citizens.end(),
        [id](const std::unique_ptr<Citizen>& c) {
            return c && c->getId() == id;
        });
    return (it != citizens.end()) ? it->get() : nullptr;
}

// Find citizen by name
Citizen* Registry::findCitizen(const std::string& name) {
    auto it = std::find_if(citizens.begin(), citizens.end(),
        [&name](const std::unique_ptr<Citizen>& c) {
            return c && c->getName() == name;
        });
    return (it != citizens.end()) ? it->get() : nullptr;
}

// Display all citizens in the registry
void Registry::displayCitizens() const {
    if (citizens.empty()) {
        std::cout << "No citizens registered.\n";
        return;
    }

    std::cout << "Number of citizens (" << citizens.size() << "):\n";
    for (const auto& c : citizens) {
        if (c) {
            c->display();
        }
    }

}

// Employee management
void Registry::addEmployee(std::unique_ptr<Employee> employee) {
    if (!employee) {
        std::cerr << "There was no employee provided!\n";
        return;
    }

    if (!Person::validateName(employee->getName())) {
        std::cerr << "Citizen's name is not valid!\n";
        return;
    }

    if (!Person::validateAddress(employee->getAddress())) {
        std::cerr << "Invalid address!\n";
        return;
    }

    if (employee->getSalary() < 0.0) {
        std::cerr << "Salary cannot be negative!\n";
        return;
    }

    if (employee->getId() > 0) {
        if (findCitizen(employee->getId())) {
            std::cerr << "Employee alredy has Id: " << employee->getId() << "\n";
            return;
        }
        if (employee->getId() >= nextEmployeeId) {
            nextEmployeeId = employee->getId() + 1;
        }
    }
    else {
        employee->setId(nextEmployeeId++);
    }

    employees.push_back(std::move(employee));
}

// Find employee by ID
Employee* Registry::findEmployee(int id) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [id](const std::unique_ptr<Employee>& e) {
            return e && e->getId() == id;
        });
    return (it != employees.end()) ? it->get() : nullptr;
}

// Find employee by name
Employee* Registry::findEmployee(const std::string& name) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [name](const std::unique_ptr<Employee>& e) {
            return e && e->getName() == name;
        });
    return (it != employees.end()) ? it->get() : nullptr;
}

// Display all employees in the registry
void Registry::displayEmployees() const {
    if (employees.empty()) {
        std::cout << "No employees registered.\n";
        return;
    }

    std::cout << "Number of citizens (" << employees.size() << "):\n";
    for (const auto& e : employees) {
        if (e) {
            e->display();
        }
    }
}

// Service request management
void Registry::addServiceRequest(std::unique_ptr<ServiceRequest> request) {
    if (!request) {
        std::cerr << "Null request provided!\n";
        return;
    }

    int cId = request->getCitizenId();
    if (cId <= 0 || !findCitizen(cId)) {
        std::cerr << "Invalid citizen Id!\n" << cId;
        return;
    }

    if (request->getRequestType().empty()) {
        std::cerr << "Request type cannot be empty!\n";
        return;
    }

    if (request->getRequestId() > 0) {
        if (findServiceRequest(request->getRequestId())) {
            std::cerr << "Request with id " << request->getRequestId() << "already exists!\n";
            return;
        }
        if (request->getRequestId() >= nextRequestId) {
            nextRequestId = request->getRequestId() + 1;
        }
    }
    else {
        request->setRequestId(nextRequestId++);
    }


    requests.push_back(std::move(request));
}

// Find service request by IDgitk --
ServiceRequest* Registry::findServiceRequest(int id) {
    auto it = std::find_if(requests.begin(), requests.end(),
        [id](const std::unique_ptr<ServiceRequest>& r) {
            return r && r->getRequestId() == id;
        });
    return (it != requests.end()) ? it->get() : nullptr;
}

// Display all service requests in the registry
void Registry::displayServiceRequests() const {
    if (requests.empty()) {
        std::cout << "No request avalaible.\n";
        return;
    }

    std::cout << "Service requests: " << requests.size() << "\n";
    for (const auto& r : requests) {
        if (r) {
            r->display();
        }
    }
}

// Update the status of a service request by ID
void Registry::updateRequestStatus(int requestId, RequestStatus status) {
    ServiceRequest* req = findServiceRequest(requestId);
    if (!req) {
        std::cerr << "Status request with id " << requestId << " not found!\n";
        return;
    }

    std::string prevStatus = req->getStatusString();
    if (req->getStatus() == status) {
        std::cout << "Request " << requestId << " already has status \"" << prevStatus << "\"\n";
        return;
    }

    req->setStatus(status);
    std::cout << "Request " << requestId << " status changed from \"" << prevStatus << "\" to \"" << req->getStatusString() << "\"\n";
}

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
void Registry::generateReport() const {
    std::ostringstream out;

    out << " === Registry Report === \n\n";

    out << "Citizens (" << citizens.size() << "):\n";
    if (citizens.empty()) {
        out << " None\n";
    }
    else {
        for (const auto& c : citizens) {
            if (c) {
                out << " " << c->toString() << "\n";
            }
        }
    }
    out << "\n";

    out << "Employees (" << employees.size() << "):\n";
    if (employees.empty()) {
        out << " None\n";
    }
    else {
        for (const auto& e : employees) {
            if (e) {
                out << " " << e->toString() << "\n";
            }
        }
    }

    out << "Service Requests (" << requests.size() << "):\n";
    if (requests.empty()) {
        out << " None\n";
    }
    else {
        for (const auto& r : requests) {
            if (r) {
                out << " " << *r << "\n";
            }
        }
    }
    out << "\n=== End of Report ===\n";


    std::cout << out.str();

    std::ofstream file("../data/registry_report.txt");
    if (!file) {
        std::cerr << "Could not open ../data/registry_report.txt for a writing\n";
    }
}
