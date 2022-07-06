//
// Created by IonCicala on 05/07/2022.
//

#include <sstream>
#include "Article.h"

Article::Article(const std::string &uniqueAbbreviation, const std::string &author, const std::string &title,
                 int yearOfPublication, const std::string &magName, int magNumber, int pageNumber) : Medium(
        uniqueAbbreviation, author, title, yearOfPublication), mag_name(magName), mag_number(magNumber), page_number(
        pageNumber) {}

const std::string &Article::getMagName() const {
    return mag_name;
}

void Article::setMagName(const std::string &magName) {
    mag_name = magName;
}

int Article::getMagNumber() const {
    return mag_number;
}

void Article::setMagNumber(int magNumber) {
    mag_number = magNumber;
}

int Article::getPageNumber() const {
    return page_number;
}

void Article::setPageNumber(int pageNumber) {
    page_number = pageNumber;
}


std::string Article::toString() const {
    std::stringstream v;
    v << Medium::toString() << " " << mag_name << ". " << mag_number << ", " << Medium::getYearOfPublication() << ", " << page_number << ".";
    return v.str();
}


Article::~Article() {

}