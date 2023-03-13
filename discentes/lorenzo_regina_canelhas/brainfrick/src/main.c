#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPE_SIZE 30000

int main(int argc, char *argv[]) {
    char tape[TAPE_SIZE] = {0};
    char *code;
    int code_length;
    int ptr = 0;

    // Read in the code from a file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file '%s'\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    code_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    code = malloc(code_length + 1);
    fread(code, 1, code_length, fp);
    fclose(fp);

    code[code_length] = '\0';

    // Interpret the code
    for (int i = 0; i < code_length; i++) {
        switch (code[i]) {
            case '>':
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                tape[ptr]++;
                break;
            case '-':
                tape[ptr]--;
                break;
            case '.':
                putchar(tape[ptr]);
                break;
            case ',':
                tape[ptr] = getchar();
                break;
            case '[':
                if (tape[ptr] == 0) {
                    int loop_count = 1;
                    while (loop_count > 0) {
                        i++;
                        if (code[i] == '[') {
                            loop_count++;
                        } else if (code[i] == ']') {
                            loop_count--;
                        }
                    }
                }
                break;
            case ']':
                if (tape[ptr] != 0) {
                    int loop_count = 1;
                    while (loop_count > 0) {
                        i--;
                        if (code[i] == '[') {
                            loop_count--;
                        } else if (code[i] == ']') {
                            loop_count++;
                        }
                    }
                }
                break;
        }
    }

    free(code);

    return 0;
}