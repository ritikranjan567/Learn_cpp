#include<iostream>
#include<thread>
#include<list>
#include<mutex>

int sharedVariable = 0;
std::mutex gLock;

void updateSharedVar(int value) {
    gLock.lock();
    // now we are enforcing sync as only one thread can access this section at time
    // anything outside this block can be executed concurrently
        sharedVariable += value;
    gLock.unlock(); // if forget to unlock, then resource will be locked forever and other threads will be in dead lock waiting for it
}

int main(int argc, char* argv[]) {
    if (argc < 1) {
        std::cerr << "Usage: " << argv[0] << " <unsgined short>" << std::endl;
        return 1;
    }

    unsigned short N = std::atoi(argv[1]);

    std::list<std::thread> threads;
    // there is a chance that this will not produce N. as multiple threads can update simultaneously
    // lets use mutex

    for (unsigned short i = 0; i < N; i++) {
        threads.push_back(std::thread(updateSharedVar, 1));
    }

    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << "Final value: " << sharedVariable << std::endl;
    return 0;
}