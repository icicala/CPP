//
// Created by IonCicala on 05/07/2022.
//

#ifndef C___MEDIUM_H
#define C___MEDIUM_H


#include <string>

class Medium {
private:
    std::string uniqueAbbreviation{};
    std::string author{};
    std::string title{};
    int yearOfPublication{};

public:
    Medium(std::string uniqueAbbreviation, std::string author, std::string title,
           int yearOfPublication);

    const std::string &getUniqueAbbreviation() const;

    void setUniqueAbbreviation(const std::string &uniqueAbbreviation);

    const std::string &getAuthor() const;

    void setAuthor(const std::string &author);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    int getYearOfPublication() const;

    void setYearOfPublication(int yearOfPublication);

    virtual std::string toString() const;
    Medium* clone();

    virtual ~Medium();
};


#endif //C___MEDIUM_H
