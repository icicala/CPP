#include <iostream>

int main() {
    int v[] = {10, 20, 30, 40};
    int i, *pv;
    /**
     * a) 10 20 30 40
     */
//    for (pv = v; pv <= v + 3; pv++)
//        std::cout << *pv << std::endl;

    /**
     * b)20 30 40
     */
//    for (pv = v, i = 1; i <= 3; i++)
//        std::cout << pv[i] << std::endl;

    /**
     * c) 10 30
     */
    for (pv = v, i = 0; pv+i <= &v[3]; pv++, i++)
        std::cout << *(pv + i) << std::endl;

    return 0;
}
