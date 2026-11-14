# Exercícios

Tipo: Página

1) Apresente (descreva) 2 situações de implementação nas quais são utilizadas **pilhas**.

2) Apresente (descreva) 2 situações de implementação nas quais são utilizadas **filas**.

**3) Resolva a questão do ENADE 2011:**

No desenvolvimento de um  _software_ que analisa bases de DNA, representadas pelas letras A, C, G, T, utilizou-se as estruturas de dados: pilha e fi la. Considere que, se uma sequência representa uma pilha, o topo é o elemento mais à esquerda; e se uma sequência representa uma fila, a sua frente é o elemento mais à esquerda.

Analise o seguinte cenário: "a sequência inicial ficou armazenada na primeira estrutura de dados na seguinte ordem: (A,G,T,C,A,G,T,T). Cada elemento foi retirado da primeira estrutura de dados e inserido na segunda estrutura de dados, e a sequência fi cou armazenada na seguinte ordem: (T,T,G,A,C,T,G,A). Finalmente, cada elemento foi retirado da segunda estrutura de dados e inserido na terceira estrutura de dados e a sequência ficou armazenada na seguinte ordem: (T,T,G,A,C,T,G,A)".  

Qual a única sequência de estruturas de dados apresentadas a seguir pode ter sido usada no cenário descrito acima?

a) Fila - Pilha - Fila.

b) Fila - Fila - Pilha.

c) Fila - Pilha - Pilha.

d) Pilha - Fila - Pilha.

e) Pilha - Pilha - Pilha.

**4)** Escreva o procedimento esvazia_pilha(). Considere que as operações de manipulação da pilha (empilha(item), desempilha, e pilha_vazia()) já existem e podem ser utilizados para escrever o esvazia_pilha().

**5)** Sendo F uma fila circular de 4 elementos, qual a situação final da fila após a seguinte sequência de operações de inserção (I,valor) e remoção (R): I,3 - I,5 - I,7 - R - I,1 - R - I,4 - I,3 - R - I,1 - R ?

**6)** Qual a situação final das deques a seguir, após a execução das seguintes sequências de operações (desenhe):  

a) deque de entrada restrita (entrada só pelo lado A): E-> A-----B  
I(5), I(1), I(4), R(A), I(6), I(8), R(B), I(3), R(A), R(B)

b) deque de saída restrita (saída só pelo lado B): A-----B ->S  
I(5,A), I(1,A), I(4,A), R, I(3,B), I(5,B), R, I(1,B), R, I(8,B), R

c) deque geral (entrada e saída pelos dois lados): A-----B  
I(5,A), I(3,B), I(4,A), I(5,B), R(A), I(1,B), R(B), R(A), I(8,B), R(B)

**Exercícios de implementação:**

  1. Desenvolva uma programa que leia um texto, e escreva as palavras do texto em ordem invertida. Use uma pilha, e considere que os separadores de palavras são espaços em branco (se quiser considere também outros separadores, como : , ; . ! etc)
  2. Como você implementaria duas pilhas sobre o mesmo vetor? O vetor tem tamanho fixo (defina o tamanho), mas as pilhas não, o tamanho de cada uma pode variar tendo como restrição o tamanho do vetor e o espaço ocupado pela outra pilha. Escreva o procedimento/método para empilhar e desempilhar, que possa ser utilizado para as duas pilhas.
  3. Escreva a implementação de operações de inserção e remoção em uma deque de entrada restrita, implementada sobre uma lista de encadeamento (simples ou duplo? Qual a melhor opção?).
  4. Implementar o interpretador de expressões aritméticas, com uso de duas pilhas (pilha de operandos e pilha de operadores**)**. A expressão aritmética pode ser lida como um string, os números da expressão podem ter apenas um dígito (ou não, talvez dois ou mais, decida como for mais adequado). Pode incluir a divisão entre os operadores, mas não esqueça de testar o divisor para que não seja igual a zero.
  5. Uma operadora possui 5 impressoras, cada impressora mantém uma fila de impressão.  
Para enviar um trabalho para impressão, é preciso escolher a impressora através de seu identificador (pode ser sequencial, do 0 ao 4), utilizando a operação  _**imprime( )**_.  
Implemente o controle da operadora através da operação  _**imprime(nroimpressora, trabalho)**_. A operação  _**imprime**_ corresponde ao  _**enfileira**_ em uma impressora específica. Defina como seria o registro de cada impressão (nodo da lista).
  6. Uma operadora possui uma impressora, compartilhada por seus usuários. Essa impressora tem uma fila de impressão, para a qual os usuários enviam suas solicitações de impressão. Os usuários são classificados em 3 categorias: prioridade máxima (0), prioridade normal (1) e prioridade baixa (2). Para solicitar uma impressão, é utilizada a operação  _**imprime(prioridade, trabalho)**_ , e a impressão ocorre através da operação  _**impressao( ).**_ A cada 2 impressões de prioridade máxima, a impressora imprime uma solicitação de prioridade normal. A cada 3 impressões de prioridade normal, a impressora imprime uma impressão de prioridade baixa. Implemente o controle da impressora.
