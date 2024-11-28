#include "processor.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    Processor cpu;
    initProcessor(&cpu);

    if (!loadProgram(&cpu, argv[1]))
    {
        return 1;
    }

    runProcessor(&cpu);
    
    // Вывод заголовка таблицы
    //printf("\n       ");
    //for (int i = 0; i < 16; i++) {
    //    printf("   %X  ", i);
    //}
    //printf("\n       ");
    //for (int i = 0; i < 16; i++) {
    //    printf("------");
    //}
    //printf("\n");

    // Вывод содержимого RAM в виде таблицы 32x16
    //for (int row = 0; row < 32; row++) {
    //    printf("0x%04X |", row * 16);
    //    for (int col = 0; col < 16; col++) {
    //        int index = row * 16 + col;
    //        printf(" %04X ", cpu.memory[index]);
    //    }
    //    printf("\n");
    //}

    getchar();
    return 0;
}
