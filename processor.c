#include "processor.h"

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
    case HALT:
        printf("Execution terminated.\n");
        return 0;
    case MOV:
    {
        cpu->program_counter++;
        uint16_t dest_address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t src_address = cpu->memory[cpu->program_counter];
        cpu->memory[dest_address] = cpu->memory[src_address];
        cpu->program_counter++;
        break;
    }
    case MOVI:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t value = cpu->memory[cpu->program_counter];
        cpu->memory[address] = value;
        cpu->program_counter++;
        break;
    }
    case INC:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->memory[address]++;
        cpu->program_counter++;
        break;
    }
    case ADD:
    {
        cpu->program_counter++;
        uint16_t address1 = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t address2 = cpu->memory[cpu->program_counter];
        cpu->memory[address1] += cpu->memory[address2];
        cpu->program_counter++;
        break;
    }
    case ADDI:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t value = cpu->memory[cpu->program_counter];
        cpu->memory[address] += value;
        cpu->program_counter++;
        break;
    }
    case SUB:
    {
        cpu->program_counter++;
        uint16_t address1 = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t address2 = cpu->memory[cpu->program_counter];
        cpu->memory[address1] -= cpu->memory[address2];
        cpu->program_counter++;
        break;
    }
    case SUBI:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t value = cpu->memory[cpu->program_counter];
        cpu->memory[address] -= value;
        cpu->program_counter++;
        break;
    }
    case MUL:
    {
        cpu->program_counter++;
        uint16_t address1 = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t address2 = cpu->memory[cpu->program_counter];
        cpu->memory[address1] *= cpu->memory[address2];
        cpu->program_counter++;
        break;
    }
    case MULI:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t value = cpu->memory[cpu->program_counter];
        cpu->memory[address] *= value;
        cpu->program_counter++;
        break;
    }
    case DIV:
    {
        cpu->program_counter++;
        uint16_t address1 = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t address2 = cpu->memory[cpu->program_counter];
        cpu->memory[address1] /= cpu->memory[address2];
        cpu->program_counter++;
        break;
    }
    case DIVI:
    {
        cpu->program_counter++;
        uint16_t address = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t value = cpu->memory[cpu->program_counter];
        cpu->memory[address] /= value;
        cpu->program_counter++;
        break;
    }
    case XCHG:
    {
        cpu->program_counter++;
        uint16_t address1 = cpu->memory[cpu->program_counter];
        cpu->program_counter++;
        uint16_t address2 = cpu->memory[cpu->program_counter];
        cpu->memory[address1] = cpu->memory[address2];
        cpu->program_counter++;
        break;
    }

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