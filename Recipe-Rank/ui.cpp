#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <limits>

int main() {
    while (true) {
        std::cout << "\n=== The CS 361 UI Menu ===\n"
                  << "1) Cook up some food\n"
                  << "2) Leave the kitchen\n"
                  << "Choice: ";

        int choice;
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            char buffer;

            {
                std::ofstream outFile("prng-service.txt", std::ofstream::trunc);
                std::cout << "\nPress the Enter Key to Begin Execution\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer
                std::cin.get(buffer);  // Wait for Enter key
                if (outFile.is_open()) {
                    outFile << "run" << std::endl;
                    outFile.close();
                }
            }

            std::cout << "\nPress the Enter Key to Generate Random Number\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer
            std::cin.get(buffer);  // Wait for Enter key

            int randomNumber = 0;
            {
                std::ifstream inFile("prng-service.txt");
                if (inFile.is_open()) {
                    inFile >> randomNumber;
                    inFile.close();
                }
            }

            {
                std::ofstream outFile("image-service.txt", std::ofstream::trunc);
                if (outFile.is_open()) {
                    outFile << randomNumber << std::endl;
                    outFile.close();
                }
            }

            std::cout << "\nPress the Enter Key to Generate Image Path\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the buffer
            std::cin.get(buffer);  // Wait for Enter key

            {
                std::ifstream inFile("image-service.txt");
                if (inFile.is_open()) {
                    std::string imagePath;
                    std::getline(inFile, imagePath);
                    inFile.close();

                    std::cout << "Generated image path: " << imagePath << std::endl;
                }
            }
        }
        else if (choice == 2) {
            std::cout << "Exiting the kitchen...\n";
            break;
        }
        else {
            std::cout << "Unknown option. Please try again.\n";
        }
    }

    return 0;
}