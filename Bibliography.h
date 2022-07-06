//
// Created by IonCicala on 05/07/2022.
//

#ifndef C___BIBLIOGRAPHY_H
#define C___BIBLIOGRAPHY_H


#include "Medium.h"

class Bibliography {
private:
    int size;
    int pointerInsertion;
    Medium** data;
    void clear();
public:
    Bibliography(int size);
    Bibliography(const Bibliography& bib);
    Bibliography& operator=(const Bibliography& bib);
    void insert(Medium* medium);
    Medium* operator[](const std::string& name) const;
    friend std::ostream& operator<<(std::ostream& os, const Bibliography& bibliography);

    virtual ~Bibliography();

};


#endif //C___BIBLIOGRAPHY_H
