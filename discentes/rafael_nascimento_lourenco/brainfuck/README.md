Para rodar o código bastar abrir a linha de comando e rodar:

```sh
make run 
```

Este comando irá compilar o executavél e executar um arquivo teste com retorno "Ola, mundo!"

Para executar com arquivo txt próprio basta rodar:

```sh
make build
cd src
./main.out <path do arquivo txt>
```

Exemplo de teste
```sh
./main.out ./nested_loop.txt
``` 

O arquivo txt será o código da linguagem [brainfuck](https://pt.wikipedia.org/wiki/Brainfuck) a ser interpretado. Algumas observações:
- Existe um limite estabelecido de loops aninhados, o padrão definido foi 10
- Se tiver ']' sem antes abrir com '[', será ignorado
- Se tiver '[' e não fechar o programa irá resultar erro
- O indice da fita começa no meio simulando uma MT de fita infinita, tem tamanho 30000

Essas regras e erros (tirando o de loops aninhados) foram baseados com testes do replit;