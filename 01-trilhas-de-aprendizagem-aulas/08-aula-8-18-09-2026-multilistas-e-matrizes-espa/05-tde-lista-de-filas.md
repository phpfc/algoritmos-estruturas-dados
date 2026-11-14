# TDE - lista de filas

Tipo: Tarefa com entrega · Prazo: 25/09/2026 23:59

**Esse TDE é a primeira parte do trabalho de implementação que será finalizado (e apresentado) na aula do dia 25/09.**

Considere um conjunto de 3 impressoras (**vetor ou lista encadeada de 3 elementos**). **Cada fila de impressão é uma lista encadeada**.

Implemente as filas de impressão de cada uma das impressoras. Cada fila de impressão tem, além das informações de inicio e fim da fila, a quantidade de impressões daquela fila.

Operações:

\- enviar documento para impressão (dizer qual a impressora e a identificação do documento): enfileira o documento na impressora (atualiza quantidade de impressões)

\- imprimir (dizer qual impressora): desenfileira documento (atualiza quantidade de impressões)

\- cancelar impressão (dizer qual impressora e qual documento): retira documento da fila daquela impressora (atualiza quantidade de impressões)

**Cada impressão é um registro com duas informações** : um código (inteiro) e um nome de arquivo a ser impresso (string).
