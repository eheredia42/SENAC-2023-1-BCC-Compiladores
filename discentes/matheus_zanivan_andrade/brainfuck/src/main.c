#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    file = fopen("arquivo.txt", "r");
    if (file) {
        while ((ch = fgetc(file)) != EOF) {
            printf("%c", ch);
	}
        fclose(file);
    }
    return 0;
}

