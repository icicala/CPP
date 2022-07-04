//
// Created by IonCicala on 04/07/2022.
//

#ifndef C___VECTOR_H
#define C___VECTOR_H


#include <ostream>

class Vector {
private:
    int dimension;
    double* data;



public:
    explicit Vector(int dim = 2, double value = 0.0);
    Vector(const Vector& v);
    bool setValue(int index, int value);
    double getValue(int index)const;
    double& operator[](int index);
    double operator [](int index) const;
    Vector& operator=(const Vector& v);
    friend std::ostream& operator<<(std::ostream& os, Vector& v );

    virtual ~Vector();
};


#endif //C___VECTOR_H
