#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex gLock;
std::condition_variable conditionVar; 

// with this we can sleep other threads saving computation until need

int main() {
    int result = 0;
    bool notified = false;

    std::thread reporter(
        [&]() {
            std::unique_lock<std::mutex> lock(gLock);
            if (!notified) {
                conditionVar.wait(lock);
            }
            std::cout << "Report: " << result << std::endl;
        } 
    );


    std::thread worker(
        [&]() {
            std::unique_lock<std::mutex> lock(gLock);
            result += 10;
            // work done
            notified = true;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "work complete" << std::endl;
            conditionVar.notify_one();
        }
    );

    worker.join();
    reporter.join();

    return 0;
}