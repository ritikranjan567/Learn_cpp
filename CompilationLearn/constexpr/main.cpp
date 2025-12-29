#include<iostream>

constexpr int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr int result = add(5,5); // this calculation is done in compile time not in runtime
    std::cout << result << std::endl;
    return 0;
}