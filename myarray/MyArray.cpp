#include<initializer_list>
#include<iostream>

struct MyArray
{
private:
    int *_array;
    unsigned int _size;
public:
    MyArray(const std::initializer_list<int>& list) {
        _array = new int[list.size()];
        _size = list.size();
        for(unsigned int i = 0; i < _size; ++i) {
            _array[i] = *(list.begin() + i);
        }
    }

    MyArray& operator=(const MyArray& other) {
        _array = other._array;
        _size = other._size;
        return *this;
    }

    const int& operator[](unsigned int index) const {
        return _array[index];
    }

    ~MyArray() {
        delete[] _array;
    }

    unsigned int size() const {
        return _size;
    }

    unsigned int countElement(int value) const {
        unsigned int count = 0;
        for(unsigned int i = 0; i < _size; ++i) {
            if(_array[i] == value) {
                ++count;
            }
        }
        return count;
    }
};


int main() {
    MyArray arr = {1, 2, 2, 4, 5};
    MyArray arr2 = arr;
    std::cout << "Size of arr: " << arr.size() << std::endl;
    std::cout << "Size of arr2: " << arr2.size() << std::endl;
    
    std::cout << "Element at index 2 in arr2: " << arr2[2] << std::endl;
    std::cout << "Count of 2 in arr: " << arr.countElement(2) << std::endl;

    return 0; // Should return 5
}