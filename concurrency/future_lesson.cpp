#include<iostream>
#include<future>
#include<thread>
#include<chrono>

bool bufferedFileLoader() {
    size_t bytesLoaded = 0;
    while(bytesLoaded < 20000) {
        std::cout << "Thread loading file" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytesLoaded += 1000;
    }
    return true;
}

int main() {
    std::future<bool> backgroundThread = std::async(std::launch::async, bufferedFileLoader);

    std::future_status status;
    // program loop
    while(true) {
        std::cout << "Main thread is running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1)); // check status within waitfor
        if (status == std::future_status::ready) {
            std::cout << "our data is ready" << std::endl;
            break;
        }
    }
    return 0;
}