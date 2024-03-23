#include <iostream>
#include <fstream>

#include "command.h"
#include "../src/Stack.cpp"
#include "processing.h"

namespace processor
{

enum class commands: int {PUSH, PUSHR, POPR, JMP, JEQ, JNE, JA, JAE, JB,
                          JBE, CALL, END, POP, ADD, SUB, MUL, DIV, OUT,
                          IN, RET};

void processing(std::ifstream &byteCode, char *path) {
    int sizeOfLabel;
    byteCode.read((char *)&sizeOfLabel, sizeof(int));
    
    int label[sizeOfLabel];
    byteCode.read((char *)&label, sizeOfLabel * sizeof(int));
    
    /*
    std::cout << sizeOfLabel << "\n";
    for (int i = 0; i < sizeOfLabel; ++i) {
        std::cout << label[i] << " ";
    }
    std::cout << "\n\n";
    */

    const int cntOfWords = 1000;
    int stream[cntOfWords];
    byteCode.read((char *)stream, cntOfWords * sizeof(int));
    
    stack::Stack <int> stack;
    
    const int numbOfRegs = 256;
    int regs[numbOfRegs];

    for (int indexInStream = label[0]; indexInStream < cntOfWords; ) {
        //std::cout << ":" << stream[indexInStream] << "\n";
        switch (stream[indexInStream]) {
            case (int)commands::PUSH:
                command::PUSH(stream, indexInStream, stack, regs);
                break;

            case (int)commands::PUSHR:
                command::PUSHR(stream, indexInStream, stack, regs);
                break;

            case (int)commands::POPR:
                command::POPR(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JMP:
                command::JMP(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JEQ:
                command::JEQ(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JNE:
                command::JNE(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JA:
                command::JA(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JAE:
                command::JAE(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JB:
                command::JB(stream, indexInStream, stack, regs);
                break;

            case (int)commands::JBE:
                command::JBE(stream, indexInStream, stack, regs);
                break;

            case (int)commands::CALL:
                command::CALL(stream, indexInStream, stack, regs);
                break;

            case (int)commands::POP:
                command::POP(stream, indexInStream, stack, regs);
                break;

            case (int)commands::ADD:
                command::ADD(stream, indexInStream, stack, regs);
                break;

            case (int)commands::SUB:
                command::SUB(stream, indexInStream, stack, regs);
                break;

            case (int)commands::MUL:
                command::MUL(stream, indexInStream, stack, regs);
                break;

            case (int)commands::DIV:
                command::DIV(stream, indexInStream, stack, regs);
                break;

            case (int)commands::OUT:
                command::OUT(stream, indexInStream, stack, regs);
                break;

            case (int)commands::IN:
                command::IN(stream, indexInStream, stack, regs);
                break;

            case (int)commands::RET:
                command::RET(stream, indexInStream, stack, regs);
                break;
               
            case (int)commands::END:
                return;
            
            default:
                std::cout << "ОШИБКА в " << path << ":\n";
                std::cout << "    Програма не завершается\n";
                return;
        }
    }
    
    std::cout << "ОШИБКА в " << path << ":\n";
    std::cout << "    Програма не завершается\n";
}

}
