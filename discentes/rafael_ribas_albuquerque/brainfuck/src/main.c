#include <stdio.h>

#define TAMANHODATA 3000



void brainfuck (char *texto, char *comeco) {

	char comandos;

	char dados[TAMANHODATA] = {0};

	char *ponteiro;

	ponteiro = &dados[TAMANHODATA / 2]; //iniciar o ponteiro na metade do vetor, assim consigo ir tanto pra direita quanto ppara esquerda 


		while (comandos = *texto++) {
	
			switch (comandos) {
				
	    case '>':
	      printf("chegou >");
				ponteiro++;
	      break;
	    
			case '<':   
	    printf("chegou <");
				ponteiro--;
	      break;
	    
			case '+':  
	    	printf("chegou +");
				(*ponteiro)++;
	      break;
	    
			case '-':  
	    	printf("chegou -");
				(*ponteiro)--;
	      break;
	    case '.':   
	    printf("chegou .");
				printf("%c", *ponteiro);
	      break;
	    
			case ',':  
				printf("chegou ,");
	      *ponteiro = *comeco++;
	      break;

			case '[':
				printf("chegou [");
				if (!*ponteiro){

					//procura até a outra chave e faz seu loop
					for (int i = 1; i; texto++){

						if (*texto == '['){
							i++;
						}
						else if(*texto == ']'){
							i--;
						}
						break;
					}
				}

			case ']':
printf("chegou ]");
				if (*ponteiro){

					texto -= 2;

					for (int i = 1; i; texto--) {

						if(*texto == ']') {
							i++;
						}
						else if (*texto == '[') {
							i--;
						}
						texto++;
					}
				}
			
				break;
		}
	
			printf("\n");
	}
}

int main() {
  
	char *hello_world_code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
  
	char *input = "";
  
	brainfuck(hello_world_code, input);
  return 0;
}