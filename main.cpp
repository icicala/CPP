#include <iostream>
/**
The following classes are given. Which accesses to attributes and methods are
allowed and which ones will cause syntax errors?

 */
class CA {
public:
    int ia1;
private:
    int ia2;
    void ma1() {
        ia1 = 10;
    }
public:
    void ma2(CA obj) {
        obj.ia1 = 20;
        ia2 = obj.ia1;
    }
};
class CB {
private:
    CA* obja;
public:
    CB(){
        obja = new CA();
    }
    void mb() {
        obja->ia1 = 11;
//        obja->ia2 = 22; // private
//        obja->ma1(); // private
        obja->ma2(*obja);
    }
};
int main() {
    CB b;
    b.mb();
    return 0;
}
