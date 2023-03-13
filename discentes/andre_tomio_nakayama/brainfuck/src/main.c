// https://pt.wikipedia.org/wiki/Brainfuck

#include <stdio.h>
#include <stdlib.h>

// 5000 células de memória
#define MAX_MEN 5000

int brainfuck(FILE *file, int quantidade) {
  // char ch;
  int mem = 0, num_caracter = 0;
  // char memoria[MAX_MEN + 1];
  char memoria[MAX_MEN];

  // fseek(file, 0, SEEK_END);

  char *caracter = (char *)malloc(quantidade);

  rewind(file);

  for (int a = 0; a < quantidade; a++) {
    // Coloca cada caracter do arquivo de entrada dentro da variável caracter
    caracter[a] = fgetc(file);
  }

  while (num_caracter < quantidade) {
    // leitura de caracter por caracter para realizar a ação
    char acao = caracter[num_caracter];
    
    if (acao == '>'){
      mem++;
    }

    else if(acao == '<'){
      mem--;
    } 

    else if(acao == '.'){
      putchar(memoria[mem]);
    }

    else if(acao == ','){
      memoria[mem] = getchar();
    } 

    else if (acao == '+'){
      memoria[mem]++;
    }
      
    else if (acao == '-'){
      memoria[mem]--;
    }

    else if (acao == '[' && !memoria[mem]) {
      int controle = 1;

      while (controle) {
        if (++num_caracter == quantidade) return(0);
        if (caracter[num_caracter] == '[') controle++;
        if (caracter[num_caracter] == ']') controle--;
      }
    } 
    
    else if (acao == ']' && memoria[mem]) {
      int controle = 1;

      while (controle) {
        if (--num_caracter == -1) return(0);
        if (caracter[num_caracter] == ']') controle++;
        if (caracter[num_caracter] == '[') controle--;
      }
    } 

    // Verifica se o caracter pertence aos 8 comandos do brainfuck
    else if (!(acao == '\t' || acao == '\n' || acao == ' ' || acao == '<' ||
                 acao == '>' || acao == '[' || acao == ']' || acao == '.' || acao == ',' || acao == '+' || acao == '-')) {
      printf("Comando não encontrado");
      return(0);
    }
    
    num_caracter++;
  }
  return 0;
}

int main(int argc, char **argv) {
  // Leitura do arquivo de entrada
  FILE *file;
  file = fopen(argv[1], "r");

  int count = 0;
  char x;

  // Contador de caracteres dentro do arquivo de entrada para percorrer o arquivo e realizar as devidas ações
  for (x = getc(file); x != EOF; x = getc(file)) {
    count = count + 1;
  }

  if (!file) {
    printf("Arquivo não foi encontrado\n");
    return (0);
  }

  return brainfuck(file, count);
}