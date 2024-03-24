#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

#include "parser.h"
#include "preprocessor.h"

namespace preprocessor
{

bool getNewWord(std::ifstream &program, std::string &word, char *path) {
    if (!(program >> word)) {
        std::cout << "ОШИБКА компиляции в " << path << "\n";
        return 1;
    }
    
    return 0;
}

void preprocessing(std::ifstream &program, char *path) {
    std::vector <std::string> stream;
    
    std::map <std::string, int> strLabelToNumOfLabel;
    int indexOfFreeNum = 1;
    std::vector <int> numOfLabelToIndex = {-1};
    
    std::string word;
    while (program >> word) {
        if (word == "PUSH") {
            stream.push_back(word);
            if (getNewWord(program, word, path))
                return;
            
            stream.push_back(word);
        }
        else if (word == "PUSHR" || word == "POPR") {
            stream.push_back(word);
            if (getNewWord(program, word, path))
                return;
            
            if (word[0] != 'R') {
                std::cout << "ОШИБКА компиляции в " << path << "\n";
                return;
            }
            stream.push_back(word.substr(1, word.size() - 1));
        }
        else if (word.size() > 0 && word[0] == 'L') {
            if (strLabelToNumOfLabel.find(word) == strLabelToNumOfLabel.end()) {
                int num = indexOfFreeNum;
                ++indexOfFreeNum;
                
                strLabelToNumOfLabel[word] = num;
                
                numOfLabelToIndex.push_back(stream.size());
            }
            else {
                std::cout << "ОШИБКА компиляции в " << path << "\n";
                return;
            }
        }
        else if (word.size() > 0 && (word[0] == 'J' || word == "CALL")) {
            stream.push_back(word);
            if (getNewWord(program, word, path))
                return;
            
            if (strLabelToNumOfLabel.find(word) != strLabelToNumOfLabel.end()) {
                stream.push_back(std::to_string(strLabelToNumOfLabel[word]));
            }
            else {
                std::cout << "ОШИБКА компиляции в " << path << "\n";
                return;
            }
        }
        else if (word == "BEGIN") {
            if (numOfLabelToIndex[0] == -1) {
                numOfLabelToIndex[0] = stream.size();
            }
            else {
                std::cout << "ОШИБКА компиляции в " << path << "\n";
                return;
            }
        }
        else if (word == "def");
        else {
            stream.push_back(word);
        }
    }
    
    parser::parser(stream, numOfLabelToIndex, path);
}

}
