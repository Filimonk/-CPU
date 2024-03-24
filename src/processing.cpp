#include <iostream>
#include <fstream>
#include <vector>
//#include <pair.h>

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

    std::vector <std::pair <int, int> > funcInputSize(cntOfWords);

    for (int indexInStream = label[0]; indexInStream < cntOfWords; ) {
        //std::cout << ":" << stream[indexInStream] << "\n";
        switch (stream[indexInStream]) {
            case (int)commands::PUSH:
                //std::cout << ":" << indexInStream << "\n";
                command::PUSH(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::PUSHR:
                command::PUSHR(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::POPR:
                command::POPR(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JMP:
                command::JMP(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JEQ:
                command::JEQ(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JNE:
                command::JNE(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JA:
                command::JA(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JAE:
                command::JAE(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JB:
                command::JB(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::JBE:
                command::JBE(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::CALL:
                command::CALL(funcInputSize, label,  stream, indexInStream, stack, regs);
                break;

            case (int)commands::POP:
                command::POP(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::ADD:
                command::ADD(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::SUB:
                command::SUB(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::MUL:
                command::MUL(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::DIV:
                command::DIV(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::OUT:
                command::OUT(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::IN:
                command::IN(label, stream, indexInStream, stack, regs);
                break;

            case (int)commands::RET:
                command::RET(funcInputSize, label, stream, indexInStream, stack, regs);
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
