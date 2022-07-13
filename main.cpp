


#include <string>
#include <regex>
#include <iostream>

int main() {
    std::string value = "Develop a program, which is able to count the occurrence of words in a text. As a result, the program prints out each word found in the text together with the number of occurrences of this specific word in the text. As an example, you see the output of the program, if you provide the text of this exercise as input";



  std::string::iterator v = value.begin();
  std::string output (value.length(), 'X');
    std::transform(value.begin(), value.end(), output.begin() , ::tolower);
    std::regex re("[' ',.]");
    std::sregex_token_iterator first{output.begin(), output.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
    std::vector<std::string> tokens{first, last};
    std::map<std::string, int> result;
    for(auto& t:tokens){
        if(!t.empty()) {
            std::pair<std::map<std::string, int>::iterator, bool> ptr = result.insert(std::make_pair(t, 1));
            if(!ptr.second){
                ptr.first->second +=1;
            }
        }

    }
    for(auto & it : result){
        std::cout << it.first << ": " << it.second << std::endl;
    }


    return 0;
}
