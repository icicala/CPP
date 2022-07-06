//
// Created by IonCicala on 06/07/2022.
//

#include "Error.h"

Error::Error(const std::string &s):errorMessage(s) {

}

const std::string &Error::getMessage() const {
    return errorMessage;
}
