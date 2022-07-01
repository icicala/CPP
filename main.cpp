#include <iostream>
#include <cmath>
double f(double x){
    return 1/exp(pow(x, 2.0));
}

double integral(double a, double b, int n){
    double interval = std::abs(b - a) / n;
    double sum{};
    for(int i = n; i >=0; --i){
        sum+=interval*f(a);
        a+=interval;
    }
    return sum;

}

int main() {
    std::cout << "Test" << std::endl;
    std::cout << integral(0,1, 10000000);
    return 0;
}
