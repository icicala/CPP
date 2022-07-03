#include <iostream>
class A {
public:
    A(int n);
    virtual void m1(int j);
    int m2();
protected:
    int i1;
};
A::A(int n){
    i1 = n;
}
void A::m1(int j) {
    i1 += j;
}
int A::m2() {
    return i1;}
class B : public A {
public:
    B(int n);
    void m1(int j);
    int m2();
private:
    int i2;
};
B::B(int n) : A (2) {
    i2 = n;
}
void B::m1(int j) {
    i2 += j;
}
int B::m2() {
    return i1 + i2;
}
using namespace std;
int main() {
    A a(1);
    B b(2);
    A * ptrA = new B(3);
    B * ptrB = new B(4);
    cout << a.m2() << endl;
    a.m1(5);
    cout << a.m2() << endl;
    cout << b.m2() << endl;
    b.m1(6);
    cout << b.m2() << endl;
    cout << ptrA->m2() << endl;
    ptrA->m1(7);
    cout << ptrA->m2() << endl;
    cout << ptrB->m2() << endl;
    ptrB->m1(9);
    cout << ptrB->m2() << endl;

    return 0;
}
/**
1
6
4
10
2
2
6
15
*/