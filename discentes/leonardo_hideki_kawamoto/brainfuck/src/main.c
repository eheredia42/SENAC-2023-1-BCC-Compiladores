
#include <stdio.h>

int main(void){
    FILE *arq;
    char c;
    int val[99999];
    int valPont = 0;
    char caract[99999];
    int caractPont = 0;
    int *p;

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
      if(c == '>'){
        p = &valPont;
        (*p)++;
      }
      else if(c == '<'){
         p = &valPont;
         (*p)--;
      }
      else if(c == '+'){
        p = &val[valPont];
        (*p)++;
      }
      else if(c == '-'){
        p = &val[valPont];
        (*p)--;
      }
      caractPont++;
    }
}