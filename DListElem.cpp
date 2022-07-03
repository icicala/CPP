//
// Created by IonCicala on 03/07/2022.
//

#include "DListElem.h"

void initializeDList(Dlist &dl) {
dl.first = nullptr;
dl.last = nullptr;
}

void put(Dlist &dl, int val) {
    DListElem *elem = new DListElem;
    elem->value = val;
    elem->prev = nullptr;
    elem->next = nullptr;
    if(!isEmpty(dl)){
        elem->next = dl.first;
        dl.first->prev =elem;
        dl.first = elem;
    }else{
        dl.first = elem;
        dl.last = elem;
    }

}

bool get(Dlist &dl, int &val) {
    if(isEmpty(dl)){
        return false;
    }
    if(dl.first == dl.last){
        val = dl.first->value;
        delete dl.last;
        dl.first = nullptr;
        dl.last = nullptr;
        return true;
    }else {
        DListElem *tem = dl.last->prev;
        tem->next = nullptr;
        dl.last->prev = nullptr;
        val = dl.last->value;
        delete dl.last;
        dl.last = tem;
        return true;
    }

}

bool isEmpty(Dlist dl) {
   return dl.first == nullptr && dl.last == nullptr;
}
