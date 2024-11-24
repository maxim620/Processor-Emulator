#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>
#include <stdio.h>

#define RAM_SIZE 65536
#define HALT 0x0000
#define MOV 0x0001  // move
#define MOVI 0x0002 // move immediate
#define INC 0x0003  // increment
#define ADD 0x0004  // add
#define ADDI 0x0005 // add immediate
#define SUB 0x0006  // subtract
#define SUBI 0x0007 // subtract immediate
#define MUL 0x0008  // multiply
#define MULI 0x0009 // multiply immediate
#define DIV 0x000A  // divide
#define DIVI 0x000B // divide immediate
#define XCHG 0x000C // exchange

typedef struct
{
    uint16_t memory[RAM_SIZE];
    uint16_t program_counter;
} Processor;

void initProcessor(Processor *cpu);
int loadProgram(Processor *cpu, const char *filename);
int executeInstruction(Processor *cpu);
void runProcessor(Processor *cpu);

#endif // PROCESSOR_H