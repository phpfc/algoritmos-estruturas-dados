#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct noA {
    char nome[MAX_NOME];
    int altura;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *criaNo(const char *nome) {
    TNoA *novo = malloc(sizeof(TNoA));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strncpy(novo->nome, nome, MAX_NOME - 1);
    novo->nome[MAX_NOME - 1] = '\0';
    novo->altura = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int altura(TNoA *a) {
    if (a == NULL)
        return 0;
    return a->altura;
}

void atualizaAltura(TNoA *a) {
    int he = altura(a->esq);
    int hd = altura(a->dir);
    a->altura = (he > hd ? he : hd) + 1;
}

/* fator de balanceamento: altura da esquerda menos altura da direita */
int fator(TNoA *a) {
    if (a == NULL)
        return 0;
    return altura(a->esq) - altura(a->dir);
}

TNoA *rotacaoDireita(TNoA *a) {
    TNoA *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

TNoA *rotacaoEsquerda(TNoA *a) {
    TNoA *b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

/* escreve a árvore deitada: a raiz fica na esquerda e a subárvore direita em cima */
void exibeArvore(TNoA *a, int nivel) {
    if (a == NULL)
        return;
    exibeArvore(a->dir, nivel + 1);
    for (int i = 0; i < nivel; i++)
        printf("        ");
    printf("%s (fb %d)\n", a->nome, fator(a));
    exibeArvore(a->esq, nivel + 1);
}

void libera(TNoA *a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int main(void) {
    /* árvore degenerada para a esquerda: zebra -> gato -> anta */
    TNoA *raiz = criaNo("zebra");
    raiz->esq = criaNo("gato");
    raiz->esq->esq = criaNo("anta");
    atualizaAltura(raiz->esq);
    atualizaAltura(raiz);

    printf("Antes da rotacao a direita:\n");
    exibeArvore(raiz, 0);

    raiz = rotacaoDireita(raiz);
    printf("\nDepois da rotacao a direita:\n");
    exibeArvore(raiz, 0);

    libera(raiz);
    return 0;
}
