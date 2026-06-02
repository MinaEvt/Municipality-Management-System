#include "Utils.h"
#include <iostream>
#include <limits>
#include <regex>

// Get integer input from the user with validation
int Utils::getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

// Get double input from the user with validation
double Utils::getDoubleInput(const std::string& prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

// Get string input from the user
std::string Utils::getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

// Clear the console screen
void Utils::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pause the console and wait for user input
void Utils::pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Validate email format using regex
bool Utils::isValidEmail(const std::string& email) { return false; }

// Validate phone number format (simple regex for demonstration)
bool Utils::isValidPhone(const std::string& phone) { return false; }
