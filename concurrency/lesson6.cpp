#include<iostream>
#include<thread>
#include<mutex>

// if the situation is like you have write multiple unlocks and you might miss an unlock call
// better use lock gaurd this is mutex wrapper

std::mutex gLock;
static int sharedVar = 0;

void updateSharedVar() {
    std::lock_guard<std::mutex> lockGaurd(gLock); //ownership of the gLock is given to the lockgaurd
    // that is it. once the lokcGaurd goes out of scope and destroyed and locks gets destroyed as well
}

