Brainfuck Interpreter
Este é um interpretador de Brainfuck escrito em C. Ele lê um arquivo de texto contendo um programa Brainfuck e o interpreta, produzindo a saída na saída padrão.

Como usar
Certifique-se de ter o gcc instalado em seu sistema. Para compilar o interpretador, execute o seguinte comando no terminal:

bash
make
Isso irá compilar o código e gerar um executável chamado bf.

Para rodar o interpretador, crie um arquivo de texto contendo um programa Brainfuck (por exemplo, bf.txt) e execute o seguinte comando no terminal:

bash
./bf bf.txt
Isso irá interpretar o programa e produzir a saída na saída padrão.

Como limpar
Para remover os arquivos gerados pela compilação, execute o seguinte comando no terminal:

bash
make clean
Dependências
O interpretador não tem dependências externas além do gcc, que é usado para compilar o código-fonte.

Contribuição
Este interpretador foi escrito apenas como um exercício de programação e não é destinado a uso em produção. No entanto, se você quiser contribuir de alguma forma, sinta-se à vontade para abrir uma issue ou enviar uma pull request.
