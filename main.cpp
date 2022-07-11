#include "Vector.h"
#include <iostream>
#include <valarray>


int main() {

    Vector<int> inteng(3, 7);
    Vector<int> jin(10, 1);
    inteng[0] = 1;
    inteng[1] = 2;
    inteng[2] = 3;
    inteng.remove(1);
    std::cout << inteng.toString();
    return 0;
}
