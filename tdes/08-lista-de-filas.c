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

void enviaDocumento(int impressora, int codigo, const char *nome) {
    Fila *f = &impressoras[impressora];
    Documento *novo = malloc(sizeof(Documento));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    novo->codigo = codigo;
    strncpy(novo->nome, nome, MAX_NOME - 1);
    novo->nome[MAX_NOME - 1] = '\0';
    novo->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    f->qtd++;
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
    enviaDocumento(0, 1, "relatorio.pdf");
    enviaDocumento(0, 2, "boleto.pdf");
    enviaDocumento(1, 3, "foto.png");
    enviaDocumento(0, 4, "contrato.docx");
    for (int i = 0; i < NUM_IMPRESSORAS; i++)
        exibeFila(i);
    libera();
    return 0;
}
