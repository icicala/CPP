#include <iostream>

int i1 = 1;
int i2 = 2;
void func(int & ref1, int & ref2) {
    int * ptr1;
    int * ptr2;
    ptr1 = &i1;
    ref2 = *ptr1;
    ptr2 = ptr1;
    *ptr2 = 4;
    ref1 = 5;
    ref2 = *ptr2;
}
int main(int argc, char* argv[])
{
    func(i1, i2);
    std::cout << "i1 = " << i1 << std::endl;
    std::cout << "i2 = " << i2 << std::endl;
    return 0;

    /**
     * i1 = 5
       i2 = 5
     */
}
