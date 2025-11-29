#include<string>
class Person {
    public:
        Person(const std::string& name);
        Person(const Person& otherPerson);
        Person& operator=(const Person& otherPerson);
        ~Person();
        std::string getName() const;
        void setName(std::string name) const;
        unsigned int getAge() const;
        void setAge(unsigned int age);

    private:
        struct PrivateData;
        PrivateData *data;
};