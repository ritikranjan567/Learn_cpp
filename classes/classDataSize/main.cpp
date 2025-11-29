#include<iostream>

#define LOG(X) std::cout << X << std::endl

class Data {
    public:
        bool win;
        short count;
        double score;
};

class DataOpt {
    public:
        int score;
        short count;
        bool win;
};

int main() {
    Data d;
    LOG(sizeof(d.count));
    LOG(sizeof(d.win));
    LOG(sizeof(d.score));
    LOG(sizeof(d));

    // all the data in class Data sums upto 11 bytes but the class size is 16. 
    // this is due to largest data type is double, and we got padding based on that
    LOG("Lets optimize");
    DataOpt dopt;
    LOG(sizeof(dopt.score));
    LOG(sizeof(dopt.count));
    LOG(sizeof(dopt.win));
    LOG(sizeof(dopt));

    // As we change the data-type of score from double to int
    // each padding/slate created for class becomes 4 bytes. To keep all the data in class
    // we just required 4 x 2 = 8 bytes
    // in previous case compiler was creating 8 x 2 size class
    // best practices: data type should be declare in desc order as per size

    LOG("To find the largest data-type align of class/struct");
    LOG(alignof(d));
    LOG(alignof(dopt));
}