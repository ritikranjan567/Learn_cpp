#include<iostream>

template<typename t>
void printData(t value) {
    std::cout << value << std::endl;
}
// Above functions is created only when called based on the type and then compiled

int main() {
    printData("Hello, world");
    printData("PI");
    printData(3.14);
    printData<std::string>("Hello, string"); // Template instantiation/specification
    return 0;
}