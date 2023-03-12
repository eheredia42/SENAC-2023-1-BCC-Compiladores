#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 30000

int main(int argc, char** argv) {
  char ch;
  char alphabet[] = {'+', '-', '>', '<', '[', ']', '.', ','};
  int memory[MAXSIZE] = {0};
  int source[MAXSIZE];
  int m_ptr = 0;
  int s_ptr = 0;
  int s_siz = 0;
  int open_key = 0;

  if (argc < 2) {
    printf("\nUSAGE: ./brainfuck <input_file>\n");
    return 1;
  }
  
  FILE *input_file;
  input_file = fopen(argv[1],"r");

  if (!input_file) {
    printf("\nError loading input file!\n");
    return 1;
  }

  // adiciona os caracteres que pertencem ao dicionario a array source.
  while ((ch = getc(input_file)) != EOF) {
    if (memchr(alphabet, ch, sizeof(alphabet))) {
      source[s_ptr] = ch;
      s_ptr++;
    }
  }

  s_siz = s_ptr;
  s_ptr = 0;

  if (s_siz > MAXSIZE) {
    printf("\nSource code is bigger than MAXSIZE (%d)", MAXSIZE);
    return 1;
  }

  //le o codigo da fita 
  while (s_ptr < s_siz) {
    ch = source[s_ptr];

    if (ch == '>') m_ptr++;
    else if (ch == '<') m_ptr--;
    else if (ch == '+') memory[m_ptr]++;
    else if (ch == '-') memory[m_ptr]--;
    else if (ch == '.') printf("%c", memory[m_ptr]);
    else if (ch == ',') memory[m_ptr] = fgetc(stdin);

    //se o byte no ponteiro for zero, pula para o proximo comando depois do par ]
    //se nao move para o proximo comando 
    else if (ch == '[' && !memory[m_ptr]) {
      open_key=1;
      while (open_key > 0) {
        s_ptr++;
        if (s_ptr > s_siz) {
          printf("\nError, [ was never closed!\n");
          return 1;
        }
        if (source[s_ptr] == '[') open_key++;
        else if (source[s_ptr] == ']') open_key--;
      }
    }

    //se o byte no ponteiro nao for zero, volta para o comando logo apos o [ de abertura
    //se nao move para o proximo comando
    else if (ch == ']' && memory[m_ptr]) {
      open_key = 1;
      while (open_key > 0) {
        s_ptr--;
        if (s_ptr < 0) {
          printf("\nError, ] was never open!");
          return 1;
        }
        if (source[s_ptr] == '[') open_key--;
        else if (source[s_ptr] == ']') open_key++;
      }
    }
    //move para o proximo comando
    s_ptr++;
  }

  return 0;
}
