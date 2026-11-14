# Exercícios

Tipo: Página

**1)** Implemente uma função que insere um nodo (números inteiros) em uma lista duplamente encadeada:

  * se o número for par, insere no início;
  * se o número for ímpar, insere no fim;
  * se o número for negativo, inserem depois dos pares (antes do primeiro ímpar).

**2)** Implementar as operações de **inserção** e **remoção** (e exibição) de nodos em uma **lista duplamente encadeada** :   

Considere uma lista de estudantes na qual cada registro (cada nodo) vai ter a nota (entre 0.0 e 10.0) e o nome do aluno. Implemente a lista com  _**header** _(cabeçalho), o qual deve ter o total de nodos (alunos) da lista, a soma das notas, e o endereço do início da lista. A soma das notas e o total de alunos permitem calcular a média dos estudantes.

Implemente as seguintes operações:

  * Insira os registros em uma lista duplamente encadeada, os quais são ordenados pela nota, sendo que pode haver notas repetidas. Atualize a soma das notas e quantidade de alunos no  _header_ a cada inserção.  

  * Remova os nodos por um ou mais critérios, sendo um deles a nota (pode ser também pelo nome). Lembre-se que se a remoção for pela nota, todos os alunos que tem a mesma nota devem ser removidos. Ou defina uma operação de remoção que considera, além da nota, o nome do aluno. Atualize a a soma das notas e quantidade de alunos no  _header_ a cada remoção.  

  * Faça buscas na lista: alunos com notas maior (ou menor) que a média

Sugestão: modificar a implementação da lista de encadeamento simples, fazendo os ajustes necessários.  

**3)** (exercício também como TDE) Uma **palíndrome** é um texto (ou palavra) que pode ser lido da esquerda para a direita ou da direita para a esquerda, produzindo o mesmo resultado (ou o mesmo texto). Por exemplo: "arara", "amor e roma", "ele", "1234554321".   

a) Considere que um texto está armazenado em uma lista duplamente encadeada, na qual cada nodo contém um caractere. Implemente uma função (em C, C#, C++, Java, Python) que verifique se o texto armazenado é uma palíndrome ou não, retornando 0 se o texto não for palíndrome e 1 se for palíndrome.

b) Defina um  _header_ (cabeçalho) para a lista que armazena a quantidade de caracteres do texto (e opcionalmente) a quantidade de palavras do texto. Considere outras operações que poderiam ser executadas sobre o texto para definir o conteúdo do  _header_.
