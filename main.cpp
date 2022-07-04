#include "Vector.h"
#include <iostream>


int main() {
    /*! on stack objects test */
    Vector v1;
    std:: cout << v1;
    v1.setValue(0, 5);
    v1.setValue(1, 20);
    Vector v2(v1);
    std:: cout << v2;
    Vector v3;
    v3=v2;
    std::cout << v3 <<" v3 "<< v3[1] << std::endl;
    std:: cout << v3[1] << std::endl;
    /*! on heap objects text */
    Vector *h1 = new Vector;
    std:: cout << *h1;
    Vector *h2 = new Vector(5, 11);
    (*h2)[2] = 777;
    std::cout << (*h2)[2] << std:: endl;
    (*h1) = (*h2);
    std:: cout << *h1 << *h2;
    Vector (h3)(*h2);
    std::cout << h3;
    Vector *h4 = new Vector;
    (*h1)[0]=10200;
    std::cout << "*h4" << *h4;
    *h4=*h2 =*h1;
    std:: cout << "*************************" << std::endl;
    std::cout << "*h4" << *h4 << "end" << std:: endl;
    std::cout << "*h2"<< *h2 << "end" << std:: endl;
    std::cout << "*h1"<< *h1 << "end" << std:: endl;
    return 0;
}
