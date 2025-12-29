#include<iostream>
#include "MyException.h"

int main() {
    try {
        throw MyException("This is my custom exception");
    } catch(int e) {
        // catches throw 23;
        std::cout << e << std::endl;
    } catch(const char* msg) {
        // throw "This is simple error message"
        std::cout << msg << std::endl;
    } catch(MyException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}