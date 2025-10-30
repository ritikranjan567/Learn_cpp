#include<iostream>

#define LOG(x) std::cout << x << std::endl

class Test {
    int x, y;
    mutable int z;
public:
    // As this should only return, we can restrict it to modify data members
    int getX() const {
        // x = 20; // with const keyword any modification to member is now restricted
        // setX(30); // this will not even call any other member function modifying values, unless the function is a const as well.
        z = 30; // However this function can modify mutable members
        return x;
    }
    void setX(int x) {
        this->x = x;
    }
};

// this is how you should pass object as reference to functions. It save memeory and avoid creation of references, so faster.
void printTestX(const Test &t) {
    // as the modifier of parameter is const
    // below will only work if getX is a const function
    LOG(t.getX());
}

int main() {
    const int a = 10; // can not be modified/should not be modified
    // int *b = &a; // This will give error due to type incompatibilaty
    int var = 20;
    const int *b = &a; // const int or int const are same
    
    // *b = 40; This is illegal now i.e can not change value
    // with int * const b; below would be illegal i.e. it will be a constant pointer saving var
    b = &var;
    
    int *c = new int;

    c = (int *) &a;
    *c = 999;
    LOG(*c); // 999
    LOG(a); // 10
    // Now deleting c will give error due to a is a const

    // To restrict both value and point address edit use
    const int * const ptr = &var;

    // *ptr = 10; // not allowed
    // ptr = &b; // not allowed
    Test t;
    t.setX(20);
    printTestX(t);
    return 0;
}