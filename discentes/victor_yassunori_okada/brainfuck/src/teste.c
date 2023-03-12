#include <stdio.h>
#include <stdlib.h>
#include <search.h> //biblioteca para busca de strings em biblioteca
#include <string.h>

//array de caracteres ascii
static char *characteres[] = { "\n"," ","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/","0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?","@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","^","_","'","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","DEL" };

//array de caracteres brainfuck concatenado(memoria + caractere)
static char *concatenado[] = { "+.","+++++.","++++++.","+++++++.","++++++++.","++++----.","++++---.","++++--.","++++-.","++++.","+++++.","++++++.","+++++++.","++++++++.","+++++++++.","+++++----.","+++++---.","+++++--.","+++++-.","+++++.","++++++.","+++++++.","++++++++.","+++++++++.","++++++++++.","++++++----.","++++++---.","++++++--.","++++++-.","++++++.","+++++++.","++++++++.","+++++++++.","++++++++++.","+++++++++++.","+++++++----.","+++++++---.","+++++++--.","+++++++-.","+++++++.","++++++++.","+++++++++.","++++++++++.","+++++++++++.","++++++++++++.","++++++++----.","++++++++---.","++++++++--.","++++++++-.","++++++++.","+++++++++.","++++++++++.","+++++++++++.","++++++++++++.","+++++++++++++.","+++++++++----.","+++++++++---.","+++++++++--.","+++++++++-.","+++++++++.","++++++++++.","+++++++++++.","++++++++++++.","+++++++++++++.","++++++++++++++.","++++++++++----.","++++++++++---.","++++++++++--.","++++++++++-.","++++++++++.","+++++++++++.","++++++++++++.","+++++++++++++.","++++++++++++++.","+++++++++++++++.","+++++++++++----.","+++++++++++---.","+++++++++++--.","+++++++++++-.","+++++++++++.","++++++++++++.","+++++++++++++.","++++++++++++++.","+++++++++++++++.","++++++++++++++++.","++++++++++++----.","++++++++++++---.","++++++++++++--.","++++++++++++-.","++++++++++++.","+++++++++++++.","++++++++++++++.","+++++++++++++++.","++++++++++++++++.","+++++++++++++++++.","+++++++++++++----.","+++++++++++++---." };

//funcao responsavel pela busca de codigo brainfuck no array de caracteres ascii
void buscaString(const char *palavra) 
{
  
   ENTRY e;
   ENTRY *ep;

   const size_t capacity = sizeof concatenado / sizeof concatenado[0];
   hcreate(capacity);

   for (size_t i = 0; i < capacity; i++) 
   {
       e.key = concatenado[i];
       e.data = (void *) characteres[i];

       ep = hsearch(e, ENTER);

       if (ep == NULL) 
       {
           fprintf(stderr, "entry failed\n");
           exit(EXIT_FAILURE);
       }
   }

    e.key = palavra;
    ep = hsearch(e, FIND);
    ep ? printf("%s", (char*)ep->data) : //printa se achar caractere, caso contrario nao imprime nada
      printf("%s", "");

}

//funcao responsavel pela concatenacao de string de memória brainfuck com string de caracteres brainfuck. Ex: ++++++++ (80) concatenado com -. (letra O)
void concatenar(const char *string, const char *string2) 
{
  
  char *palavra;
  palavra = (char *) malloc(sizeof(char));
  
  while (*string) 
  { 
    
    size_t len, len2;
    const char *endptr = strstr(string, ">"); // remove da string o caractere <
    const char *endptr2 = strstr(string2, ">"); // remove da string o caractere <
    
    if (endptr && endptr2) 
    {
      
      len = (size_t) (endptr - string);  // pega tamanho de string do ponto final até o inicial
      len2 = (size_t) (endptr2 - string2); // pega tamanho de string do ponto final até o inicial
      endptr++;
      endptr2++;
      
    } 
    else 
    {
      
      len = strlen(string);
      len2 = strlen(string2);
      endptr = string + len;
      endptr2 = string2 + len2;
      
    }
    
    char *result = malloc(len + 1); // aloca tamanho de string em variavel
    char *result2 = malloc(len2 + 1); // aloca tamanho de string em variavel
    
    if (result && result2) 
    {
      
      memcpy(result, string, len);
      result[len] = '\0';
      
      memcpy(result2, string2, len2);
      result2[len2] = '\0';

      strcat(result,result2); // concatena strings em uma unica string(reault)
    
      buscaString(result); // busca palavra na funcao buscaString pra retornar caracteres ascii
      
      free(result); 
      free(result2);
      
    }
    
    string = endptr;
    string2 = endptr2;
  }
}

void init()
{

  char *resultado;
  size_t len;
  resultado = (char *) malloc(sizeof(char));
  
  char *entrada = "++++++++++[>++++++++>+++++++++++>++++++++++>++++>+++>++++++++>++++++++++++>+++++++++++>++++++++++>+++++++++++>+++>+<<<<<<<<<<<<-]>-.>--.>---.>++++.>++.>---.>---.>.>.>+.>+++.>."; //hello world
  char *arg = strchr(entrada, '['); // pega string a partir do caractere [
  char *arg2 = strchr(entrada, ']'); // pega string a partir do caractere ]
  
  if (arg != NULL)
  {
    
    arg++; 
    arg2++;
    
    const char *endptr = strstr(arg, "<<<<<<<<<<<<-]"); // remove caracteres invalidos para busca em funcao buscaString
    
    if (endptr) 
    {
      
      len = (size_t) (endptr - arg); // pega tamanho da string do fim até o inicio
      endptr++;
      
    } 
    else 
    {
      
      len = strlen(arg); // retorna tamanho da string 
      endptr = arg + len; // retorna soma de string com tamanho
      
    }
    
    char *result = malloc(len + 1);
    
    if (result) 
    {
      
      memcpy(result, arg, len); // copia caracteres de arg para result
      result[len] = '\0';

      concatenar(result, arg2); // copia caracteres de arg2 para result
      free(result);
      
    }
    arg = endptr;

  }
}


void brainfuck(void) 
{
  
   init(); // funcao que inicializa programa
  
}

/* 

REFERENCIAS :

https://pt.wikipedia.org/wiki/Brainfuck#:~:text=brainfuck%2C%20tamb%C3%A9m%20conhecido%20como%20brainf,%C3%A9%20%C3%BAtil%20para%20uso%20pr%C3%A1tico.
https://www.rapidtables.com/code/text/ascii-table.html
https://www.javatpoint.com/ascii-table-in-c#:~:text=The%20standard%20ASCII%20code%20ranges,punctuation%20marks%2C%20and%20control%20characters.
https://www.delftstack.com/howto/c/dictionary-in-c/
https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
https://stackoverflow.com/questions/45832469/get-the-beginning-of-a-string-until-a-given-char
https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
https://www.geeksforgeeks.org/strstr-in-ccpp/
https://stackoverflow.com/questions/52281456/how-to-loop-a-string-using-strstr-to-find-substrings-in-c
https://www.tutorialspoint.com/c_standard_library/c_function_memcpy.htm
https://stackoverflow.com/questions/18219722/how-to-select-read-copy-values-after-specific-character-in-a-string
https://onestepcode.com/brainfuck-compiler-c/

*/
