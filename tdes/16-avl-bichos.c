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

/* as rotações duplas são feitas com duas rotações simples */
TNoA *balanceia(TNoA *a) {
    atualizaAltura(a);
    int fb = fator(a);
    if (fb > 1) {
        if (fator(a->esq) < 0)
            a->esq = rotacaoEsquerda(a->esq);
        return rotacaoDireita(a);
    }
    if (fb < -1) {
        if (fator(a->dir) > 0)
            a->dir = rotacaoDireita(a->dir);
        return rotacaoEsquerda(a);
    }
    return a;
}

TNoA *insere(TNoA *a, const char *nome, int *inseriu) {
    if (a == NULL) {
        *inseriu = 1;
        return criaNo(nome);
    }
    int cmp = strcmp(nome, a->nome);
    if (cmp < 0)
        a->esq = insere(a->esq, nome, inseriu);
    else if (cmp > 0)
        a->dir = insere(a->dir, nome, inseriu);
    else {
        *inseriu = 0;
        return a;
    }
    return balanceia(a);
}

void exibeEmOrdem(TNoA *a) {
    if (a != NULL) {
        exibeEmOrdem(a->esq);
        printf("%s\n", a->nome);
        exibeEmOrdem(a->dir);
    }
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
    TNoA *raiz = NULL;
    /* em ordem alfabética, para forçar as rotações */
    const char *bichos[] = {"anta", "baleia", "capivara", "elefante", "foca", "gato",
                            "hiena", "jacare", "leao", "macaco", "onca", "pato",
                            "quati", "rato", "sapo", "tatu", "urso", "zebra",
                            "coelho", "cavalo", "gato"};
    int n = sizeof(bichos) / sizeof(bichos[0]);
    int inseriu;

    for (int i = 0; i < n; i++) {
        raiz = insere(raiz, bichos[i], &inseriu);
        if (!inseriu)
            printf("%s ja esta na arvore\n", bichos[i]);
    }

    printf("Altura da arvore: %d\n\n", altura(raiz));
    exibeArvore(raiz, 0);
    printf("\nEm ordem:\n");
    exibeEmOrdem(raiz);

    libera(raiz);
    return 0;
}
