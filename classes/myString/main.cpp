#include<iostream>
#include<cstring>
#include<memory>

class MyString {
    std::unique_ptr<char[]> _buffer;
    unsigned int _size;

public:
    MyString(const char *buffer) {
        _size = std::strlen(buffer);
        _buffer = std::make_unique<char[]>(_size + 1);
        std::strcpy(_buffer.get(), buffer);
    }

    // MyString(const MyString& other) : _size(other._size), _buffer(other._buffer) {} // this is default one
    // MyString(const MyString& other) = delete; // disable copy

    MyString(const MyString& other) {
        _size = other._size;
        _buffer = std::make_unique<char[]> (_size + 1);
        std::strcpy(_buffer.get(), other._buffer.get());
    }


    unsigned int length() const noexcept {
        return _size;
    }

    char& operator[](unsigned int index) {
        return _buffer[index];
    }

    friend std::ostream& operator<<(std::ostream &stream, MyString &str);
};

std::ostream& operator<<(std::ostream &stream, MyString &str) {
    stream << str._buffer.get();
    return stream;
}

int main() {
    MyString s = "Apple Tree";

    std::cout << s << std::endl;
    std::cout << s.length() << std::endl;

    s[0] = 'X';

    std::cout << s << std::endl;

    MyString s2 = s; // can not be done without a copy constructor
    s2[0] = 'M';

    std::cout << s2 << std::endl;

    return 0;
}