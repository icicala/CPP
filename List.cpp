#include <iostream>
#include "List.h"
//
// Created by IonCicala on 02/07/2022.
//
void printList(List lst) {
    while(lst!= nullptr){
        std::cout << " " << lst->info << " ";
        lst = lst->next;
    }
    std::cout << std::endl;
}

void insertLast(List &lst, int info) {
List element = new ListElem;
element->info = info;
element->next = nullptr;
if(lst == emptyList){
    lst = element;
}else{
    ListElem* interim = lst;
    while(interim->next != nullptr){
        interim = interim->next;
    }
    interim->next = element;
}

}

void reverseList(List &lst) {
ListElem* prev = nullptr;
ListElem* current = lst;
ListElem* next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    lst = prev;
}

int listLength(List lst) {
    int count{};
    while(lst != nullptr){
        lst = lst->next;
        count++;
    }
    return count;
}

void insertElem(List &lst, int info) {
    List element = new ListElem;
    element->info = info;
    element->next = lst;
    lst = element;
}

bool removeElem(List &lst, int &info) {
    if(lst != emptyList){
        List temp = lst->next;
        info = lst->info;
        delete lst;
        lst = temp;
        return true;
    }
    return false;
}

ListElem *searchElem(List lst, int info) {
    while(lst != nullptr){
        if(lst->info == info){
            return lst;
        }
        lst = lst->next;
    }
    return nullptr;
}
