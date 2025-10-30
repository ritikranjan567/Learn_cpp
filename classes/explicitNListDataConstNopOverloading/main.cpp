#include<iostream>

class Vector {
public:
    float x, y, z;
    const char* vectorType;
public:
    Vector() : x(0.0f), y(0.0f), z(0.0f), vectorType("Default") {} // should follow the sequence of variable declared
    explicit Vector(float x, float y, float z)
        : x(x), y(y), z(z), vectorType("Parameterzied") {}
    Vector(const char* type) : vectorType(type) {};

    Vector operator+(const Vector &other) {
        return Vector(
            x + other.x,
            y + other.y,
            z + other.z
        );
    }
};

// stream insertion should be a non-member function
std::ostream& operator<<(std::ostream& stream, const Vector &obj) {
    stream << obj.vectorType << ": " << obj.x << "," << obj.y << "," << obj.z;
    return stream;
}

int main() {
    // Vector v = {2.3,4.5,6.2}; // implicit conversion, will not work if constructor is explicit marked
    Vector v(2.3f, 4.5f, 6.2f);
    Vector v2(2.7f, 4.5f, 5.8f);
    Vector v3 = v + v2;

    Vector vt = "Test"; // implicit type conversion based on constructor

    std::cout << v << std::endl;
    std::cout << v3 << std::endl;
    return 0;
}
