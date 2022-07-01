#include <iostream>
/**
 * Vigenère key (also shift key)
 * @return
 */

char vigenereSquareEncrypt(char origtext, char password){
    if(origtext == ' ' && password == ' '){
        return ' ';
    }
    unsigned int tempText = static_cast<int>(origtext);
    unsigned int tempPassw = static_cast<int>(password);
    unsigned int temp = ((tempText-97) + (tempPassw-65))%26;
    char encrypted = static_cast<char>(temp+65);
    return encrypted;
}
char vinereSqaureDecrypt(char encryptext, char password){
    if(encryptext == ' ' && password == ' '){
        return ' ';
    }
    unsigned int tempencrypText = static_cast<int>(encryptext);
    unsigned int tempPassw = static_cast<int>(password);
    unsigned int temp = ((91 - tempPassw) + (tempencrypText-65))%26;
    char decrypt = static_cast<char>(temp+97);
    return decrypt;
}
std::string encrypt(const std::string& text, const std::string& password){
    std::string encryptedText {};
    for(int i = 0; i < text.size(); i++ ){
        encryptedText+= vigenereSquareEncrypt(text[i], password[i]);
    }
    return encryptedText;
}
std::string decrypt(const std::string& encrypText, const std::string& password){
    std:: string originalText{};
    for(int i = 0; i < encrypText.size(); ++i){
        originalText+= vinereSqaureDecrypt(encrypText[i], password[i]);
    }
    return originalText;
}

int main() {
     std::string originalText = "vigenere quadrat";
     std::string passw = "PASSWORT PASSWOR";

     std::string encrypText ="KIYWJSIX FUSVNOK";
     std::cout << encrypt(originalText, passw) << std::endl;
     std::cout << "*******************************" << std::endl;
     std::cout << decrypt(encrypText, passw) << std::endl;
    return 0;
}
