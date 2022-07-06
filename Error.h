//
// Created by IonCicala on 06/07/2022.
//

#ifndef C___ERROR_H
#define C___ERROR_H


#include <string>

class Error {
private:
    std::string errorMessage;
public:
    Error(const std::string& s);
    const std::string& getMessage()const;


};


#endif //C___ERROR_H
