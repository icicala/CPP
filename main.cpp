#include <iostream>
#include <cmath>
constexpr  double GRAVITY = 9.81;
double inputFromUser(){
    double temp{};
    std::cin >> temp;
    return temp;
}

double toRadians(double degrees){
    return degrees*(M_PI/180.0);
}
double distance(double speed, double angle){
    return (pow(speed, 2)/GRAVITY)* sin(2* toRadians(angle));
}
double height(double speed, double angle){
    double temp = toRadians(angle);
    return pow(speed, 2)/(2*GRAVITY)* (pow(sin(temp),2));
}
double time(double speed, double angle){
    return ((2*speed)/GRAVITY)* sin(toRadians(angle));
}
int main() {
std::cout << "Inclined Throw" << std::endl;
std::cout << "==============" << std::endl;
std::cout << "Throwing speed in m/s?" << std::endl;
double speed = inputFromUser();
std::cout << "Throwing angle in degrees?" << std::endl;
double angle = inputFromUser();
std::cout << "Result" << std:: endl;
std::cout << "Throwing distance: " << distance(speed, angle) << std::endl;
std::cout << "Throwing height: " << height(speed, angle) << std::endl;
std:: cout << "Time: " << time(speed, angle) << std::endl;

    return 0;
}
