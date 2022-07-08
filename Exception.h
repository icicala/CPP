//
// Created by IonCicala on 08/07/2022.
//

#ifndef C___EXCEPTION_H
#define C___EXCEPTION_H


#include <string>

class Exception {
private:
    std::string m_error;
public:
    Exception(std::string_view error);

    const std::string &getMError() const;


};


#endif //C___EXCEPTION_H
