#include<iostream>
#include<variant>
int main() {
    std::variant<bool, int, double> var; // This varible can have 3 different variables but 1 at a time
    var = false;
    std::cout << std::get<bool>(var) << std::endl;
    var = -12;
    std::cout << std::get<int>(var) << std::endl;
    var = 3.14;
    std::cout << std::get<double>(var) << std::endl;

}