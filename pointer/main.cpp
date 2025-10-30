#include<iostream>

#define LOG(X) std::cout << X << std::endl

int main() {

    int var = 8;
    void* ptr = nullptr; //Invalid memory address; but no issue
    ptr = &var; // here & represents address of
    LOG(*(int *)ptr);

    int& ref = var; // here & is the part of declaration and is a type
    return 0;
}