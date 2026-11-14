# Aula 7 - 11/09/2026 - exercício de implementação com fila e listas encadeadas

Tipo: Tarefa com entrega · Prazo: 20/09/2026 23:59

Uma operadora possui uma impressora, compartilhada por seus usuários.

Essa impressora tem uma fila de impressão, para a qual os usuários enviam suas solicitações de impressão.

Os usuários são classificados em 3 categorias: prioridade máxima (0), prioridade normal (1) e prioridade baixa (2).

Para solicitar uma impressão, é utilizada a operação _**imprime(prioridade, trabalho)**_, e a impressão ocorre através da operação _**impressao( ).**_

A cada 2 impressões de prioridade máxima, a impressora imprime uma solicitação de prioridade normal. A cada 3 impressões de prioridade normal, a impressora imprime uma impressão de prioridade baixa.

**Implemente as operações de controle da impressora** (o parâmetro _**trabalho**_ pode ser um _string_).

## Minhas entregas

### Tentativa 1

Enviada em 19/09/2026 12:37 · Nota: 10

A resposta foi enviada como texto no AVA. O código está salvo em [aula-7-fila-impressora.c](arquivos/minhas-entregas/aula-7-fila-impressora.c):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMA 0
#define NORMAL 1
#define BAIXA  2

typedef struct No {
    char *trabalho;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

typedef struct {
    Fila filas[3];
    int contMaxima;
    int contNormal;
} Impressora;

Impressora impressora;

void inicializa(void) {
    for (int i = 0; i < 3; i++) {
        impressora.filas[i].inicio = NULL;
        impressora.filas[i].fim = NULL;
    }
    impressora.contMaxima = 0;
    impressora.contNormal = 0;
}

static int vazia(Fila *f) {
    return f->inicio == NULL;
}

static void enfileira(Fila *f, const char *trabalho) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    novo->trabalho = malloc(strlen(trabalho) + 1);
    if (novo->trabalho == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strcpy(novo->trabalho, trabalho);
    novo->prox = NULL;
    if (vazia(f))
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

static char *desenfileira(Fila *f) {
    if (vazia(f))
        return NULL;
    No *removido = f->inicio;
    char *trabalho = removido->trabalho;
    f->inicio = removido->prox;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(removido);
    return trabalho;
}

void imprime(int prioridade, const char *trabalho) {
    if (prioridade < MAXIMA || prioridade > BAIXA) {
        printf("Prioridade invalida: %d\n", prioridade);
        return;
    }
    enfileira(&impressora.filas[prioridade], trabalho);
}

static void executa(int prioridade) {
    char *trabalho = desenfileira(&impressora.filas[prioridade]);
    printf("Imprimindo [prioridade %d]: %s\n", prioridade, trabalho);
    free(trabalho);

    if (prioridade == MAXIMA) {
        impressora.contMaxima++;
    } else if (prioridade == NORMAL) {
        impressora.contMaxima = 0;
        impressora.contNormal++;
    } else {
        impressora.contNormal = 0;
    }
}

void impressao(void) {
    Fila *maxima = &impressora.filas[MAXIMA];
    Fila *normal = &impressora.filas[NORMAL];
    Fila *baixa  = &impressora.filas[BAIXA];

    if (impressora.contNormal >= 3 && !vazia(baixa))
        executa(BAIXA);
    else if (impressora.contMaxima >= 2 && !vazia(normal))
        executa(NORMAL);
    else if (!vazia(maxima))
        executa(MAXIMA);
    else if (!vazia(normal))
        executa(NORMAL);
    else if (!vazia(baixa))
        executa(BAIXA);
    else
        printf("Fila de impressao vazia\n");
}

void libera(void) {
    for (int i = 0; i < 3; i++) {
        char *t;
        while ((t = desenfileira(&impressora.filas[i])) != NULL)
            free(t);
    }
}

int main(void) {
    inicializa();

    char nome[32];
    for (int i = 1; i <= 10; i++) {
        sprintf(nome, "max-%d", i);
        imprime(MAXIMA, nome);
    }
    for (int i = 1; i <= 6; i++) {
        sprintf(nome, "normal-%d", i);
        imprime(NORMAL, nome);
    }
    for (int i = 1; i <= 3; i++) {
        sprintf(nome, "baixa-%d", i);
        imprime(BAIXA, nome);
    }

    for (int i = 0; i < 20; i++)
        impressao();

    libera();
    return 0;
}
```
