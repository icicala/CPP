#include <iostream>
#include "ATM.h"
int main() {

    ATM a;
    a.refill(5*5, 5*20, 5*50);
    std:: cout << a.getTotalAmount() << std::endl;
    a.cash(225);
    std:: cout << a.getTotalAmount() << std::endl;
    a.cash(200);
    a.cash(120);
    std:: cout << a.getTotalAmount() << std::endl;
    a.cash(15);
    std:: cout << a.getTotalAmount() << std::endl;
    a.cash(10);
    std:: cout << a.getTotalAmount() << std::endl;
    a.cash(20);
    std:: cout << a.getTotalAmount() << std::endl;





    return 0;
}
