#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct No {
    char nome[MAX_NOME];
    struct No *prox;
} No;

No *insereOrdenado(No *lista, const char *nome) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strncpy(novo->nome, nome, MAX_NOME - 1);
    novo->nome[MAX_NOME - 1] = '\0';

    No *ant = NULL;
    No *atual = lista;
    while (atual != NULL && strcmp(atual->nome, nome) <= 0) {
        ant = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    if (ant == NULL)
        return novo;
    ant->prox = novo;
    return lista;
}

No *removePorValor(No *lista, const char *nome, int *removidos) {
    No *ant = NULL;
    No *atual = lista;
    *removidos = 0;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            No *removido = atual;
            atual = atual->prox;
            if (ant == NULL)
                lista = atual;
            else
                ant->prox = atual;
            free(removido);
            (*removidos)++;
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
    return lista;
}

No *removePorPosicao(No *lista, int posicao, int *removeu) {
    No *ant = NULL;
    No *atual = lista;
    *removeu = 0;
    if (posicao < 1)
        return lista;
    for (int i = 1; i < posicao && atual != NULL; i++) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
        return lista;
    if (ant == NULL)
        lista = atual->prox;
    else
        ant->prox = atual->prox;
    free(atual);
    *removeu = 1;
    return lista;
}

void exibe(No *lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }
    int posicao = 1;
    for (No *p = lista; p != NULL; p = p->prox)
        printf("%d: %s\n", posicao++, p->nome);
}

void libera(No *lista) {
    while (lista != NULL) {
        No *prox = lista->prox;
        free(lista);
        lista = prox;
    }
}

int main(void) {
    No *lista = NULL;
    const char *nomes[] = {"marcos", "ana", "carla", "bruno", "ana", "zeca", "daiane", "ana", "luis"};
    int n = sizeof(nomes) / sizeof(nomes[0]);

    for (int i = 0; i < n; i++)
        lista = insereOrdenado(lista, nomes[i]);
    printf("Lista apos as insercoes:\n");
    exibe(lista);

    int removidos;
    lista = removePorValor(lista, "ana", &removidos);
    printf("\nRemocao por valor de \"ana\" (%d nodos removidos):\n", removidos);
    exibe(lista);

    int removeu;
    lista = removePorPosicao(lista, 1, &removeu);
    printf("\nRemocao da posicao 1:\n");
    exibe(lista);

    lista = removePorPosicao(lista, 3, &removeu);
    printf("\nRemocao da posicao 3:\n");
    exibe(lista);

    lista = removePorPosicao(lista, 10, &removeu);
    if (!removeu)
        printf("\nPosicao 10 nao existe na lista\n");

    libera(lista);
    return 0;
}
