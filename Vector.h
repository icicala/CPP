//
// Created by IonCicala on 11/07/2022.
//

#ifndef C___VECTOR_H
#define C___VECTOR_H

#include <cstddef>
#include <sstream>
#include <iostream>

template <typename T>
class Vector{

private:
    size_t m_dimension;
    T* m_data;
public:
    Vector();
    Vector(size_t dimension, T value);
    Vector(const Vector<T>& vector);

    size_t size()const;
    void resize(size_t lenght);
    void swap(Vector<T>& vector);
    std::string toString();
    void insert(size_t positon, const Vector<T>& vector);
    void insert(size_t position, const T& value);
    void remove(size_t position);

    T & operator[](size_t index);
    T operator[](size_t index) const;
    Vector<T>& operator=(const Vector<T>& vector);




    ~Vector();
};

template<typename T>
Vector<T>::Vector(size_t dimension, T value):m_dimension(dimension), m_data(new T[dimension]) {

    for(size_t i = 0; i < dimension; ++i){
        m_data[i] = value;
    }
}

template<typename T>
Vector<T>::Vector():m_dimension(1), m_data(new T[m_dimension]{}) {

}

template<typename T>
Vector<T>::Vector(const Vector<T> &vector) {
    m_dimension = vector.m_dimension;
    m_data = new T[m_dimension];
    for(size_t i = 0; i < m_dimension; ++i){
        m_data[i] = vector.m_data[i];
    }
}

template<typename T>
size_t Vector<T>::size() const {
    return m_dimension;
}

template<typename T>
void Vector<T>::resize(size_t lenght) {
    size_t dimtTemp = m_dimension;
    m_dimension = lenght;
    T* dataTemp = new T[m_dimension]{};
    for(size_t i = 0; i < dimtTemp; ++i ){
        dataTemp[i] = m_data[i];
    }
    delete [] m_data;
    m_data = dataTemp;
    dataTemp = nullptr;
}

template<typename T>
void Vector<T>::swap(Vector<T> &vector) {
    size_t tempDimention = m_dimension;
    T* tempData = m_data;
    m_dimension = vector.m_dimension;
    m_data = vector.m_data;
    vector.m_dimension = tempDimention;
    vector.m_data = tempData;
}

template<typename T>
std::string Vector<T>::toString() {
    std::stringstream ss;
    ss <<"(" << m_data[0];
    for(size_t i = 1; i < m_dimension; ++i){
        ss << ", "<< m_data[i];
    }
    ss<<")";
    return ss.str();
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_data;
}

template<typename T>
T &Vector<T>::operator[](size_t index){
    if(index < 0 || index >= m_dimension){
        throw std::out_of_range(" The index is out of range");
    }

    return m_data[index];
}

template<typename T>
T Vector<T>::operator[](size_t index) const {
    if(index < 0 || index >= m_dimension){
        throw std::out_of_range("The index is out of range");
    }
    return m_data[index];
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T>& vector) {
    if(this != &vector){
        m_dimension = vector.m_dimension;
        delete[] m_data;
        m_data = new T[m_dimension];
        for(size_t i=0; i < m_dimension; ++i){
            m_data[i] = vector.m_data[i];
        }
    }

    return *this;
}

template<typename T>
void Vector<T>::insert(size_t positon, const Vector<T>& vector) {
    if(positon < 0 || positon > m_dimension){
        throw std::out_of_range("The index is out of range");
    }
    if(vector.m_dimension > 0) {
        size_t newDimension = m_dimension + vector.m_dimension;
        Vector<T> temp(*this);
        this->resize(newDimension);
        for (size_t i = positon, j = 0; j < vector.m_dimension; ++i, ++j) {
            m_data[i] = vector.m_data[j];
        }

        for (size_t i = positon + vector.m_dimension, j = positon; j < temp.m_dimension; ++i, ++j) {
                m_data[i] = temp.m_data[j];
        }

    }



}

template<typename T>
void Vector<T>::insert(size_t position, const T &value) {
    Vector<T> temp(1, value);
    this->insert(position, temp);
}

template<typename T>
void Vector<T>::remove(size_t position) {
    if(position < 0 || position >= m_dimension){
        throw std::out_of_range("The index is out of boundary");
    }
    Vector<T> temp(*this);
    m_dimension -= 1;
    this->resize(m_dimension);
    for(size_t i = position; i < m_dimension; ++i){
        m_data[i] = temp.m_data[i+1];
    }

}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vector) {
    os << vector.toString();
    return os;
}


#endif //C___VECTOR_H
