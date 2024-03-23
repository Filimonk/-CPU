#include <iostream>
#include <fstream>
#include <string>

#include "../STACK/src/Stack.cpp"

void computingUnit(char *path) {
    std::ifstream program(path);
    if (!program) {
        std::cout << "ОШИБКА в " << path << ":\n";
        std::cout << "    Программа не найдена\n";
        return;
    }
    
    std::string word;
    program >> word;

    if (word != "BEGIN") {
        std::cout << "ОШИБКА в " << path << ":\n";
        std::cout << "    Программа не была запущена\n";
        return;
    }
    
    stack::Stack <int> stack;

    int numbOfRegs = 20;
    int *regs = new int[numbOfRegs + 2];

    program >> word;
    while (word != "END") {
        if (word == "PUSH") {
            int value0;
            
            if (program >> value0) {
                stack.push(value0);
            }
            else {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << "    Вводится не число\n";
                break;
            }
        }
        else if (word == "POP") {
            try {
                stack.pop();
            }
            catch (const char* error) {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << error << "\n";
                break;
            }
        }
        else if (word == "PUSHR") {
            int reg0;

            if (program >> reg0) {
                if (reg0 >= numbOfRegs) {
                    std::cout << "ОШИБКА! в " << path << ":\n";
                    std::cout << "    Обращение к несуществующему регистру\n";
                    break;
                }
                
                stack.push(regs[reg0]);
            }
            else {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << "    Вводится не число\n";
                break;
            }
        }
        else if (word == "POPR") {
            int reg0;

            if (program >> reg0) {
                if (reg0 >= 20) {
                    std::cout << "ОШИБКА! в " << path << ":\n";
                    std::cout << "    Обращение к несуществующему регистру\n";
                    break;
                }
                
                regs[reg0] = stack.top();
                stack.pop();
            }
            else {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << "    Вводится не число\n";
                break;
            }
        }
        else if (word == "ADD") {
            regs[20] = stack.top();
            stack.pop();
            regs[20] += stack.top();
            stack.push(regs[20] - stack.top());
            stack.push(regs[20]);
        }
        else if (word == "SUB") {
            regs[20] = stack.top();
            stack.pop();
            regs[20] -= stack.top(); //вычитаем из верхнего числа нижнее!!!
            stack.push(regs[20] + stack.top());
            stack.push(regs[20]);
        }
        else if (word == "MUL") {
            regs[20] = stack.top();
            stack.pop();
            regs[21] = stack.top();
            stack.push(regs[20]);
            stack.push(regs[20] * regs[21]);
        }
        else if (word == "DIV") {
            regs[20] = stack.top();
            stack.pop();
            regs[21] = stack.top();
            stack.push(regs[20]);
            stack.push(regs[20] / regs[21]); //верхнее число - делимое,
                                             //нижнее - делитель
        }
        else if (word == "OUT") {
            try {
                std::cout << stack.top() << "\n";
                stack.pop();
            }
            catch (const char* error) {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << error << "\n";
                break;
            }
        }
        else if (word == "IN") {
            int value0;
            
            if (std::cin >> value0) {
                stack.push(value0);
            }
            else {
                std::cout << "ОШИБКА! в " << path << ":\n";
                std::cout << "    Вводится не число\n";
                break;
            }
        }
        else {
            std::cout << "ОШИБКА! в " << path << ":\n";
            std::cout << "    Команда пока неизвесна\n";
            break;
        } 
        
        program >> word;
    }
    
    delete[] regs;
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
