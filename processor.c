#include "processor.h"
#include "instruction_handlers.h"

void initProcessor(Processor *cpu)
{
    for (int i = 0; i < RAM_SIZE; i++)
    {
        cpu->memory[i] = 0;
    }
    cpu->program_counter = 0;
}

int loadProgram(Processor *cpu, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    size_t words_read = fread(cpu->memory, sizeof(uint16_t), RAM_SIZE, file);
    fclose(file);

    if (words_read == 0)
    {
        printf("Error: Empty file or read error\n");
        return 0;
    }

    return 1;
}

int executeInstruction(Processor *cpu)
{
    uint16_t instruction = cpu->memory[cpu->program_counter];

    switch (instruction)
    {
        case HALT: return handle_halt(cpu);
        case MOV:  return handle_mov(cpu);
        case MOVI: return handle_movi(cpu);
        case INC:  return handle_inc(cpu);
        case ADD:  return handle_add(cpu);
        case ADDI: return handle_addi(cpu);
        case SUB:  return handle_sub(cpu);
        case SUBI: return handle_subi(cpu);
        case MUL:  return handle_mul(cpu);
        case MULI: return handle_muli(cpu);
        case DIV:  return handle_div(cpu);
        case DIVI: return handle_divi(cpu);
        case XCHG: return handle_xchg(cpu);
        case AND:  return handle_and(cpu);
        case ANDI: return handle_andi(cpu);
        case OR:   return handle_or(cpu);
        case ORI:  return handle_ori(cpu);
        case XOR:  return handle_xor(cpu);
        case XORI: return handle_xori(cpu);
        case NOT:  return handle_not(cpu);
        case NEG:  return handle_neg(cpu);
        case JMP:  return handle_jmp(cpu);
        case NOP:  return handle_nop(cpu);
        case CMP:  return handle_cmp(cpu);
        case CMPI: return handle_cmpi(cpu);
        
        default:
            printf("Unknown instruction: 0x%04X at position %d\n",
                   instruction, cpu->program_counter);
            return 0;
    }

    return 1;
}

void runProcessor(Processor *cpu)
{
    while (cpu->program_counter < RAM_SIZE)
    {
        if (!executeInstruction(cpu))
        {
            break;
        }
    }
}
