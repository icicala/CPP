//
// Created by IonCicala on 08/07/2022.
//

#include "Exception.h"

const std::string &Exception::getMError() const {
    return m_error;
}

Exception::Exception(std::string_view error):m_error(error) {

}
