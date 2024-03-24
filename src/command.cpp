#include <iostream>
#include <vector>
//#include <pair.h>

#include "command.h"
#include "../STACK/src/Stack.cpp"

namespace command
{

const int numbOfRegs = 256;

void PUSH(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    stack.push(stream[indexInStream + 1]);
    indexInStream += 2;
}

void PUSHR(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int ind = stream[indexInStream + 1];
    stack.push(regs[ind]);
    indexInStream += 2;
}

void POPR(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int ind = stream[indexInStream + 1];
    int val = stack.top();
    regs[ind] = val;
    stack.pop();
    indexInStream += 2;
}

void JMP(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    indexInStream = label[stream[indexInStream + 1]];
}

void JEQ(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 == stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void JNE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 != stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void JA(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 > stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void JAE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 >= stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void JB(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 < stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void JBE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int val1 = stack.top();
    stack.pop();
    if (val1 <= stack.top()) {
        indexInStream = label[stream[indexInStream + 1]];
    }
    else {
        indexInStream += 2;
    }
    stack.push(val1);
}

void CALL(std::vector <std::pair <int, int> > &funcInputSize, int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    funcInputSize.push_back({stack.getSize(), indexInStream + 2});
    indexInStream = label[stream[indexInStream + 1]];
}

void POP(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    stack.pop();
    ++indexInStream;
}

void ADD(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp += stack.top();
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void SUB(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp -= stack.top(); // Вычитание из верхнего числа меньшее
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void MUL(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp *= stack.top();
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void DIV(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp /= stack.top(); // Деление верхнего числа на нижнее
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void OUT(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    std::cout << temp << "\n";
    ++indexInStream;
}

void IN(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp;
    std::cin >> temp;
    stack.push(temp);
    ++indexInStream;
}

void RET(std::vector <std::pair <int, int> > &funcInputSize, int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    std::pair <int, int> lastVal = funcInputSize[funcInputSize.size() - 1];
    while (stack.getSize() != lastVal.first) {
        stack.pop();
    }

    indexInStream = lastVal.second;
    funcInputSize.pop_back();
}

}
