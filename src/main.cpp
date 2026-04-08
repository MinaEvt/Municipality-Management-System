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

    // --- temporary validation tests ---
    std::cout << "=== Validation Tests ===\n";

    // valid person
    try {
        Citizen c("Ivan Petrov", 1, "ul. Shipka 5", "1234567890", "ivan@mail.com");
        std::cout << "[PASS] Valid citizen created\n";
    } catch (const std::exception& e) {
        std::cout << "[FAIL] " << e.what() << "\n";
    }

    // empty name
    try {
        Citizen c("", 2, "ul. Vitosha 1", "0987654321");
        std::cout << "[FAIL] Empty name should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Empty name rejected: " << e.what() << "\n";
    }

    // name with numbers
    try {
        Citizen c("Ivan123", 3, "ul. Rakovski 10", "1111111111");
        std::cout << "[FAIL] Name with numbers should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Name with numbers rejected: " << e.what() << "\n";
    }

    // invalid id
    try {
        Citizen c("Maria Georgieva", -1, "ul. Levski 3", "2222222222");
        std::cout << "[FAIL] Negative ID should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Negative ID rejected: " << e.what() << "\n";
    }

    // only spaces in name
    try {
        Citizen c("   ", 4, "ul. Odrin 7", "3333333333");
        std::cout << "[FAIL] Spaces-only name should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Spaces-only name rejected: " << e.what() << "\n";
    }

    // invalid phone
    try {
        Citizen c("Ivan Petrov", 1, "ul. Shipka 5", "abc123", "ivan@mail.com");
        std::cout << "[FAIL] Invalid phone should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Invalid phone rejected: " << e.what() << "\n";
    }

    // invalid email
    try {
        Citizen c("Ivan Petrov", 1, "ul. Shipka 5", "0888123456", "notanemail");
        std::cout << "[FAIL] Invalid email should be rejected\n";
    } catch (const std::exception& e) {
        std::cout << "[PASS] Invalid email rejected: " << e.what() << "\n";
    }

    std::cout << "========================\n\n";
    // --- end of tests ---

    while (true) {
        // displayMenu();
        // int choice = Utils::getIntInput("");

        // switch (choice) {
        //     case 1:
        //         handleCitizenRegistry(registry);
        //         break;
        //     case 2:
        //         handleEmployeeManagement(registry);
        //         break;
        //     case 3:
        //         handleServiceRequests(registry);
        //         break;
        //     case 4:
        //         registry.generateReport();
        //         break;
        //     case 5:
        //         registry.saveToFiles();
        //         return 0;
        //     default:
        //         break;
        // }
    }

    return 0;
}
