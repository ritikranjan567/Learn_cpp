#include<exception>

class MyException : public std::exception {
    const char* _msg;
    public:
        MyException(const char* msg);
        const char* what() const noexcept;
};