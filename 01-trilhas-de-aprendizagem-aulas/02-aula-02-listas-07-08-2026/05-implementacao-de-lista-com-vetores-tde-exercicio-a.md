# Implementação de lista com vetores (TDE - exercício avaliativo)

Tipo: Tarefa com entrega · Prazo: 14/08/2026 23:59

Você vai receber cartas de um baralho, e deve pegar uma a uma e ir colocando lado a lado (ou na sua mão), em ordem de valores numéricos, do menor para o maior (a carta "ás" (A ou 1) é o menor valor. Os naipes vão ser considerados como texto: "ouros", "copas", "paus", "espadas".

TAD jogo{

Dados: cartas

Operações:

recebe_carta(E: carta);

ver_lista_cartas(S: lista de cartas);

remover_carta(E: carta; S: lista de cartas);

trincas(S: listas de trincas);

}

**Tarefa:**

Considere a implementação das cartas recebidas em um jogo como um vetor (máximo de 20 posições). Fazer um menu de operações, para o usuário selecionar:

\- implementar a operação de **recebe_carta(...)** , na qual é realizada a **inserção de um valor de forma ordenada** no vetor**(não utilize um método de ordenação, cada inserção deve ser feita na sua posição considerando a ordem)**. A ordenação deve ser em ordem **crescente **de valores, ou seja, a cada inserção de uma nova carta, ela deve ser colocada na sua posição correta na lista. Pode haver valores repetidos na lista, cada baralho tem 4 cartas de mesmo valor (cada valor pode ser repetido no máximo 4 vezes, uma vez para cada naipe). O valor das cartas deve estar entre 1 e 13.

Deve ser controlado o número de cartas inserido, para não ultrapassar 20 (se ultrapassar, mostrar mensagem de erro). **  
**

**- **implementar a operação **ver_lista_cartas(...)** , que exiba a lista de cartas armazenada.**  
**

**- **implementar a operação **remover_carta(...)** , que remove a carta do valor informado. 

**-** implementar a operação **exibe_trincas(...)** , que exibe as trincas (3 cartas de mesmo valor) da lista de cartas armazenada.

**Fazer upload da sua implementação. Pode ser feito em duplas, nesse caso colocar o nome dos dois participantes, e cada um faz upload do código.**
