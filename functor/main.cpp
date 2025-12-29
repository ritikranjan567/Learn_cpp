#include<iostream>

#define LOG(msg) std::cout << msg << std::endl

class Vector {
    public:
        float X,Y,Z;
    public:
        Vector(float x, float y, float z) : X(x), Y(y), Z(z) {}
        float operator()(char action) const {
            if (action == 'n') {
                return (X + Y + Z) / 3.0;
            }
            return 0.0;
        }
};

int main() {
    Vector v({1.5, 1.5, 1.5});

    LOG(v('n'));
    return 0;
}