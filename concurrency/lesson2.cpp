#include<iostream>
#include<thread>

int main() {
    auto lambda = [](int port) {
        std::cout << "Hello from thread lambda!" << std::endl;
        std::cout << "Port argument: " << port << std::endl;
    };

    std::thread myThread(lambda, -9090);
    myThread.join();

    std::cout << "Hello from main thread!!" << std::endl;
    return 0;
}