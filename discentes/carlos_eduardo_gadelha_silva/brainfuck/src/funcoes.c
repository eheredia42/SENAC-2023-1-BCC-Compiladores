#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_TAMANHO 256
#define MAX_MEMORIA 30000

int P = 0;
int memoria[MAX_MEMORIA];
char mem_repeticao[MAX_MEMORIA];
int repeticao =0;


void verificaCaracter(char letra){

	if(repeticao == 0)
	{
		if(letra == '>')
			P++;
		if(letra == '<')
			P--;
		if(letra == '+')
			memoria[P] += 1;
		if(letra == '-')
			memoria[P] -= 1;
		if(letra == '.')
			putchar(memoria[P]);	
		if(letra == ',')
			memoria[P] = getchar();
		if(letra == '[')
			repeticao ++;
		if(letra == ']'){
			printf("\nRejeitado! Loop finalizado antes de ser inicializado!");
		 	exit(0);
		}
	}

	else 
	{
		if(letra == ']'){
		
			repeticao = 0;
			
			while(memoria[P] != 0){
				for(int i =0; i < MAX_MEMORIA ; i++)
					verificaCaracter(mem_repeticao[i]);
			}	
		}
			
		else{
			mem_repeticao[repeticao] = letra;
			repeticao ++;
		}
	}
}

int verificaSintaxe(char *palavra){
	char letra;
  unsigned i = 0;
	char alfabeto[] = {'>', '<', '+', '-', '.', ',', '[', ']', '\n','\t'}; 
	unsigned aceita = 0;

	while (i < strlen(palavra)) {
		letra = palavra[i];

		for(int j = 0; alfabeto[j]!=NULL; j++){
			if(letra == alfabeto[j]){
				aceita++;
				verificaCaracter(letra);
			}
		}

		if(aceita == 0)
			return 1;

		aceita =0;
		i++;
	}
	
	return 0; 
}


void lerArquivo(char *nomeArquivo) {
  FILE *file;
  char texto[MAX_TAMANHO];
  char *palavra;

  file = fopen(nomeArquivo, "r");

  // #LENDO POR LINHA#
  while (fgets(texto, MAX_TAMANHO, file) != NULL) {
    palavra = strtok(texto, " ");

    while (palavra != NULL) {
		 if(verificaSintaxe(palavra) != 0)
		 {	
			 printf("\nRejeitado! Caracter %s não pertence aos comandos da linguagem\n", palavra);
			 exit(0);
			 
		 }

      palavra = strtok(NULL, " ");
    }
  }
	
	printf("\nAceito\n");	
  fclose(file);
}