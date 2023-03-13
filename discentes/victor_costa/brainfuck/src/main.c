#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_FILE "./data/program.bf"

char *readFile()
{
  FILE *fp = fopen(PROGRAM_FILE, "r");

  if (fp == NULL)
  {
    printf("Error: could not open file %s", PROGRAM_FILE);
    exit(1);
  }

  char ch, *buffer = malloc(0);
  int count = 0;

  while ((ch = fgetc(fp)) != EOF)
  {
    buffer = realloc(buffer, ++count * sizeof(char));
    buffer[count - 1] = ch;
  }

  fclose(fp);
  return buffer;
}

void print_memory(int MEMORY[100], char ch, int ph, int rh)
{
  printf("%c > ", ch);

  for (int i = 0; i < 15; i++)
  {
    printf("%d|", MEMORY[i]);
  }

  printf(" (%d, %d)\n", ph, rh);
}

int *push_loop_stack(int *LOOP_STACK, int *loopStackLen, int value)
{
  (*loopStackLen)++;

  LOOP_STACK = realloc(LOOP_STACK, (*loopStackLen) * sizeof(int));
  LOOP_STACK[(*loopStackLen) - 1] = value;

  return LOOP_STACK;
}

int *pop_loop_stack(int *LOOP_STACK, int *loopStackLen)
{
  (*loopStackLen)--;
  LOOP_STACK = realloc(LOOP_STACK, (*loopStackLen) * sizeof(int));

  return LOOP_STACK;
}

int main()
{
  char *buffer = readFile();

  int *MEMORY = malloc(0);
  int len = 0;

  int printHead = 0;
  int readHead = 0;

  int *LOOP_STACK = malloc(0);
  int loopStackLen = 0;

  char readValue;
  while (buffer[readHead] != '\0')
  {
    readValue = buffer[readHead];

    if (readValue == '>')
    {
      printHead++;

      if (printHead > len)
      {
        len = printHead;
        MEMORY = realloc(MEMORY, (len + 1) * sizeof(int));
      }
    }

    else if (readValue == '<')
    {
      printHead--;
    }

    else if (readValue == '+')
    {
      MEMORY[printHead]++;
    }

    else if (readValue == '-')
    {
      MEMORY[printHead]--;
    }

    else if (readValue == '.')
    {
      putchar(MEMORY[printHead]);
    }

    else if (readValue == ',')
    {
      MEMORY[printHead] = getchar();
    }

    else if (readValue == '[')
    {
      LOOP_STACK = push_loop_stack(LOOP_STACK, &loopStackLen, readHead);

      if (MEMORY[printHead] == 0)
      {
        LOOP_STACK = pop_loop_stack(LOOP_STACK, &loopStackLen);

        do
        {
          readHead++;
        } while (buffer[readHead] != ']');
      }
    }

    else if (readValue == ']')
    {
      readHead = LOOP_STACK[loopStackLen - 1] - 1;
      LOOP_STACK = pop_loop_stack(LOOP_STACK, &loopStackLen);
    }

    readHead++;
  }

  return 0;
}
