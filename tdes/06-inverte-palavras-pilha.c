#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 1000
#define SEPARADORES " \t\n:,;.!?"

typedef struct No {
    char *palavra;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = NULL;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

void empilha(Pilha *p, const char *palavra) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    novo->palavra = malloc(strlen(palavra) + 1);
    if (novo->palavra == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strcpy(novo->palavra, palavra);
    novo->prox = p->topo;
    p->topo = novo;
}

char *desempilha(Pilha *p) {
    if (vazia(p))
        return NULL;
    No *removido = p->topo;
    char *palavra = removido->palavra;
    p->topo = removido->prox;
    free(removido);
    return palavra;
}

int main(void) {
    char texto[MAX_TEXTO];
    Pilha pilha;
    inicializa(&pilha);

    printf("Digite um texto: ");
    if (fgets(texto, MAX_TEXTO, stdin) == NULL)
        return 0;

    char *palavra = strtok(texto, SEPARADORES);
    while (palavra != NULL) {
        empilha(&pilha, palavra);
        palavra = strtok(NULL, SEPARADORES);
    }

    printf("Palavras em ordem invertida:");
    while (!vazia(&pilha)) {
        palavra = desempilha(&pilha);
        printf(" %s", palavra);
        free(palavra);
    }
    printf("\n");
    return 0;
}
