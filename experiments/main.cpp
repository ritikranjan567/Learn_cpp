#include<iostream>

using namespace std;

int& returnRef(int &var) {
    return var;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

constexpr int mult(int a, int b) {
    return a * b;
}

int main() {
    int var = 20;
    int &&a = 50;
    cout << "var: " << var << endl;
    a = 90;
    cout << a << endl;
    returnRef(var) = 55;

    int x = 10, y = 20;
    swap(&x, &y);
    cout << x << " : " << y << endl;

    // decltype(x) newVar;

    cout << "var: " << var << mult(30, 50) << endl;
    return 0;
}