#include<iostream>
#include<cstdarg>

template<typename T, int N>
class Array {
    T m_array[N]; // creates on compile time based on usage

public:
    Array() {}
    Array(T ...) {
        va_list args;
        va_start(args, N);

        for (int i = 0; i < N; i++) {
            m_array[i] = va_arg(args, T);
        }
        va_end(args);
    }

    T size() const { return N; }

    void printArray() const {
        for (unsigned int i = 0; i < N; i++) {
            std::cout << m_array[i];
        }
        std::cout << std::endl;
    }
};

int main() {
    Array<int, 3> nums;
    int a[] = {1,2};
    Array<int, 2> nums2 = {1,2};

    nums2.printArray();

    return 0;
}