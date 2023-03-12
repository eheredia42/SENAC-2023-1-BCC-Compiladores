#include "funcoes.h"

int main(int argc, char *argv[])
{
	FILE *file;
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Erro ao abrir o argv[1]!\nUso: ./main exemplo.txt\n");
		return 1;
	}
	interpretadorBF(file);
	fclose(file);
	return 0;
}