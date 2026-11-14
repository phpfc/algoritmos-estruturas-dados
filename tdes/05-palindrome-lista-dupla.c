#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char letra;
    struct No *ant;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Lista;

void inicializa(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void insereFim(Lista *l, char letra) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    novo->letra = letra;
    novo->prox = NULL;
    novo->ant = l->fim;
    if (l->fim == NULL)
        l->inicio = novo;
    else
        l->fim->prox = novo;
    l->fim = novo;
}

void carregaTexto(Lista *l, const char *texto) {
    for (int i = 0; texto[i] != '\0'; i++)
        insereFim(l, texto[i]);
}

/* Os espaços são ignorados, para que "amor e roma" seja palíndrome. */
int palindrome(Lista *l) {
    No *esq = l->inicio;
    No *dir = l->fim;

    while (esq != NULL && dir != NULL && esq != dir && esq->ant != dir) {
        if (esq->letra == ' ') {
            esq = esq->prox;
        } else if (dir->letra == ' ') {
            dir = dir->ant;
        } else {
            if (esq->letra != dir->letra)
                return 0;
            esq = esq->prox;
            dir = dir->ant;
        }
    }
    return 1;
}

void libera(Lista *l) {
    No *p = l->inicio;
    while (p != NULL) {
        No *prox = p->prox;
        free(p);
        p = prox;
    }
    inicializa(l);
}

int main(void) {
    const char *textos[] = {"arara", "amor e roma", "ele", "1234554321", "arvore", "ab", "a", ""};
    int n = sizeof(textos) / sizeof(textos[0]);

    for (int i = 0; i < n; i++) {
        Lista l;
        inicializa(&l);
        carregaTexto(&l, textos[i]);
        printf("\"%s\": %d\n", textos[i], palindrome(&l));
        libera(&l);
    }
    return 0;
}
