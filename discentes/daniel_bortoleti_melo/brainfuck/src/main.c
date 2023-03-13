#include <stdio.h>
#include <stdlib.h>

#define TAPE_SIZE 30000

char tape[TAPE_SIZE];
char *ptr = tape;

void interpret(char *program, char *end)
{
    while (program < end)
    {
        switch (*program)
        {
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            (*ptr)++;
            break;
        case '-':
            (*ptr)--;
            break;
        case '.':
            putchar(*ptr);
            break;
        case ',':
            *ptr = getchar();
            break;
        case '[':
            if (*ptr == 0)
            {
                int loopCount = 1;
                while (loopCount > 0)
                {
                    program++;
                    if (*program == '[')
                        loopCount++;
                    if (*program == ']')
                        loopCount--;
                }
            }
            break;
        case ']':
            if (*ptr != 0)
            {
                int i = 1;
                while (i > 0)
                {
                    program--;
                    if (*program == ']')
                        i++;
                    if (*program == '[')
                        i--;
                }
            }
            break;
        }
        program++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <program.bf>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *program = (char *)malloc(fileSize * sizeof(char));
    if (program == NULL)
    {
        printf("Could not allocate memory\n");
        return 1;
    }

    fread(program, sizeof(char), fileSize, file);

    fclose(file);

    interpret(program, program + fileSize);

    free(program);

    return 0;
}
