//
// Created by IonCicala on 05/07/2022.
//

#ifndef C___BOOK_H
#define C___BOOK_H


#include "Medium.h"

class Book: public Medium {
private:
    std::string publisher;
public:
    Book(const std::string &uniqueAbbreviation, const std::string &author, const std::string &title,
         int yearOfPublication, const std::string &publisher);

    const std::string &getPublisher() const;
    void setPublisher(const std::string &publisher);
    std::string toString() const override;

    virtual ~Book();


};


#endif //C___BOOK_H
