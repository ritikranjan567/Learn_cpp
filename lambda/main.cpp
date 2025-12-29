#include<iostream>
#include<vector>
#include<algorithm>

struct Showy {
    static int lastElement;
    void operator()(int n) {
        std::cout << n << ", "; 
        lastElement = n;
    }
};

int Showy::lastElement = INT_MAX;

int main() {
    std::vector<int> v({1,2,3,4});

    // Lambdas are basically same as functors, which can inscope capture. Unnaded functions
    int lastElement = -9999;
    std::for_each(begin(v), 
        end(v),
        [&lastElement](int n) { std::cout << n << ", "; lastElement = n; });
    std::cout << "Last: " << lastElement << std::endl;

    // lets do the same with functor
    Showy show;
    std::for_each(begin(v), 
        end(v),
        show);
    std::cout << "Last: " <<Showy::lastElement << std::endl;
}