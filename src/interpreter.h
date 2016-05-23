#ifndef INTERPRETER_H_
#define INTERPRETER_H_

# include "read/head.h"

void jsr(uint16_t opcode);
void rts(uint16_t opcode);
void add(uint16_t opcode);
void bcc(uint16_t opcode);
void move(uint16_t opcode);
#endif
