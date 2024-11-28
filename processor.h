#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>
#include <stdio.h>
#include "instructions.h"

#define RAM_SIZE 65536

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
