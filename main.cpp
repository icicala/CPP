#include <iostream>
#include <cstring>

int main()
{
    const char *ptr1 = new char[]{"zt"};
    const char *ptr2 = new char[]{"st"};
    int test = strcmp(ptr1, ptr2);
    std::cout << test;
    return 0;
}