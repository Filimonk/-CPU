#ifndef CPP_COMMAND
#define CPP_COMMAND

#include "Stack.h"

namespace command
{

void PUSH(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void PUSHR(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void POPR(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JMP(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JEQ(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JNE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JA(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JAE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JB(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void JBE(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void CALL(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void POP(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void ADD(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void SUB(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void MUL(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void DIV(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void OUT(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void IN(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);

void RET(int *label, int *stream, int &indexInStream, stack::Stack <int> &stack, int *regs);    

}

#endif //CPP_COMMAND
