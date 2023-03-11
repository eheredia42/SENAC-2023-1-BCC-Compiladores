#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_SIZE 10//30000

void interpretadorBF(FILE *file){
	char fita[MEM_SIZE] = {0};
	char c;
	char *ptr = fita;

	while( (c=fgetc(file)) !=EOF) {
		switch(c){
			case '<':ptr--;break;
			case '>':ptr++;break;
			case '+':(*ptr)++;break;
			case '-':(*ptr)--;break;
			case '.':putchar(*ptr);break;
			case ',':*ptr = getchar();break;
			case '[':printf(" foi %c\n",c);break;
			case ']':printf(" foi %c\n",c);break;
		}
	}

	for (int i = 0; i < MEM_SIZE; i++)
	{
		printf("[%d]",fita[i]);
	}
	
}