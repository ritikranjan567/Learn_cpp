#include<iostream>
#include "Person.h"

// Pointer to implementation pIMPL
int main() {
    Person p("Ritik");
    p.setAge(30);
    Person p2 = p;
    p2.setAge(40);
    std::cout << p.getName() << " and age: " << p.getAge() << std::endl;
    std::cout << p2.getName() << " and age: " << p2.getAge() << std::endl;
    return 0;
}
