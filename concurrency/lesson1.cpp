#include<iostream>
#include<thread>

void test(int x) {
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Passed arguement: " << x << std::endl;
}

int main() {
    std::thread myThread(&test, -80);
    myThread.join(); // without this you may see errors as main thread may end before other thread end
    // here in this case order is enforced.

    std::cout << "Hello from main thread" << std::endl;
    return 0;
}