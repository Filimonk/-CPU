#ifndef CPP_COMMAND
#define CPP_COMMAND

#include "Stack.h"

namespace command
{

void PUSH(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void PUSHR(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void POPR(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JMP(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JEQ(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JNE(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JA(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JAE(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JB(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void JBE(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void CALL(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void POP(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void ADD(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void SUB(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void MUL(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void DIV(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void OUT(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void IN(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

void RET(int *stream,  int &indexInStream, stack::Stack <int> &stack, int *regs);

}

#endif //CPP_COMMAND
