#include<iostream>
using namespace std;

long int f(int n) {
    if (n==0) return 0;
    return n + f(n - 2);
}

int main() {
    cout << f(5) << endl;
    return 0;
}