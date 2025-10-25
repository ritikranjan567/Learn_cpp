// #include<iostream>
#include "seat_manage.h"
#include "display_seats.h"
using namespace std;

int main() {
    cout << "Here" << "start" << endl;
    unsigned int rowSize = 10, colSize = 10;
    unsigned short choice;
    unsigned int row, col, numberOfSeats;
    bool* block = new bool[rowSize * colSize]();
    bool** seats = new bool*[rowSize];
    for (unsigned int r = 0; r < rowSize; ++r)
        seats[r] = block + (r * colSize);
    seatManage::createHall(seats, rowSize, colSize);
    cout << "Here";
    while(true) {
        cout << "===== Cinema Seat Booking Menu =====" << endl;
        cout << "1.\tView Seat Layout" << endl;
        cout << "2.\tBook a Single Seat" << endl;
        cout << "3.\tBook a block of Seats" << endl;
        cout << "4.\tCancel a Seat Booking" << endl;
        cout << "5.\tDisplay availble seats only" << endl;
        cout << "6.\tExit" << endl;
        cout << "Enter your choice (1 to 6) to select a function: ";
        cin >> choice;
        cout << endl;
        if (choice == 1) {
            displaySeats::displayLayout(seats, rowSize, colSize);
        } else if (choice == 2) {
            cout << "Enter row and column to book (0-based): ";
            cin >> row;
            cin >> col;
            seatManage::bookSeat(seats, row, col);
            cout << "Seat booked successfully." << endl << endl;
        } else if (choice == 3) {
            cout << "Enter row, starting column and number of seats to book (0-based): ";
            cin >> row;
            cin >> col;
            cin >> numberOfSeats;
            seatManage::bookBlock(seats, row, col, numberOfSeats, colSize);
            cout << "Block Booked" << endl << endl;
        } else if (choice == 4) {
            cout << "Enter row and column to cancel booking (0-based): ";
            cin >> row;
            cin >> col;
            seatManage::cancelBooking(seats, row, col);
            cout << "Seat booking cancelled." << endl << endl;
        } else if (choice == 5) {
            displaySeats::displayAvailableSeats(seats, rowSize, colSize);
        } else if (choice == 6) {
            cout << "Exiting System. Thank you!" << endl;
            break;
        }
    }
    
    return 0;
}