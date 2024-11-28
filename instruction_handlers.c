#include "instruction_handlers.h"
#include "instructions.h"

int handle_halt(Processor *cpu) {
    printf("Execution terminated.\n");
    return 0;
}


int handle_mov(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] = cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}

int handle_movi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[address] = value;
    cpu->program_counter++;
    return 1;
}

int handle_inc(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->memory[address]++;
    cpu->program_counter++;
    return 1;
}

int handle_add(Processor *cpu) {   
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] += cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_addi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] += value;
    cpu->program_counter++;
    return 1;
}
int handle_sub(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] -= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_subi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] -= value;
    cpu->program_counter++;
    return 1;
}
int handle_mul(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] *= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_muli(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] *= value;
    cpu->program_counter++;
    return 1;
}

int handle_div(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] /= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_divi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] /= value;
    cpu->program_counter++;
    return 1;
}
int handle_neg(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->memory[address] = -cpu->memory[address];
    cpu->program_counter++;
    return 1;
}
int handle_xchg(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address1 = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t address2 = cpu->memory[cpu->program_counter];
    uint16_t temp = cpu->memory[address1];
    cpu->memory[address1] = cpu->memory[address2];
    cpu->memory[address2] = temp;
    cpu->program_counter++;
    return 1;
}
int handle_and(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] &= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_andi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] &= value;
    cpu->program_counter++;
    return 1;
}
int handle_or(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] |= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_ori(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] |= value;
    cpu->program_counter++;
    return 1;
}
int handle_xor(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t src_address = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] ^= cpu->memory[src_address];
    cpu->program_counter++;
    return 1;
}
int handle_xori(Processor *cpu) {
    cpu->program_counter++;
    uint16_t dest_address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    cpu->memory[dest_address] ^= value;
    cpu->program_counter++;
    return 1;
}
int handle_not(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->memory[address] = ~cpu->memory[address];
    cpu->program_counter++;
    return 1;
}
int handle_jmp(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->program_counter = address;
    return 1;
}
int handle_nop(Processor *cpu) {
    cpu->program_counter++;
    return 1;
}

int handle_cmp(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address1 = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t address2 = cpu->memory[cpu->program_counter];
    // Просто сравниваем значения
    cpu->memory[address1] = (cpu->memory[address1] == cpu->memory[address2]) ? 1 : 0;
    cpu->program_counter++;
    return 1;
}

int handle_cmpi(Processor *cpu) {
    cpu->program_counter++;
    uint16_t address = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    uint16_t value = cpu->memory[cpu->program_counter];
    // Сравниваем с непосредственным значением
    cpu->memory[address] = (cpu->memory[address] == value) ? 1 : 0;
    cpu->program_counter++;
    return 1;
}

int handle_int(Processor *cpu)
{
    cpu->program_counter++;
    uint16_t interrupt_number = cpu->memory[cpu->program_counter];
    cpu->program_counter++;
    return 1;
}
