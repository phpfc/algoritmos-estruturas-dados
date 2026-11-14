#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INFO 16

typedef struct noA {
    char info[MAX_INFO];
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *criaNo(const char *info, TNoA *esq, TNoA *dir) {
    TNoA *novo = malloc(sizeof(TNoA));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strncpy(novo->info, info, MAX_INFO - 1);
    novo->info[MAX_INFO - 1] = '\0';
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

TNoA *operando(const char *valor) {
    return criaNo(valor, NULL, NULL);
}

TNoA *operador(const char *op, TNoA *esq, TNoA *dir) {
    return criaNo(op, esq, dir);
}

/* Percurso em ordem: os nodos internos são operadores e as folhas, operandos. */
void escreveExpressao(TNoA *a) {
    if (a == NULL)
        return;
    if (a->esq == NULL && a->dir == NULL) {
        printf("%s", a->info);
        return;
    }
    printf("(");
    escreveExpressao(a->esq);
    printf("%s", a->info);
    escreveExpressao(a->dir);
    printf(")");
}

void libera(TNoA *a) {
    if (a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}

int main(void) {
    TNoA *e1 = operador("+", operando("5"), operador("*", operando("3"), operando("4")));
    TNoA *e2 = operador("*", operador("+", operando("5"), operando("3")), operando("4"));
    /* 5+(3*4)-(2+1)/2 */
    TNoA *e3 = operador("-",
                        operador("+", operando("5"), operador("*", operando("3"), operando("4"))),
                        operador("/", operador("+", operando("2"), operando("1")), operando("2")));
    TNoA *e4 = operando("7");

    TNoA *expressoes[] = {e1, e2, e3, e4};
    int n = sizeof(expressoes) / sizeof(expressoes[0]);

    for (int i = 0; i < n; i++) {
        escreveExpressao(expressoes[i]);
        printf("\n");
        libera(expressoes[i]);
    }
    return 0;
}
