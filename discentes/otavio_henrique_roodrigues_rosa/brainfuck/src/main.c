#include <stdio.h>
#include <stdlib.h>

int main(){

    int *memory = malloc(sizeof(int));
    FILE *arquivo = fopen("src/brainfuck.txt", "r");
    int ponteiro = 0;
    int posicao_arquivo = 0;

    if(arquivo == NULL){
        printf("Não é possível abrir o arquivo especificado!\n");
    }


    char temp;
    while(temp !=  EOF){
        temp = fgetc(arquivo);

        if(temp == '+')
            memory[ponteiro] += 1;

        if(temp == '-'){
            memory[ponteiro] -= 1;
        }
        
        if(temp == '>'){
            memory = realloc(memory, sizeof(int));
            ponteiro += 1;
        }
            
        if(temp == '.'){
            printf("%c", (char)memory[ponteiro]);
        }
            
        if(temp == '<')
            ponteiro -= 1;

        if(temp == '['){
            posicao_arquivo = ftell(arquivo);
        }

        if(temp == ']'){
            if(memory[ponteiro] != 0){
                fseek(arquivo, posicao_arquivo, SEEK_SET);
            }
        }
    }

    printf("\n");
    free(memory);
    fclose(arquivo);
    return 0;
}