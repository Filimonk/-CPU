#include <iostream>

#include "command.h"
#include "../STACK/src/Stack.cpp"

namespace command
{

const int numbOfRegs = 256;

void PUSH(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    stack.push(stream[indexInStream + 1]);
    indexInStream += 2;
}

void PUSHR(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int ind = stream[indexInStream + 1];
    stack.push(regs[ind]);
    indexInStream += 2;
}

void POPR(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int ind = stream[indexInStream + 1];
    int val = stack.top();
    regs[ind] = val;
    stack.pop();
    indexInStream += 2;
}

void JMP(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JEQ(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JNE(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JA(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JAE(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JB(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void JBE(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void CALL(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

void POP(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    stack.pop();
    ++indexInStream;
}

void ADD(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp += stack.top();
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void SUB(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp -= stack.top(); // Вычитание из верхнего числа меньшее
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void MUL(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp *= stack.top();
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void DIV(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    temp /= stack.top(); // Деление верхнего числа на нижнее
    stack.pop();
    stack.push(temp);
    ++indexInStream;
}

void OUT(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp = stack.top();
    stack.pop();
    std::cout << temp << "\n";
    ++indexInStream;
}

void IN(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    int temp;
    std::cin >> temp;
    stack.push(temp);
    ++indexInStream;
}

void RET(int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs) {
    
    std::cout << "ahaha\n";
}

}
