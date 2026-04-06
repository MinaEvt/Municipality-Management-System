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

void handleCitizenRegistry(Registry& registry) {}

void handleEmployeeManagement(Registry& registry) {}

void handleServiceRequests(Registry& registry) {}

int main() {
    Registry registry;

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
