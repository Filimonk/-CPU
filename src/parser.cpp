#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

#include "parser.h"

namespace parser 
{
std::vector <std::string> commands = {"PUSH", "PUSHR", "POPR", "JMP",
                                      "JEQ", "JNE", "JA", "JAE", "JB",
                                      "JBE", "CALL", "END", "POP",
                                      "ADD", "SUB", "MUL", "DIV", "OUT",
                                      "IN", "RET"};

int find(std::string &word) {
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == word) {
            return i;
        }
    }
    
    return -1;
}

bool isNotInt(std::string &word) {
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] < '0' || word[i] > '9') {
            return 1;
        }
    }
    
    return 0;
}

void parser(std::vector <std::string> &stream, 
        std::vector <int> &numOfLabelToIndex, char *path) {
    
    int len = strlen(path);
    std::string pathCode = "";
    for (int i = 0; i < len - 3; ++i) {
        pathCode += path[i];
    }
    pathCode[len - 4] = 'o';
    
    std::ofstream byteCode(pathCode, std::ios::out | std::ios::binary);
    
    int numOfLabelToIndexSize = numOfLabelToIndex.size();
    int temp[numOfLabelToIndexSize];
    for (int i = 0; i < numOfLabelToIndexSize; ++i) {
        temp[i] = numOfLabelToIndex[i];
    }
    
    byteCode.write((char *)&(numOfLabelToIndexSize), sizeof(int));
    byteCode.write((char *)temp, numOfLabelToIndexSize * sizeof(int));
    
    for (int i = 0; i < stream.size(); ++i) {
        int indOfCom = find(stream[i]);
        if (indOfCom == -1) {
            std::cout << "ОШИБКА компиляции в " << path << "\n";
            return;
        }
        
        byteCode.write((char *)&indOfCom, sizeof(indOfCom));
        if (indOfCom <= 10) {
            ++i;
            
            if (isNotInt(stream[i])) {
                std::cout << "ОШИБКА компиляции в " << path << "\n";
                return;
            }
            
            int num = std::stoi(stream[i]);
            byteCode.write((char *)&num, sizeof(num));
        }
    }

    byteCode.close();
}

}
