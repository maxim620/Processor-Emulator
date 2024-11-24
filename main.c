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
    getchar();
    return 0;
}
