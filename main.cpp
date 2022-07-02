#include <iostream>
#include <cmath>
void calcSurfaceAndVolumeOfSphere(const double& radius, double& surface, double& volume){

    surface = 4*M_PI*pow(radius,2);
    volume = (4.0/3) * M_PI * pow(radius, 3);

}
void calcSurfaceAndVolumeOfSphere(const double* radius, double* surface, double* volume){

    *surface = 4*M_PI*pow(*radius,2.0);
    *volume = (4.0/3) * M_PI * pow(*radius, 3);

}


int main() {

    double surface{};
    double volume{};
    double radius{0.5};
    for(int i = 0; i<=20; ++i){
        //calcSurfaceAndVolumeOfSphere(radius, surface, volume);
        calcSurfaceAndVolumeOfSphere(&radius, &surface, &volume);


        std::cout << "Radius:" << radius <<" Surface:" << surface << " Volume:" << volume << std::endl;
        radius+=0.5;
    }

    return 0;
}
