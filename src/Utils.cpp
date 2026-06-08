#include "Utils.h"
#include <iostream>
#include <limits>
#include <regex>

// Get integer input from the user with validation
int Utils::getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
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
bool Utils::isValidEmail(const std::string& email) {
    if (email.empty()) return false;
    std::regex pattern(R"(^[^\s@]+@[^\s@]+\.[^\s@]+$)");
    return std::regex_match(email, pattern);
}

// Validate phone number format — digits only, optional internal spaces
bool Utils::isValidPhone(const std::string& phone) {
    if (phone.empty()) return false;
    for (size_t i = 0; i < phone.length(); ++i) {
        if (!std::isdigit(phone[i]) && phone[i] != ' ') return false;
        if ((i == 0 || i == phone.length() - 1) && phone[i] == ' ') return false;
    }
    return true;
}
