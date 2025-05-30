#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>  
#include <cstdlib>  

int main() {
    const int NUM_IMAGES = 11;

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::ifstream inFile("image-service.txt");
        if (!inFile.is_open()) {
            continue;
        }

        std::string line;
        std::getline(inFile, line);
        inFile.close();

        bool isNumber = true;
        for (char c : line) {
            if (!isdigit(c) && c != '-' && c != '+') {
                isNumber = false;
                break;
            }
        }

        if (isNumber && !line.empty()) {
            int number = std::stoi(line);

            int modNum = number % NUM_IMAGES;
            if (modNum < 0) {
                modNum = (modNum + NUM_IMAGES) % NUM_IMAGES;
            }

            std::string imagePath = "/users/CS361/images/" + std::to_string(modNum) + ".jpg";

            std::ofstream outFile("image-service.txt", std::ofstream::trunc);
            if (outFile.is_open()) {
                outFile << imagePath << std::endl;
                outFile.close();
            }
        }
    }

    return 0;
}