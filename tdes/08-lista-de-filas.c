#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_IMPRESSORAS 3
#define MAX_NOME 50

typedef struct Documento {
    int codigo;
    char nome[MAX_NOME];
    struct Documento *prox;
} Documento;

typedef struct {
    Documento *inicio;
    Documento *fim;
    int qtd;
} Fila;

Fila impressoras[NUM_IMPRESSORAS];

void inicializa(void) {
    for (int i = 0; i < NUM_IMPRESSORAS; i++) {
        impressoras[i].inicio = NULL;
        impressoras[i].fim = NULL;
        impressoras[i].qtd = 0;
    }
}

void exibeFila(int impressora) {
    Fila *f = &impressoras[impressora];
    printf("Impressora %d (%d na fila):", impressora, f->qtd);
    for (Documento *d = f->inicio; d != NULL; d = d->prox)
        printf(" [%d %s]", d->codigo, d->nome);
    printf("\n");
}

void libera(void) {
    for (int i = 0; i < NUM_IMPRESSORAS; i++) {
        Documento *d = impressoras[i].inicio;
        while (d != NULL) {
            Documento *prox = d->prox;
            free(d);
            d = prox;
        }
    }
    inicializa();
}

int main(void) {
    inicializa();
    for (int i = 0; i < NUM_IMPRESSORAS; i++)
        exibeFila(i);
    libera();
    return 0;
}
