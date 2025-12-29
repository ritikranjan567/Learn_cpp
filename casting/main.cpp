#include<iostream>
#include<cstdint>

#define LOG(X) std::cout << X << std::endl

class Base {
    public:
        int x, y;
        virtual void DO() const {
            LOG("Base::Do");
        }
};

class Derieved : public Base {
    public:
        void DO() const override {
            LOG("Derieved::Do");
        }
};

struct GameState {
    unsigned short health;
    unsigned short level;
    short damage;
    bool bossDefeated;
};

int main() {
    Base* B = new Base;
    Derieved* D = new Derieved;

    if (dynamic_cast<Derieved*>(B)) {
        (static_cast<Derieved*>(B))->DO();
    }
    (static_cast<Base*>(D))->DO();

    D->DO();

    delete B;
    delete D;

    Base BB;
    Derieved DD;

    static_cast<Base>(DD).DO(); // Base::Do
    // static_cast<Derieved>(BB).DO(); //Error
    //reinterpret_cast - based on bytes
    float pi = 3.14f;
    LOG((int)pi);
    LOG(&pi);
    LOG(*reinterpret_cast<int*>(&pi)); //Random number
    // Here is how to use it

    GameState gs = { 100, 8, 25, false };
    /*
        Suppose you are writting each data info into file
        you have to do something like
        f << gs.level;
        f << gs.health;
        .
        .
        Like around 4 or more operations as per number of attributes
    */
   // To do that in 1 go
    char bagOfBytes[sizeof(GameState)];
    memcpy(bagOfBytes, &gs, sizeof(GameState));
    LOG(*memcpy); // you can not extract data like this
    // So we use reinterpret_cast
    LOG(reinterpret_cast<GameState*>(bagOfBytes)->level);
    // so it is bytes to data you need
    return 0;
}