#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 30000

int main(int argc, char **argv)
{
    char mem[MEM_SIZE] = {0};
    char *ptr = mem;
    char c;

    if (argc < 2)
    {
        printf("Usage: %s <program.bf>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (!f)
    {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    while ((c = fgetc(f)) != EOF)
    {
        switch (c)
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
                int depth = 1;
                while (depth > 0)
                {
                    c = fgetc(f);
                    if (c == '[')
                        depth++;
                    if (c == ']')
                        depth--;
                }
            }
            break;
        case ']':
            if (*ptr != 0)
            {
                int depth = 1;
                while (depth > 0)
                {
                    c = fgetc(f);
                    if (c == '[')
                        depth--;
                    if (c == ']')
                        depth++;
                }
                fseek(f, -1, SEEK_CUR);
            }
            break;
        default:
            break;
        }
    }

    fclose(f);

    return 0;
}
