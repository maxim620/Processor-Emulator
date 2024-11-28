#ifndef INSTRUCTION_HANDLERS_H
#define INSTRUCTION_HANDLERS_H

#include "processor.h"

// Обработчики инструкций
int handle_halt(Processor *cpu);
int handle_mov(Processor *cpu);
int handle_movi(Processor *cpu);
int handle_inc(Processor *cpu);
int handle_add(Processor *cpu);
int handle_addi(Processor *cpu);
int handle_sub(Processor *cpu);
int handle_subi(Processor *cpu);
int handle_mul(Processor *cpu);
int handle_muli(Processor *cpu);
int handle_div(Processor *cpu);
int handle_divi(Processor *cpu);
int handle_xchg(Processor *cpu);
int handle_and(Processor *cpu);
int handle_andi(Processor *cpu);
int handle_or(Processor *cpu);
int handle_ori(Processor *cpu);
int handle_xor(Processor *cpu);
int handle_xori(Processor *cpu);
int handle_not(Processor *cpu);
int handle_neg(Processor *cpu);
int handle_jmp(Processor *cpu);
int handle_nop(Processor *cpu);
int handle_cmp(Processor *cpu);
int handle_cmpi(Processor *cpu);
int handle_int(Processor *cpu);
#endif // INSTRUCTION_HANDLERS_H 