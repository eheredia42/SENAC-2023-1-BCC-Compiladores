Interpretador Brainfuck em C

Este é um interpretador Brainfuck simples em C que lê um arquivo de código-fonte Brainfuck e executa as instruções contidas nele. O programa assume que o arquivo de entrada é fornecido como um argumento de linha de comando e que o nome do arquivo é "codigo.txt".
Compilação e execução

Para compilar o código, execute o seguinte comando na linha de comando:

gcc -o brainfuck main.c

Isso compilará o código-fonte em um arquivo executável chamado "brainfuck".

Para executar o brainfuck no arquivo "codigo.txt", execute o seguinte comando na linha de comando:

./brainfuck codigo.txt

Funcionamento

O interpretador lê cada caractere do arquivo de entrada e executa a instrução correspondente em uma máquina virtual Brainfuck. As instruções suportadas são:

    > - incrementa o índice da memória
    < - decrementa o índice da memória
    + - incrementa o valor da célula atual da memória
    - - decrementa o valor da célula atual da memória
    . - imprime o valor da célula atual da memória como um caractere ASCII
    , - lê um caractere do input do usuário e armazena na célula atual da memória
    [ - inicia um loop
    ] - termina um loop

O interpretador usa um array de caracteres de 30.000 células para armazenar a memória do Brainfuck. Além disso, o programa suporta loops aninhados até uma profundidade máxima de 100. O programa ignora qualquer caractere que não seja uma instrução Brainfuck válida.