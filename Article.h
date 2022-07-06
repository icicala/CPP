//
// Created by IonCicala on 05/07/2022.
//

#ifndef C___ARTICLE_H
#define C___ARTICLE_H


#include "Medium.h"

class Article: public Medium {
private:
    std::string mag_name;
    int mag_number;
    int page_number;

public:
    Article(const std::string &uniqueAbbreviation, const std::string &author, const std::string &title,
            int yearOfPublication, const std::string &magName, int magNumber, int pageNumber);

    const std::string &getMagName() const;

    void setMagName(const std::string &magName);

    int getMagNumber() const;

    void setMagNumber(int magNumber);

    int getPageNumber() const;

    void setPageNumber(int pageNumber);

    std::string toString() const override;

    virtual ~Article();

};


#endif //C___ARTICLE_H
