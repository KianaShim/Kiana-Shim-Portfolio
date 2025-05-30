#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::ifstream inFile("prng-service.txt");
        if (!inFile.is_open()) {
            continue;
        }

        std::string line;
        std::getline(inFile, line);
        inFile.close();

        if (line == "run") {
            int randomNum = rand() % 100;

            std::ofstream outFile("prng-service.txt", std::ofstream::trunc);
            if (outFile.is_open()) {
                outFile << randomNum << std::endl;
                outFile.close();
            }
        }
    }

    return 0;
}