// Desenvolvido por Rafael Nascimento Lourenco

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPE_SIZE 30000
#define NESTED_LOOPS_LIMIT 10

typedef struct LoopsStructures {
	char *condition;
	uint64_t initialIndex;
} loopStructure;

bool itsLanguageCaracter(char ch) {
	return ch == '<' || ch == '>' || ch == '[' || ch == ']' || ch == ',' ||
		   ch == '+' || ch == '-' || ch == '.';
}

void throwError(char *message) {
	if (message == NULL || message[0] == '\0') {
		printf("Error: Unspecified\n");
	} else {
		printf("Error: %s\n", message);
	}
	exit(1);
}

void validateIndex(int index, int limit) {
	if (index < 0 || index >= limit) {
		throwError("Try to use wrong index from tape");
	}
}

void validateMalloc(void *pointer) {
	if (pointer == NULL) {
		throwError("Malloc return null");
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		throwError("Not found file path");
	}
	char ch = '\0';
	loopStructure *listLoopStructure =
		(loopStructure *)malloc(sizeof(loopStructure) * NESTED_LOOPS_LIMIT);
	uint64_t loopStructureIndex = 0;

	char *tape = (char *)malloc(sizeof(char) * TAPE_SIZE);
	uint64_t tapeIndex = TAPE_SIZE / 2;
	memset(tape, '\0', TAPE_SIZE);

	FILE *file = fopen(argv[1], "r");

	if (file == NULL) {
	    throwError("Opening file");
	}

	fseek(file, 0, SEEK_END);
	uint16_t fileSize = ftell(file);
	rewind(file);

	char *bfProgram = (char *)malloc(sizeof(char) * fileSize);
	uint64_t bfProgramIndex = 0;

	validateMalloc(bfProgram);

	int bracketCounter = 0;
	while (ch != EOF) {
		ch = (char)fgetc(file);
		if (itsLanguageCaracter(ch)) {

			if (ch == '[')
				bracketCounter++;

			if (ch == ']')
				bracketCounter--;

			bfProgram[bfProgramIndex] = ch;
			bfProgramIndex++;
		}
	}

	if (bracketCounter > 0) {
		throwError("Malformed code, brackets balance off by" + bracketCounter);
	}

	fclose(file);

	uint64_t lastIndex = bfProgramIndex;
	bfProgramIndex = 0;
	while (lastIndex > bfProgramIndex) {
		ch = bfProgram[bfProgramIndex];
		switch (ch) {
		case '>':
			tapeIndex++;
			break;
		case '<':
			tapeIndex--;
			break;
		case '+':
			validateIndex(tapeIndex, TAPE_SIZE);
			tape[tapeIndex]++;
			break;
		case '-':
			validateIndex(tapeIndex, TAPE_SIZE);
			tape[tapeIndex]--;
			break;
		case '.':
			validateIndex(tapeIndex, TAPE_SIZE);
			putchar(tape[tapeIndex]);
			break;
		case '[':
			if (loopStructureIndex >= NESTED_LOOPS_LIMIT)
				throwError("Nested loop limit");
			listLoopStructure[loopStructureIndex].condition = tape + tapeIndex;
			listLoopStructure[loopStructureIndex].initialIndex = bfProgramIndex;
			loopStructureIndex++;
			break;
		case ']':
			if (loopStructureIndex > 0) {
				if (*(listLoopStructure[loopStructureIndex - 1].condition) >
					0) {
					bfProgramIndex =
						listLoopStructure[loopStructureIndex - 1].initialIndex;
				} else {
					listLoopStructure[loopStructureIndex - 1].condition = NULL;
					listLoopStructure[loopStructureIndex - 1].initialIndex = 0;
					loopStructureIndex--;
				}
			}
			break;
		case ',':
			tape[tapeIndex] = getchar();
			break;
		}
		bfProgramIndex++;
	}

    free(listLoopStructure);
    free(tape);
    free(bfProgram);
	return 0;
}