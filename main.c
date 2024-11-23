#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define RAM_SIZE 65536
#define INSTRUCTION_HALT 0x00
#define INSTRUCTION_PRINT 0x01
#define INSTRUCTION_PRINT_ERROR 0x02
#define INSTRUCTION_INCREMENT 0x03

typedef struct {
    uint8_t memory[RAM_SIZE];
    uint16_t program_counter;
} Processor;

// Инициализация процессора
void initProcessor(Processor *cpu) {
    for (int i = 0; i < RAM_SIZE; i++) {
        cpu->memory[i] = 0;
    }
    cpu->program_counter = 0;
}

// Загрузка программы в память
int loadProgram(Processor *cpu, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    size_t bytes_read = fread(cpu->memory, 1, RAM_SIZE, file);
    fclose(file);
    
    if (bytes_read == 0) {
        printf("Error: Empty file or read error\n");
        return 0;
    }
    
    return 1;
}

// Выполнение одной инструкции
int executeInstruction(Processor *cpu) {
    uint8_t instruction = cpu->memory[cpu->program_counter];
    
    switch (instruction) {
        case INSTRUCTION_HALT:
            printf("Execution terminated.\n");
            return 0;
            
        case INSTRUCTION_PRINT:
            printf("hi\n");
            cpu->program_counter++;
            break;
        case INSTRUCTION_PRINT_ERROR:
            printf("Error\n");
            cpu->program_counter++;
            break;
            
        case INSTRUCTION_INCREMENT: {
            cpu->program_counter++;
            uint8_t address = cpu->memory[cpu->program_counter];
            cpu->memory[address]++;
            printf("Memory[%d] increased to %d\n", address, cpu->memory[address]);
            cpu->program_counter++;
            break;
        }
            
        default:
            printf("Unknown instruction: 0x%02X at position %d\n", 
                   instruction, cpu->program_counter);
            return 0;
    }
    
    return 1;
}

// Основной цикл выполнения
void runProcessor(Processor *cpu) {
    while (cpu->program_counter < RAM_SIZE) {
        if (!executeInstruction(cpu)) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    Processor cpu;
    initProcessor(&cpu);

    if (!loadProgram(&cpu, argv[1])) {
        return 1;
    }

    runProcessor(&cpu);
    getchar();
    
    return 0;
}