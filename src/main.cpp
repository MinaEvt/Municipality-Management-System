#include "Registry.h"
#include "Citizen.h"
#include "Employee.h"
#include "ServiceRequest.h"
#include "Utils.h"
#include <iostream>
#include <memory>

void displayMenu() {
    Utils::clearScreen();
    std::cout << "+----------------------------------+\n";
    std::cout << "|  Municipality Management System  |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "|  [1] Citizen Registry            |\n";
    std::cout << "|  [2] Employee Management         |\n";
    std::cout << "|  [3] Service Requests            |\n";
    std::cout << "|  [4] Generate Report             |\n";
    std::cout << "|  [5] Exit                        |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "Choose an option: ";
}

void handleCitizenRegistry(Registry& registry) {
    while(true){
        Utils::clearScreen();
        std::cout << "+-----------------------------+\n";
        std::cout << "|      Citizen Registry       |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "|  [1] Add Citizen          |\n";
        std::cout << "|  [2] Find by ID           |\n";
        // std::cout << "|  [3] Find by Name         |\n";
        std::cout << "|  [4] Display All          |\n";
        std::cout << "|  [5] Back                 |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "Choose an option: ";

        int choice = Utils::getIntInput("");

        switch(choice){
            case 1:
                {
                    std::string name = Utils::getStringInput("Enter citizen name:");
                    std::string address = Utils::getStringInput("Enter citizen address:");
                    std::string email = Utils::getStringInput("Enter citizen email:");
                    std::string phone = Utils::getStringInput("Enter citizen phone number:");

                    try{
                        int id = registry.getNextCitizenId();
                        auto c = std::make_unique<Citizen>(name, id, address, phone, email);
                        registry.addCitizen(std::move(c));
                    }
                    catch(const std::exception& e){
                        std::cerr << "Error adding citizen: " << e.what() << std::endl;
                    }
                    Utils::pause();
                    break;
                }
            case 2:
                {
                    std::string id = Utils::getStringInput("Enter citizen ID:");
                    try{
                        Citizen* c = registry.findCitizen(std::stoi(id));
                        if (c) {
                            c->display();
                        } else {
                            std::cerr << "Citizen not found with ID: " << id << "\n";
                        }
                    }
                    catch(const std::exception& e){
                        std::cerr << "Error finding citizen: " << e.what() << std::endl;
                    }
                }
                Utils::pause();
                break;
            // case 3:
            //     {
            //         std::string name = Utils::getStringInput("Enter citizen name:");
            //         registry.findCitizenByName(name)->display();
            //     }
            //     Utils::pause();
            //     break;
            case 4:
                registry.displayCitizens();
                Utils::pause();
                break;
            case 5:
                return;
            default:
                break;
        }
    }
}

void handleEmployeeManagement(Registry& registry) {
    while(true){
        Utils::clearScreen();
        std::cout << "+-----------------------------+\n";
        std::cout << "|     Employee Management      |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "|  [1] Add Employee          |\n";
        std::cout << "|  [2] Find by ID           |\n";
        // std::cout << "|  [3] Find by Name         |\n";
        std::cout << "|  [4] Display All          |\n";
        std::cout << "|  [5] Back                 |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "Choose an option: ";

        int choice = Utils::getIntInput("");

        switch(choice){
            case 1:
                {
                    std::string name = Utils::getStringInput("Enter employee name:");
                    std::string address = Utils::getStringInput("Enter employee address:");
                    std::string role = Utils::getStringInput("Enter employee role:");
                    std::string department = Utils::getStringInput("Enter employee department:");
                    std::string salaryStr = Utils::getStringInput("Enter employee salary:");

                    try{
                        int id = registry.getNextEmployeeId();
                        double salary = std::stod(salaryStr);
                        auto e = std::make_unique<Employee>(name, id, address, role, department, salary);
                        registry.addEmployee(std::move(e));
                    }
                    catch(const std::exception& e){
                        std::cerr << "Error adding employee: " << e.what() << std::endl;
                    }
                    Utils::pause();
                    break;
                }
            case 2:
                {
                    std::string id = Utils::getStringInput("Enter employee ID:");
                    try{
                        Employee* e = registry.findEmployee(std::stoi(id));
                        if (e) {
                            e->display();
                        } else {
                            std::cerr << "Employee not found with ID: " << id << "\n";
                        }                    }
                    catch(const std::exception& e){
                        std::cerr << "Error finding employee: " << e.what() << std::endl;
                    }
                }
                Utils::pause();
                break;
            // case 3:
            //     {
            //         std::string name = Utils::getStringInput("Enter employee name:");
            //         registry.findEmployeeByName(name)->display();
            //     }
            //     Utils::pause();
            case 4:
                registry.displayEmployees();
                Utils::pause();
                break;
            case 5:
                return;
            default:
                break;  
        }
    }
}

