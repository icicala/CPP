//
// Created by IonCicala on 08/07/2022.
//

#include "mystring.h"
#include "Exception.h"
#include <cstring>


stringexercise::mystring::mystring():occupied{0}, capacity{1}, sequence{new char[]{'\0'}} {

}
stringexercise::mystring::mystring(const char *str) {
    if(str != nullptr){
        occupied = strlen(str);
        capacity = occupied + 1;
        sequence = new char[capacity]{};
        strcpy(sequence, str);
    }else{
        occupied = 0;
        capacity = 1;
        sequence = new char[capacity]{'\0'};

    }
}

stringexercise::mystring::mystring(const std::string str) {
    if(str.empty()){
        occupied = 0;
        capacity = 1;
        sequence = new char[capacity]{'\0'};
    }else{
        occupied = str.length();
        capacity = occupied + 1;
        strcpy(sequence, str.c_str());
    }
}

stringexercise::mystring::mystring(const stringexercise::mystring &source) {
    occupied = source.occupied;
    capacity = source.capacity;
    sequence = new char [capacity];
    strcpy(sequence, source.sequence);
}

stringexercise::mystring::~mystring() {
        delete[] sequence;
}

stringexercise::mystring &stringexercise::mystring::operator+=(const stringexercise::mystring &addend) {
    size_t totalChars = occupied + addend.occupied + 1;
    if(capacity < totalChars) {
        char* temp = new char[totalChars];
        strcpy(temp, addend.sequence);
        delete [] sequence;
        sequence = temp;
        capacity = totalChars;
    }
        strcat(sequence, addend.sequence);
        occupied = occupied+addend.occupied;
    return *this;
}

stringexercise::mystring &stringexercise::mystring::operator+=(const char *addend) {

    return *this+=mystring(addend);
}

stringexercise::mystring &stringexercise::mystring::operator+=(const char addend) {
    std::string temp{addend};
    return *this += temp;
}

stringexercise::mystring &stringexercise::mystring::operator=(const stringexercise::mystring &source) {
    if(sequence != source.sequence){
        occupied = source.occupied;
        capacity = source.capacity;
        delete [] sequence;
        sequence = new char[capacity];
        strcpy(sequence, source.sequence);
    }
    return *this;
}

const char &stringexercise::mystring::operator[](size_t position) const {

    if(position < 0 || position >= occupied)throw Exception{"Invalid Index"};
    return sequence[position];
}

char &stringexercise::mystring::operator[](size_t position) {
    if(position < 0 || position >= occupied) throw Exception{"Invalid Index"};
 return sequence[position];
}


stringexercise::mystring operator+(const stringexercise::mystring& s1, const stringexercise::mystring& s2){
    stringexercise::mystring temp = s1;
    return temp+=s2;
}
stringexercise::mystring operator+(const stringexercise::mystring& s1, const char* s2 ){
stringexercise::mystring temp = s1;
    return temp+=s2;
}
stringexercise::mystring operator+(const char* s1, const stringexercise::mystring& s2){
    stringexercise::mystring temp = s2;
    return temp+=s1;
}

std::istream &stringexercise::operator>>(std::istream &ins, stringexercise::mystring &target) {
    std::string temp{};
    std::getline(ins, temp);
    mystring string(temp);
    target = temp;
    return ins;
}

std::ostream &stringexercise::operator<<(std::ostream &outs, const stringexercise::mystring &source) {
    outs << source.sequence;
    return outs;
}

bool stringexercise::operator==(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result == 0;
}

bool stringexercise::operator!=(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result != 0;
}

bool stringexercise::operator>=(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result >= 0;
}

bool stringexercise::operator<=(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result <= 0;
}

bool stringexercise::operator>(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result > 0;
}

bool stringexercise::operator<(const stringexercise::mystring &s1, const stringexercise::mystring &s2) {
    int result = strcmp(s1.sequence, s2.sequence);
    return result < 0;
}








