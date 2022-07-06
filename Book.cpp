//
// Created by IonCicala on 05/07/2022.
//

#include <sstream>
#include "Book.h"

Book::Book(const std::string &uniqueAbbreviation, const std::string &author, const std::string &title,
           int yearOfPublication, const std::string &publisher) : Medium(uniqueAbbreviation, author, title,
                                                                         yearOfPublication), publisher(publisher) {}



const std::string &Book::getPublisher() const {
    return publisher;
}

void Book::setPublisher(const std::string &publisher) {
    Book::publisher = publisher;
}



std::string Book::toString() const {

    std::stringstream v;
    v << Medium::toString() << " " << publisher << ", " << getYearOfPublication() << ".";
    return v.str();
}

Book::~Book() {

}