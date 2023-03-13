#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define MAX_VECT 30000

void clear(int *vect){
  for(int i = 0; i<MAX_VECT; i++){
    vect[i] = 0;
  }
}

void bf(char symbol, int *msg, int *pos, int *iPos, int *input, int *loop, int *i){
  switch (symbol){
    case '+':
      msg[*pos]++;
    break;
    case '-':
      msg[*pos]--;
    break;
    case '>':
      (*pos)++;
    break;
    case '<':
      (*pos)--;
    break;
    case '.':
      printf("%c",msg[*pos]);
    break;
    case ',':
      msg[*pos] = input[*iPos];
      (*iPos)++;
    break;
    case '[':
      *loop = *i;
    break;
    case ']':
      if(msg[*pos] != 0){
        *i = *loop;
      }
    break;
  }
}

int main(int argc, const char * argv[])
{
  char c;
  FILE *fp;
  int line =0;
  int instances = 0;
  int inst= 1;
  int input[MAX_SIZE];
  int msg[MAX_VECT]={0};
  int pos = 0;
  int iPos = 0;
  int loop;
  int i = 0;
  int j = 0;
  char instance[MAX_SIZE];
  char vector[MAX_SIZE];
  
  
  if (argc != 2 || (fp = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "Usage: %s filename\n", argv[0]);
      return -1;
  }else{
    while ((c = getc(fp)) != EOF) {
      vector[i] = c;
      i++;
    }
    i=0;
    while(vector[i] != '\0'){
      c = vector[i];
      if(c == '\n'){
        if(line == 0){
          sscanf(instance, "%d", &instances);
          printf("Instancia %d\n",inst);
        }else if(line == 5){
          clear(input);
          clear(msg);
          line = 2;
          instances --;
          inst++;
          iPos = 0;
          pos = 0;
          loop = 0;
          printf("\n\n");
          printf("Instancia %d\n",inst);
        }
        line++;
        j = 0;
      }else if (line == 2){
        input[j] = c;
        j++;
      } else if (line == 0){
        instance[j] = c;
        j++;
      }else if(line == 3){
        bf(c, msg, &pos, &iPos, input, &loop, &i);
      }
      i++;
    }
  }
  fclose(fp);
  return 0;
}