void handleServiceRequests(Registry& registry) {
    while(true){
        Utils::clearScreen();
        std::cout << "+-----------------------------+\n";
        std::cout << "|      Service Requests       |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "|  [1] Submit Request         |\n";
        std::cout << "|  [2] View All               |\n";
        std::cout << "|  [3] Update Status          |\n";
        std::cout << "|  [4] Back                   |\n";
        std::cout << "+-----------------------------+\n";
        std::cout << "Choose an option: ";

        int choice = Utils::getIntInput("");

        switch(choice){
            case 1:
                {
                    std::string citizenIdStr = Utils::getStringInput("Enter your citizen ID:");
                    std::string type = Utils::getStringInput("Enter request type:");
                    std::string description = Utils::getStringInput("Enter request description:");

                    
                    try{
                        int citizenId = std::stoi(citizenIdStr);
                        int requestId = registry.getNextRequestId();
                        auto r = std::make_unique<ServiceRequest>(requestId, citizenId, type, description);
                        registry.addServiceRequest(std::move(r));
                    }
                    catch(const std::exception& e){
                        std::cerr << "Error submitting request: " << e.what() << std::endl;
                    }
                    Utils::pause();
                    break;
                }
            case 2:
                registry.displayServiceRequests();
                Utils::pause();
                break;
            case 3:
                {
                    std::string requestIdStr = Utils::getStringInput("Enter request ID:");
                    std::string statusStr = Utils::getStringInput("Enter new status (Pending, InProgress, Completed, Rejected):");

                    try{
                        int requestId = std::stoi(requestIdStr);
                        RequestStatus st = RequestStatus::Pending;
                        if (statusStr == "Pending") st = RequestStatus::Pending;
                        else if (statusStr == "InProgress") st = RequestStatus::InProgress;
                        else if (statusStr == "Completed") st = RequestStatus::Completed;
                        else if (statusStr == "Rejected") st = RequestStatus::Rejected;
                        else {
                            std::cerr << "Invalid status. Use: Pending, InProgress, Completed, Rejected\n";
                            Utils::pause();
                            break;   
                        }

                        registry.updateRequestStatus(requestId, st);

                    }
                    catch(const std::exception& e){
                        std::cerr << "Error updating request status: " << e.what() << std::endl;
                    }
                    Utils::pause();
                    break;
                }
            case 4:
                return;
            default:
                break;
        }
    }
}

int main() {
    Registry registry;
    registry.loadFromFiles();

    while (true) {
        displayMenu();
        int choice = Utils::getIntInput("");

        switch (choice) {
            case 1:
                handleCitizenRegistry(registry);
                break;
            case 2:
                handleEmployeeManagement(registry);
                break;
            case 3:
                handleServiceRequests(registry);
                break;
            case 4:
                registry.generateReport();
                Utils::pause();
                break;
            case 5:
                registry.saveToFiles();
                return 0;
            default:
                break;
        }
    }

    return 0;
}
