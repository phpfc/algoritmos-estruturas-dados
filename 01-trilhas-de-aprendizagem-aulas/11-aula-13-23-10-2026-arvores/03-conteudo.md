# Conteúdo

Tipo: Página

[Arquivo: Estruturas de dados_ árvores.pdf](arquivos/estruturas-de-dados-arvores.pdf)

**Algumas explicações sobre árvores e seu armazenamento:**

**

[Arquivo: Árvores](arquivos/arvoresgeral.pdf)

**

Para **percorrer** uma árvore, é preciso usar um **método que consiga passar por todos os elementos da árvore, sem esquecer nenhum e sem repetir nodos.** Para tanto, usa-se os **percursos**(ou **caminhamentos** , ou **enumerações**), métodos que percorrem os elementos da árvore. Há duas grandes formas principais de percorrer uma árvore:

  * em largura (nível a nível)
  * ou em profundidade (para cada nodo, segue-se os caminhos em direção às folhas)

**Percursos em profundidade** são geralmente implementados de forma recursiva, e para cada nodo realizam as seguintes operações:

  1. "visitar" o nodo: "visitar" significa fazer algo com o conteúdo daquele nodo, como por exemplo escrever, comparar, modificar ou simplesmente ignorar
  2. ir para sub-árvore da esquerda
  3. ir para subárvore da direita

Percurso pré-fixado (ou em pré-ordem) para árvore binária:

void preordem(TNoA* a){  
if (a!= NULL){  
printf("%c\n",a->info);  
preordem(a->esq);  
preordem(a->dir);  
}  
}
