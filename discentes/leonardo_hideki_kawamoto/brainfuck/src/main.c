
#include <stdio.h>

int main(void){
    FILE *arq;
    char c;
    int val[99999];
    char caract[99999];
    int caractPont = 0;

    arq = fopen("arquivo.txt", "r");

    for (int i = 0; i < 99999; i++) {
        val[i] = 0;
        caract[i] = '\0';
    }

    while (c != EOF) {
        c = fgetc(arq);
        caract[caractPont] = c;
        caractPont++;
    }

    fclose(arq);
}