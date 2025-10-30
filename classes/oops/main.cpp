#include<iostream>

#define LOG(msg) std::cout << msg << std::endl

class Parent {
    protected:
        int x, y;
    public:
        /* This is a simple parameterized constructor; if not defined cpp automatically creates one
        without any parameter */
        Parent(int x, int y) {
            LOG("Parent parameterized");
            this->x = x;
            this->y = y;
        }

        // You can overload these
        Parent() {
            LOG("Parent Default");
            this->x = 0;
            this->y = 0;
        }
        // Parent() = delete; #This tells cpp to hide constructor, and it is now impossible to instantiate
        // Another way to achieve this is to move the Constructor to private access modifier; That is helpful for singleton pattern
        int getX() {
            return x;
        }

        void setX(int x) {
            this->x = x;
        }

        int getY() {
            return y;
        }

        // Lets see about overriding
        void nonVclassName() {
            LOG("Parent");
        }

        virtual void className() {
            LOG("Parent");
        }
        // Presence of below pure virtual method makes the class abstract.
        // Now with this Parent class can not be instantiated, neither its sub-classes unless they implement the method
        // virtual int absMethod() = 0; 
};

class Child: public Parent {
    public:
        Child(int x, int y) {
            LOG("Child parameterized");
            this->x = x;
            this->y = y;
        }
        void setY(int y) {
            this->y = y;
        }

        void nonVclassName() { // Override keyword can not be used here as in base class it is not virtual function
            LOG("Child");
        }

        void className() override {
            LOG("Child");
        }
};

void printNonVClassName(Parent &obj) {
    obj.nonVclassName();
}

void printClassName(Parent &obj) {
    obj.className();
}

int main() {
    Parent pd;
    Parent p(12, 13);
    // Child c(12, 13); // This is error, because construct do not get in herited, 
    // although default constructor without params gets called

    // After declaring a parameterized constructor in child class
    Child c(34, 43); // if defined parameterized constructor without a default, then Child c; will give error (as it don't find default constructor in child class)
    // Although we call child parameterized constructor, before this parent's default contructor is called
    LOG(c.getX());
    
    pd.nonVclassName();
    c.nonVclassName();
    // This kind of override is ok untill, the variable type are matching. 
    // If we keep an instance of child in a varible of type parent then, override do not work.
    printNonVClassName(c); // O/P = Parent; Not child because non virtual functions are tied to type

    printClassName(c); // O/P = Child;

    return 0;
}