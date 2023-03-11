
#include <stdio.h>

void brainfuck(void){
    FILE *arq;
    char c;
    int val[99999];
    int valPont = 0;
    char caract[99999];
    int caractPont = 0;
    int *p;
    int qtdColc = 0;

    arq = fopen("arquivo.txt", "r");

    for (int i = 0; i < 99999; i++) {
        val[i] = 0;
        caract[i] = NULL;
    }

    while (c != EOF) {
        c = fgetc(arq);
        caract[caractPont] = c;
        caractPont++;
    }

    fclose(arq);

    caractPont = 0;

    while (c != NULL) {
      c = caract[caractPont];
      switch (c) {
        case '>':
          p = &valPont;
          (*p)++;
          break;
        case '<':
          p = &valPont;
          (*p)--;
          break;
        case '+':
          p = &val[valPont];
          (*p)++;
          break;
        case '-':
          p = &val[valPont];
          (*p)--;
          break;
        case '.':
          p = &val[valPont];
          printf("%c", *p);
          break;
        case ',':
          p = &val[valPont];
          p = getchar();
          break;
        case '[':
          if (val[valPont] == 0) {
            caractPont++;
            while (c != EOF) {
              c = caract[caractPont];
                      
              if (c == ']' && qtdColc == 0) {
                break;
              } 
              else if (c == ']') {
                qtdColc--;
              } 
              else if (c == '[') {
                qtdColc++;
              }

                caractPont++;
            }
          }
          break;
        case ']':
          if (val[valPont] != 0) {
            caractPont--;

            while (caractPont >= 0) {
              c = caract[caractPont];

              if (c == '[' && qtdColc == 0) {
                break;
              }
              else if (c == '[') {
                qtdColc--;
              } 
              else if (c == ']') {
                qtdColc++;
              }

              caractPont--;
            }
          }
          break;
      }
      caractPont++;
    }
}