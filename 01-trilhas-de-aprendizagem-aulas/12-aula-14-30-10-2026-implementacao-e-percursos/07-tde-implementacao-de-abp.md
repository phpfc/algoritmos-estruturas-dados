# TDE: Implementação de ABP

Tipo: Tarefa com entrega · Prazo: 07/11/2026 23:59

6) Considere uma ABP (árvore binária de pesquisa) que armazena números inteiros (implemente a operação de inserção). Implementar uma operação que escreva os números ímpares em ordem decrescente.

## Minhas entregas

### Tentativa 1

Enviada em 07/11/2026 14:27

A resposta foi enviada como texto no AVA. O código está salvo em [tde-implementacao-de-abp.c](arquivos/minhas-entregas/tde-implementacao-de-abp.c):

```c
#include <stdio.h>

#include <stdlib.h>

typedef struct noA {

 int info;

 struct noA *esq;

 struct noA *dir;

} TNoA;

TNoA *criaNo(int valor) {

 TNoA *novo;

 novo = (TNoA *) malloc(sizeof(TNoA));

 novo->info = valor;

 novo->esq = NULL;

 novo->dir = NULL;

 return novo;

}

TNoA *insere(TNoA *a, int valor) {

 if (a == NULL)

 return criaNo(valor);

 if (valor < a->info)

 a->esq = insere(a->esq, valor);

 else if (valor > a->info)

 a->dir = insere(a->dir, valor);

 return a;

}

void imparesDecrescente(TNoA *a) {

 if (a != NULL) {

 imparesDecrescente(a->dir);

 if (a->info % 2 != 0)

 printf("%d\n", a->info);

 imparesDecrescente(a->esq);

 }

}

void libera(TNoA *a) {

 if (a != NULL) {

 libera(a->esq);

 libera(a->dir);

 free(a);

 }

}

int main(void) {

 TNoA *raiz = NULL;

 int valores[] = {50, 30, 70, 21, 45, 65, 83, 15, 27, 77, 90, -3};

 int n = sizeof(valores) / sizeof(valores[0]);

 int i;

 for (i = 0; i < n; i++)

 raiz = insere(raiz, valores[i]);

 printf("Impares em ordem decrescente:\n");

 imparesDecrescente(raiz);

 libera(raiz);

 return 0;

}
```
