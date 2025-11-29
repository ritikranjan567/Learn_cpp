#include "Person.h"

struct Person::PrivateData
{   
    std::string name;
    unsigned int age;
    PrivateData(const std::string& name, unsigned int age) : name(name), age(age) {}
};


Person::Person(const std::string& name) : data(new PrivateData(name, 24)) {}

Person::~Person() {
    delete data;
}

Person::Person(const Person& otherPerson): data(new PrivateData(otherPerson.data->name, otherPerson.data->age)) {}

Person& Person::operator=(const Person& otherPerson) {
    if (this == &otherPerson) return *this;

    data = new PrivateData(otherPerson.data->name, otherPerson.data->age);
    return *this;
}
unsigned int Person::getAge() const {
    return data->age;
}

void Person::setAge(unsigned int age) {
    data->age = age;
}

std::string Person::getName() const {
    return data->name;
}

