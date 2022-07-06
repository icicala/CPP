//
// Created by IonCicala on 05/07/2022.
//

#include <iostream>
#include "Bibliography.h"

Bibliography::Bibliography(int size) : size(size), data(new Medium*[size]{}) {
    pointerInsertion = 0;
}

Bibliography::~Bibliography() {
    clear();
}


Bibliography::Bibliography(const Bibliography &bib) {

    size = bib.size;
    data = new Medium*[size];
    pointerInsertion = bib.pointerInsertion;

    for(int i = 0; i < pointerInsertion; ++i){
        data[i] = bib.data[i]->clone();
    }
}


void Bibliography::insert(Medium* medium) {
    if(pointerInsertion < size){
        data[pointerInsertion++] = medium;
    }else{
        std::cerr << "Error: Could not be inserted the array is full";
    }

}

Bibliography& Bibliography::operator=(const Bibliography &bib) {
    if(this == &bib){
        return *this;
    }

    clear();
    size = bib.size;
    data = new Medium*[size];
    pointerInsertion = bib.pointerInsertion;
    for(int i =0; i < pointerInsertion; ++i){
        data[i] = bib.data[i]->clone();
    }
    return *this;
}

void Bibliography::clear() {
    for(int i = 0; i < size; ++i){
        if(data[i]){
            delete data[i];
            data[i] = nullptr;
        }
    }
    delete[]data;
}

Medium *Bibliography::operator[](const std::string &name) const {
    for(int i = 0; i < pointerInsertion; i++){
        if(data[i]->getUniqueAbbreviation() == name){
            return data[i];
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const Bibliography &bibliography) {
    for(int i = 0; i < bibliography.pointerInsertion; ++i){
        os << bibliography.data[i]->toString() << std::endl;
    }
    return os;
}
