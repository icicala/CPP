#include <iostream>
#include <iomanip>
/*
 * Write a program that prints a section of the ASCII character set table. The program
first asks the user for input of two numbers (which should be between 32 and
255). Then the program prints the code of the character and the corresponding
character of the given range, e.g. in the following way:
Please enter lower limit: 40
Please enter upper limit: 45
Code Character
40 '('
41 ')'
42 '*'
43 '+'
44 ','
45 '-'
 */
int inputUser(){
    int temp{};
    std:: cin >> temp;
    if(temp >= 32 && temp <= 255 ){
        return temp;
    }else{
        return 0;
    }

}

int main() {
    std::cout << "Please enter lower limit: " << std::endl;
    int lowerLimit = inputUser();
    std::cout << "Please enter upper limit: " << std::endl;
    int upperLimit = inputUser();
    if(lowerLimit && upperLimit) {
        std::cout << "Code " << " Character" << std::endl;
        for (int s = lowerLimit; s <= upperLimit; ++s) {
            std::cout << std::setw(3) << s << std::setw(7)<< "\'" << static_cast<char>(s)<<"\'" << std::endl;
        }
    }else{
        std::cout << "Please insert a number between 32 and 255" << std::endl;
    }
    return 0;
}
