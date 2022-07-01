#include <iostream>
#include <iomanip>


int main() {
    /*a) What is the value of the variable x after the following program section */
    int n = 3;
    double x;
    x = (2 / n) * 3.0;
    std::cout << x; // 0

   /* b) The following loop does not behave as the programmer expected.
            Why? How often does the loop run?  Explain in detail!
        The signed integer  i will be converted to unsigned. And because unsigned integers can not store negative numbers,
         -2 wrapping around to a number close to the top of the range of a 4-byte integer.(4294967294)
            */
    unsigned int limit = 10;
    for (int i = -2; i < limit; i++)
    {
        std::cout << i;
    }
    int i = -2;
    bool  y = i < limit;
    return 0;
}
