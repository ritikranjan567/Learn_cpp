#include<iostream>

#define LOG(X) std::cout << X << std::endl;

struct A
{
    int x = 1, y = 2;
};

struct B : virtual A {
};


struct C : virtual A {};

struct D : B, C
{
    /* data */
};

// We don't need to use public access modifier while inheriting struct because they are by default public

int main() {
    D d;
    LOG(d.x); // you will be getting error of ambiguity as both B and C have their own copy of x and y
    // Solution to it would be virtual inheritance
    return 0;
}