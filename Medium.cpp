//
// Created by IonCicala on 05/07/2022.
//

#include <sstream>
#include "Medium.h"

Medium::Medium(const std::string uniqueAbbreviation, const std::string author, const std::string title,
               int yearOfPublication) : uniqueAbbreviation(uniqueAbbreviation), author(author), title(title),
                                        yearOfPublication(yearOfPublication) {}

const std::string &Medium::getUniqueAbbreviation() const {
    return uniqueAbbreviation;
}

void Medium::setUniqueAbbreviation(const std::string &uniqueAbbreviation) {
    Medium::uniqueAbbreviation = uniqueAbbreviation;
}

const std::string &Medium::getAuthor() const {
    return author;
}

void Medium::setAuthor(const std::string &author) {
    Medium::author = author;
}

const std::string &Medium::getTitle() const {
    return title;
}

void Medium::setTitle(const std::string &title) {
    Medium::title = title;
}

int Medium::getYearOfPublication() const {
    return yearOfPublication;
}

void Medium::setYearOfPublication(int yearOfPublication) {
    Medium::yearOfPublication = yearOfPublication;
}

std::string Medium::toString() const {
    std::stringstream v;
    v << "[" << uniqueAbbreviation << "]" << " " << author << ": " << title;
    return v.str();
}

Medium::~Medium() {

}

Medium *Medium::clone() {
    Medium* medium = new Medium(*this);
    return medium;

}


