//
// Created by IonCicala on 03/07/2022.
//

#ifndef C___DLISTELEM_H
#define C___DLISTELEM_H


struct DListElem {
    int value{};
    DListElem *prev;
    DListElem *next;

};

struct Dlist {
    DListElem* first;
    DListElem* last;
};
void initializeDList(Dlist & dl);
void put(Dlist& dl, int val);
bool get(Dlist& dl, int &val);
bool isEmpty(Dlist dl);

#endif //C___DLISTELEM_H
