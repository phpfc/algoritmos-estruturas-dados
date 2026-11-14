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

TNoA *menor(TNoA *a) {
    while (a->esq != NULL)
        a = a->esq;
    return a;
}

/* nodo com dois filhos é substituído pelo menor da subárvore direita */
TNoA *removeNo(TNoA *a, const char *nome, int *removeu) {
    if (a == NULL) {
        *removeu = 0;
        return NULL;
    }
    int cmp = strcmp(nome, a->nome);
    if (cmp < 0) {
        a->esq = removeNo(a->esq, nome, removeu);
    } else if (cmp > 0) {
        a->dir = removeNo(a->dir, nome, removeu);
    } else {
        *removeu = 1;
        if (a->esq == NULL || a->dir == NULL) {
            TNoA *filho = a->esq != NULL ? a->esq : a->dir;
            free(a);
            return filho;
        }
        TNoA *sucessor = menor(a->dir);
        strcpy(a->nome, sucessor->nome);
        int aux;
        a->dir = removeNo(a->dir, sucessor->nome, &aux);
    }
    return balanceia(a);
}

/* retorna o nodo do bicho (ou NULL) e conta as comparações feitas na busca */
TNoA *consulta(TNoA *a, const char *nome, int *comparacoes) {
    *comparacoes = 0;
    while (a != NULL) {
        (*comparacoes)++;
        int cmp = strcmp(nome, a->nome);
        if (cmp == 0)
            return a;
        if (cmp < 0)
            a = a->esq;
        else
            a = a->dir;
    }
    return NULL;
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

int leLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL)
        return 0;
    destino[strcspn(destino, "\n")] = '\0';
    return 1;
}

int main(void) {
    TNoA *raiz = NULL;
    /* carga inicial em ordem alfabética, para forçar as rotações */
    const char *bichos[] = {"anta", "baleia", "capivara", "elefante", "foca", "gato",
                            "hiena", "jacare", "leao", "macaco", "onca", "pato",
                            "quati", "rato", "sapo", "tatu", "urso", "zebra"};
    int n = sizeof(bichos) / sizeof(bichos[0]);
    int ok;

    for (int i = 0; i < n; i++)
        raiz = insere(raiz, bichos[i], &ok);

    char linha[MAX_NOME];
    char nome[MAX_NOME];
    int opcao = -1;
    do {
        printf("\n1 - Inserir bicho\n");
        printf("2 - Consultar bicho\n");
        printf("3 - Remover bicho\n");
        printf("4 - Exibir em ordem alfabetica\n");
        printf("5 - Exibir arvore com fatores de balanceamento\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        if (!leLinha(linha, MAX_NOME))
            break;
        if (sscanf(linha, "%d", &opcao) != 1)
            opcao = -1;

        if (opcao >= 1 && opcao <= 3) {
            printf("Nome do bicho: ");
            if (!leLinha(nome, MAX_NOME))
                break;
            if (nome[0] == '\0') {
                printf("Nome vazio\n");
                continue;
            }
        }

        if (opcao == 1) {
            raiz = insere(raiz, nome, &ok);
            if (ok)
                printf("%s inserido\n", nome);
            else
                printf("%s ja esta na arvore\n", nome);
        } else if (opcao == 2) {
            int comparacoes;
            if (consulta(raiz, nome, &comparacoes) != NULL)
                printf("%s encontrado com %d comparacoes\n", nome, comparacoes);
            else
                printf("%s nao encontrado (%d comparacoes)\n", nome, comparacoes);
        } else if (opcao == 3) {
            raiz = removeNo(raiz, nome, &ok);
            if (ok)
                printf("%s removido\n", nome);
            else
                printf("%s nao esta na arvore\n", nome);
        } else if (opcao == 4) {
            if (raiz == NULL)
                printf("Arvore vazia\n");
            exibeEmOrdem(raiz);
        } else if (opcao == 5) {
            if (raiz == NULL)
                printf("Arvore vazia\n");
            else
                printf("Altura: %d\n", altura(raiz));
            exibeArvore(raiz, 0);
        } else if (opcao != 0) {
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    libera(raiz);
    return 0;
}
