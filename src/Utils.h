#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>


//helper class for input validation and common functions
class Utils {
public:
    
    static int getIntInput(const std::string& prompt);
    static double getDoubleInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
    static void clearScreen();
    static void pause();
    static bool isValidEmail(const std::string& email);
    static bool isValidPhone(const std::string& phone);
};

#endif // UTILS_H