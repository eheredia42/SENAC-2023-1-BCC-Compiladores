#include <stdio.h>
#define MEM_SIZE 30000

void interpretadorBF(FILE *file)
{
	char fita[MEM_SIZE] = {0};
	char *ptr = fita;
	int loops;
	/*
		Teve que se criar este outro array para armazenar
		o código em BF. Tentei usar o fgetc, porém tava dando muito erro.
	*/
	char codBf[MEM_SIZE] = {0};

	while (fgets(codBf, MEM_SIZE, file) != NULL)
	{
		// O \0 representa o caractere nulo, pois strings em C são como arrays que terminam em nulo
		for (int i = 0; codBf[i] != '\0'; i++)
		{
			switch (codBf[i])
			{
				case '<':ptr--;break;
				case '>':ptr++;break;
				case '+':(*ptr)++;break;
				case '-':(*ptr)--;break;
				case '.':putchar(*ptr);break;
				case ',':*ptr = getchar();break;
				case '[':
                    // checa se o ponteiro atual não é zero, iniciando o loop
                    if (*ptr == 0) {
                        // chega quantos loops irão ter
                        loops = 1;
                        while (loops > 0) {
                            i++;
                            if (codBf[i] == '[') {
                                loops++;
                            } else if (codBf[i] == ']') {
                                loops--;
                            }
                        }
                    }
                    break;
                case ']':
                    if (*ptr != 0) {
                        loops = 1;
                        while (loops > 0) {
                            i--;
                            if (codBf[i] == '[') {
                                loops--;
                            } else if (codBf[i] == ']') {
                                loops++;
                            }
                        }
                    }
                    break;
			}
		}
	}
}