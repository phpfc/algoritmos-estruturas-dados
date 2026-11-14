#include <stdio.h>
#include <string.h>

#define MAX_CARTAS 20
#define MAX_NAIPE  10

typedef struct {
    int valor;
    char naipe[MAX_NAIPE];
} Carta;

typedef struct {
    Carta cartas[MAX_CARTAS];
    int qtd;
} Jogo;

static int naipeValido(const char *naipe) {
    return strcmp(naipe, "ouros") == 0 || strcmp(naipe, "copas") == 0 ||
           strcmp(naipe, "paus") == 0 || strcmp(naipe, "espadas") == 0;
}

static int existeCarta(Jogo *j, Carta c) {
    for (int i = 0; i < j->qtd; i++)
        if (j->cartas[i].valor == c.valor && strcmp(j->cartas[i].naipe, c.naipe) == 0)
            return 1;
    return 0;
}

int recebe_carta(Jogo *j, Carta c) {
    if (j->qtd == MAX_CARTAS) {
        printf("Erro: a mao ja tem %d cartas\n", MAX_CARTAS);
        return 0;
    }
    if (c.valor < 1 || c.valor > 13) {
        printf("Erro: o valor deve estar entre 1 e 13\n");
        return 0;
    }
    if (!naipeValido(c.naipe)) {
        printf("Erro: naipe invalido (ouros, copas, paus ou espadas)\n");
        return 0;
    }
    if (existeCarta(j, c)) {
        printf("Erro: a carta %d de %s ja esta na mao\n", c.valor, c.naipe);
        return 0;
    }

    int i = j->qtd - 1;
    while (i >= 0 && j->cartas[i].valor > c.valor) {
        j->cartas[i + 1] = j->cartas[i];
        i--;
    }
    j->cartas[i + 1] = c;
    j->qtd++;
    return 1;
}

void ver_lista_cartas(Jogo *j) {
    if (j->qtd == 0) {
        printf("Nenhuma carta na mao\n");
        return;
    }
    for (int i = 0; i < j->qtd; i++)
        printf("%d: %d de %s\n", i + 1, j->cartas[i].valor, j->cartas[i].naipe);
}

int remover_carta(Jogo *j, int valor) {
    int i = 0;
    while (i < j->qtd && j->cartas[i].valor != valor)
        i++;
    if (i == j->qtd)
        return 0;
    for (; i < j->qtd - 1; i++)
        j->cartas[i] = j->cartas[i + 1];
    j->qtd--;
    return 1;
}

void exibe_trincas(Jogo *j) {
    int achou = 0;
    int i = 0;
    while (i < j->qtd) {
        int fim = i;
        while (fim < j->qtd && j->cartas[fim].valor == j->cartas[i].valor)
            fim++;
        if (fim - i >= 3) {
            achou = 1;
            printf("Trinca de %d:", j->cartas[i].valor);
            for (int k = i; k < i + 3; k++)
                printf(" %s", j->cartas[k].naipe);
            printf("\n");
        }
        i = fim;
    }
    if (!achou)
        printf("Nenhuma trinca na mao\n");
}

int main(void) {
    Jogo jogo;
    jogo.qtd = 0;

    int opcao;
    do {
        printf("\n1 - Receber carta\n");
        printf("2 - Ver lista de cartas\n");
        printf("3 - Remover carta\n");
        printf("4 - Exibir trincas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1)
            break;

        if (opcao == 1) {
            Carta c;
            printf("Valor (1 a 13): ");
            if (scanf("%d", &c.valor) != 1)
                break;
            printf("Naipe (ouros, copas, paus, espadas): ");
            if (scanf("%9s", c.naipe) != 1)
                break;
            if (recebe_carta(&jogo, c))
                printf("Carta inserida\n");
        } else if (opcao == 2) {
            ver_lista_cartas(&jogo);
        } else if (opcao == 3) {
            int valor;
            printf("Valor da carta a remover: ");
            if (scanf("%d", &valor) != 1)
                break;
            if (remover_carta(&jogo, valor))
                ver_lista_cartas(&jogo);
            else
                printf("Nao ha carta de valor %d na mao\n", valor);
        } else if (opcao == 4) {
            exibe_trincas(&jogo);
        } else if (opcao != 0) {
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
