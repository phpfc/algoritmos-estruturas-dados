# Trabalho de listas: lista de impressoras

Tipo: Tarefa com entrega · Prazo: 25/09/2026 23:59

**Lista de impressoras**

Considere um conjunto de 3 impressoras (**vetor ou lista encadeada de 3 elementos**).  **Cada fila de impressão é uma lista encadeada**.

Implemente as filas de impressão de cada uma das impressoras. Cada fila de impressão tem, além das informações de inicio e fim da fila, a quantidade de impressões daquela fila.

**Cada impressão é um registro com duas informações** : um código (inteiro) e um nome de arquivo a ser impresso (string).

**Operações:**

1) **enviar documento para impressão** (dizer qual a impressora e a identificação do documento): enfileira o documento na impressora (atualiza quantidade de impressões)

2) **imprimir**(dizer qual impressora): desenfileira documento (atualiza quantidade de impressões)

3) **cancelar impressão** (dizer qual impressora e qual documento): retira documento da fila daquela impressora (atualiza quantidade de impressões)

Operações a serem implementadas no dia 25/09:

4) **exibe relatório de uma impressora** (dizer qual é a impressora): informa quantas impressões tem na fila, e quantas impressões aquela impressora realizou.

5) **desliga impressora** (dizer qual é a impressora): se a impressora tiver documentos na fila, pergunta para qual outra impressora (impressora destino) deve transferi-los. Nessa transferência, intercala os documentos da fila destino com os da fila da impressora desligada: primeiro um documento da impressora destino, depois um documento da impressora desligada, e assim por diante até terminarem os documentos da impressora desligada.

6) **prioriza impressão de um documento** (dizer qual é a impressora e qual é o documento): exibe a lista de documentos de uma impressora, e permite escolher um desses documentos para ser colocado na primeira posição da fila de impressão dessa impressora.

7) **exibe a fila de impressão de uma impressora** (dizer qual é a impressora): exibe os documentos de uma fila de impressão

8) **insira uma nova impressora na fila de impressão**

9) defina uma ou mais operações extras.
