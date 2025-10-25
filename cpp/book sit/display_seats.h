#include<iostream>

namespace displaySeats {
    void displayLayout(bool **seats, unsigned int rowSize, unsigned int colSize) {
        std::cout << "--- Seat Layout (0 = Available, 1 = Booked) ---" << std::endl;
        for (unsigned int i = 0; i < rowSize; i++) {
            for (unsigned int j = 0; j < colSize; j++) {
                std::cout << seats[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void displayAvailableSeats(bool **seats, unsigned int rowSize, unsigned int colSize) {
        std::cout << "--- Available seats ---" << std::endl;
        for (unsigned int i = 0; i < rowSize; i++) {
            for (unsigned int j = 0; j < colSize; j++) {
                if (!seats[i][j])
                    std::cout << "Seat (" << i << "," << j << ") is available" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}