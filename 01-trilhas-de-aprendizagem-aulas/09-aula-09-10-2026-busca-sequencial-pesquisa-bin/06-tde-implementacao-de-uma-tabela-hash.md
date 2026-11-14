# TDE: implementação de uma tabela hash

Tipo: Tarefa com entrega · Prazo: 15/10/2026 23:59

Implementar uma tabela _hash_(por endereçamento aberto - as listas encadeadas armazenam as colisões) para incluir nomes de cidades brasileiras:

\- defina o **tamanho da tabela** a partir de algum critério que faça sentido (!)

\- defina uma **função** _**hash** _para transformar o nome da cidade (que é a chave) em um endereço da tabela

\- insira pelo menos uns 50 nomes de cidades na tabela _hash_ , e depois pesquise alguns nomes.

## Minhas entregas

### Tentativa 1

Enviada em 12/10/2026 15:03

A resposta foi enviada como texto no AVA. O código está salvo em [tde-implementacao-de-uma-tabela-hash.c](arquivos/minhas-entregas/tde-implementacao-de-uma-tabela-hash.c):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 71

typedef struct No {
    char nome[64];
    struct No *prox;
} No;

No *tabela[TAM];

unsigned int hash(const char *s) {
    unsigned long h = 5381;
    while (*s) {
        h = h * 33 + (unsigned char)*s++;
    }
    return h % TAM;
}

void inserir(const char *nome) {
    unsigned int i = hash(nome);
    No *novo = malloc(sizeof(No));
    strncpy(novo->nome, nome, 63);
    novo->nome[63] = '\0';
    novo->prox = NULL;
    if (tabela[i] == NULL) {
        tabela[i] = novo;
        return;
    }
    No *aux = tabela[i];
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

int buscar(const char *nome) {
    No *aux = tabela[hash(nome)];
    while (aux != NULL) {
        if (strcmp(aux->nome, nome) == 0) {
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void imprimir() {
    for (int i = 0; i < TAM; i++) {
        printf("%2d:", i);
        for (No *aux = tabela[i]; aux != NULL; aux = aux->prox) {
            printf(" %s ->", aux->nome);
        }
        printf(" NULL\n");
    }
}

int main() {
    const char *cidades[] = {
        "Caxias do Sul", "Porto Alegre", "Sao Paulo", "Rio de Janeiro",
        "Belo Horizonte", "Curitiba", "Florianopolis", "Salvador", "Recife",
        "Fortaleza", "Brasilia", "Manaus", "Belem", "Goiania", "Campinas",
        "Santos", "Gramado", "Canela", "Bento Goncalves", "Farroupilha",
        "Flores da Cunha", "Garibaldi", "Carlos Barbosa", "Veranopolis",
        "Passo Fundo", "Santa Maria", "Pelotas", "Rio Grande", "Canoas",
        "Novo Hamburgo", "Sao Leopoldo", "Gravatai", "Viamao", "Uruguaiana",
        "Joinville", "Blumenau", "Londrina", "Maringa", "Ribeirao Preto",
        "Uberlandia", "Vitoria", "Natal", "Joao Pessoa", "Maceio", "Aracaju",
        "Teresina", "Sao Luis", "Cuiaba", "Campo Grande", "Palmas", "Macapa",
        "Boa Vista", "Rio Branco", "Porto Velho", "Ouro Preto"
    };
    int n = sizeof(cidades) / sizeof(cidades[0]);

    for (int i = 0; i < n; i++) {
        inserir(cidades[i]);
    }

    imprimir();

    const char *consultas[] = {"Caxias do Sul", "Gramado", "Ouro Preto", "Atlantis", "Pelotas"};
    for (int i = 0; i < 5; i++) {
        printf("%s: %s\n", consultas[i], buscar(consultas[i]) ? "encontrada" : "nao encontrada");
    }

    return 0;
}
```
