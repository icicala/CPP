//
// Created by IonCicala on 04/07/2022.
//

#include <cassert>
#include <iostream>
#include "Vector.h"

Vector::Vector(int dim, double value):dimension{dim}, data{new double[dim]{}} {
    if(dim < 0){
        std::cerr << "Not posible to create the object";
    }
    if(static_cast<bool>(value)) {
        for (int i = 0; i < dim; i++) {
            data[i] = value;
        }
    }


}

Vector::Vector(const Vector &v):dimension{v.dimension}, data{ new double [dimension]} {
    for(int i = 0; i < dimension; ++i){
        data[i] = v.data[i];
    }
}

bool Vector::setValue(int index, int value) {
    if(index >= 0 && index < dimension){
        data[index] = value;
        return true;
    }
    return false;
}

double Vector::getValue(int index)const {
    return data[index];
}

double& Vector::operator[](int index) {
    assert(index >= 0 && index < dimension);
    return data[index];
}

double Vector::operator[](int index) const {
    assert(index >= 0 && index < dimension);
    return data[index];
}
Vector::~Vector() {
    delete [] data;
}

Vector &Vector::operator=(const Vector &v){
    if(this == &v){
        return *this;
    }
    if(dimension != v.dimension){
        dimension = v.dimension;
        delete[]data;
        data = new double[dimension];
    }
    for(int i = 0; i < dimension; ++i){
        data[i] = v[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Vector &v) {
    os << "(";
    for(int i = 0; i < v.dimension-1; ++i){
        os << v.data[i] << ",";
    }
    os << v[v.dimension -1] << ")" << std::endl;
    return os;
}
