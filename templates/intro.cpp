#include<iostream>

template<typename t>
void printData(t value) {
    std::cout << value << std::endl;
}
// Above functions is created only when called based on the type and then compiled
// Based on calls compiler will generate overloads of the function

int main() {
    printData("Hello, world");
    printData("PI");
    printData(3.14);
    printData<std::string>("Hello, string"); // Template instantiation/specification
    return 0;
}