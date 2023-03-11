#include <ctype.h>
// #include <errno.h>
#include <stdio.h>
#include <string.h>
#define MAX_TAMANHO 256
#define MAX_MEMORIA 65535

int P = 0;
int memoria[MAX_MEMORIA];

void verificaCaracter(char letra){
	if(letra == '>')
		P++;
	if(letra == '<')
		P--;
	if(letra == '+')
		memoria[P] += 1;
	if(letra == '-')
		memoria[P] -= 1;
	if(letra == '.')
	{
		// putchar(memoria[P] + '0');	
		putchar(memoria[P]);	
	}
	if(letra == ',')
		memoria[P] = getchar();
	// if(letra == '['){
	// 	while(letra != ']'){
			
	// 	}
	// }
		
}

int verificaSintaxe(char *palavra){
	char letra;
  unsigned i = 0;
	char alfabeto[] = {'>', '<', '+', '-', '.', ',', '[', ']', '\n','\t'}; 
	unsigned aceita = 0;

	while (i < strlen(palavra)) {
		letra = palavra[i];
		// printf("%c", letra);

		for(int j = 0; alfabeto[j]!=NULL; j++){
			if(letra == alfabeto[j]){
				aceita++;
				verificaCaracter(letra);
			}
		}

		// printf("\nACEITA %d\n", aceita);
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
  unsigned i = 0;

  file = fopen(nomeArquivo, "r");

  // #LENDO POR LINHA#
  while (fgets(texto, MAX_TAMANHO, file) != NULL) {
    palavra = strtok(texto, " ");
    // printf("LINHA: %s\n",texto);

    while (palavra != NULL) {
      // printf("Palavra: %s \n", palavra);

      // if (verificaLetra(palavra) < 1)
      //   printf(" %s ", palavra);

		 if(verificaSintaxe(palavra) != 0)
		 {	
			 printf("\nRejeitado! Erro de sintaxe em %s\n", palavra);
			 exit(0);
			 
		 }

      palavra = strtok(NULL, " ");
    }
  }
	
	printf("\nAceito\n");	

	printf("\nMEMORIA:\n");
	for(int i = 1; i<6; i++){
		printf(" [%d] ", memoria[i]);
	}
	
  fclose(file);
}