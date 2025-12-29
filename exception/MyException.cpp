#include "MyException.h"

MyException::MyException(const char* msg) : _msg(msg) {}

const char* MyException::what() const noexcept {
    return _msg;
}