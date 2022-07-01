#include <iostream>
#define SQUARESUM(a, b) (((a)*(a))+((b)*(b)))
using std::cout, std::endl;
int main() {
    int i1 = 3;
    int i2 = 2; // Ergebnis:
    cout << SQUARESUM(i1, i2) << endl; // 13
    cout << SQUARESUM(2 + i1, i2) << endl; // 29
    cout << SQUARESUM(i1, i2 + 1) << endl; // 18
    cout << 3 * SQUARESUM(i1, i2) << endl; // 39
    return 0;
}
