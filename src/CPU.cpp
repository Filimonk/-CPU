#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "preprocessor.h"
#include "processing.h"

void computingUnit(char *path) {
    int len = strlen(path);
    std::string fileActionType = ".";
    
    std::ios::openmode mode;

    if (len >= 5 && path[len - 5] == '.' &&
                    path[len - 4] == 'p' && 
                    path[len - 3] == 'r' &&
                    path[len - 2] == 'o' && 
                    path[len - 1] == 'g') {
        fileActionType = "compil";
        
        mode |= std::ios::in;
    }
    
    if (len >= 2 && path[len - 2] == '.' && path[len - 1] == 'o') {
        fileActionType = "run";
        mode |= (std::ios::in | std::ios::binary);
    }
    
    if (fileActionType == ".") {
        std::cout << "ОШИБКА в " << path << ":\n";
        std::cout << "    Неправильно задан путь\n";
        return;
    }
    
    std::ifstream file(path, mode);
    
    if (!file) {
        std::cout << "ОШИБКА в " << path << ":\n";
        std::cout << "    Файл не найден\n";
        return;
    }
    
    if (fileActionType == "compil") {
        preprocessor::preprocessing(file, path);
    }
    else {
        processor::processing(file, path);
    }
    
    file.close();
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Исполняемые файлы не выбраны!\n";
        return 0;
    }
    
    for (int i = 1; i < argc; ++i) {
        computingUnit(argv[i]);
    }
}
