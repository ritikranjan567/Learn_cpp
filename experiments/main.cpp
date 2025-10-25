#include<iostream>

using namespace std;

int& returnRef(int &var) {
    return var;
}

int main() {
    int var = 20;
    int &&a = 50;
    cout << "var: " << var << endl;
    a = 90;
    cout << a << endl;
    returnRef(var) = 55;

    cout << "var: " << var << endl;
    return 0;
}