#include<iostream>
#include<initializer_list>

template<typename T, size_t N>
class MyArray {
    T* m_array;
    public:
        MyArray(std::initializer_list<T> list)
            : m_array(new T[N])   // initialize the pointer here
        {
            std::copy(list.begin(), list.end(), m_array);
        }

        MyArray(const MyArray<T, N>& otherArray) : m_array(new T[N]) {
            for (unsigned int i = 0; i < N; i++) {
                m_array[i] = otherArray.m_array[i];
            }
        }

        MyArray<T, N>& operator=(const MyArray<T, N>& otherArray) {
            if (this == &otherArray)
                return *this;
            m_array = new T[N];
            for (unsigned int i = 0; i < N; i++) {
                m_array[i] = otherArray.m_array[i];
            }
            return *this;
        }

        ~MyArray() {
            delete [] m_array;
        }
        T& operator[](std::size_t idx) { return m_array[idx]; }
        const T& operator[](std::size_t idx) const { return m_array[idx]; }
};

int main() {
    MyArray<int, 3> arr = {1,2,3};
    arr[0] = 20;
    std::cout << arr[0] << std::endl;
    return 0;
}