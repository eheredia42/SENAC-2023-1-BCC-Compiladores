#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 10000

void handle_command(command) {
    switch(command) {
        default:
        printf("sorry, unknown command \n");
        break;
    }
}

int main(void) {
    char fita[CAPACIDADE] = {0}; //modificar
    char *ponteiro = fita;
    char command;

    FILE *brainfuck = fopen("brainfuck.txt", "r");
    if(brainfuck == NULL) {
        printf("404: File not found.");
        exit(1);
    }

    while (command != EOF) {
        command = fgetc(brainfuck);
        handle_command(command);
    }

    fclose(brainfuck);
    return 0;
}