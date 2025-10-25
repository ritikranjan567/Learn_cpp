#include "../externalLibHeaders/adder.h"
#include<iostream>

int main() {
    int a, b;
    float c, d;
    std::cout << "Enter two ints: ";
    std::cin >> a;
    std::cin >> b;
    std::cout << "Int sum = " << myMath::add(a, b) << std::endl;

    std::cout << "Enter two floats: ";
    std::cin >> c;
    std::cin >> d;
    std::cout << "Float sum = " << myMath::add(c, d) << std::endl;

    return 0;
}