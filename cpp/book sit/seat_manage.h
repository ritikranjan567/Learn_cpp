namespace seatManage {
    void createHall(bool **seats, unsigned int rowSize, unsigned int colSize) {
        for (unsigned int i = 0; i < rowSize; i++)
            for (unsigned int j = 0; j < colSize; j++)
                seats[i][j] = false;
    }
    void bookSeat(bool **seats, unsigned int row, unsigned int col) {
        seats[row][col] = true;
    }

    void bookBlock(bool **seats, unsigned int row, unsigned int startCol, unsigned int numberOfSeats, unsigned int colSize) {
        for (unsigned int i = startCol; i < (startCol + numberOfSeats) && i < colSize; i++) {
            seats[row][i] = true;
        }
    }

    void cancelBooking(bool **seats, unsigned int row, unsigned int col) {
        seats[row][col] = false;
    }
}