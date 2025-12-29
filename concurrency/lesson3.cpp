// Multiple threads.
#include<iostream>
#include<thread>
#include<list>

int main() {
    std::list<std::thread> threads;
    unsigned short N;

    std::cout << "Enter number for threads you want to enter: " << std::endl;
    std::cin >> N;

    auto excuteInThread = [](unsigned short idx) {
        std::cout << "Excuting from thread index: " << idx << std::endl;
        std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
    };

    for (unsigned short i = 0; i < N; i++) {
        threads.push_back(std::thread(excuteInThread, i));
        // threads.back().join(); this is basically sequential programing with no benifit
    }

    // here we should join
    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << "Hello from main thread!!" << std::endl;
    return 0;
}