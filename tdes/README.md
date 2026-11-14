# TDEs

Implementações em C dos TDEs da disciplina. O enunciado de cada um está na pasta da aula correspondente, em [`01-trilhas-de-aprendizagem-aulas`](../01-trilhas-de-aprendizagem-aulas/).

| Arquivo | TDE | Entrada |
|---|---|---|
| [02-lista-vetores-cartas.c](02-lista-vetores-cartas.c) | Lista de cartas em vetor, com inserção ordenada, remoção e trincas | menu |
| [03-lista-encadeada-ordenada.c](03-lista-encadeada-ordenada.c) | Inserção ordenada e remoção (por valor e por posição) em lista encadeada simples de nomes | demonstração fixa |
| [05-palindrome-lista-dupla.c](05-palindrome-lista-dupla.c) | Verificação de palíndrome em lista duplamente encadeada | demonstração fixa |
| [06-inverte-palavras-pilha.c](06-inverte-palavras-pilha.c) | Escreve as palavras de um texto em ordem invertida usando pilha | texto digitado |
| [08-lista-de-filas.c](08-lista-de-filas.c) | Filas de impressão de 3 impressoras: enviar, imprimir e cancelar | demonstração fixa |
| [15-expressao-arvore-binaria.c](15-expressao-arvore-binaria.c) | Escreve a expressão de uma árvore binária totalmente parentizada | demonstração fixa |
| [16-avl-bichos.c](16-avl-bichos.c) | AVL de nomes de bichos: inserir, consultar e remover | menu |

Os TDEs já entregues pelo AVA (TAD, fila de impressora com prioridades, tabela hash e ABP) estão em `arquivos/minhas-entregas/` da aula correspondente.

## TDE: implementação de uma AVL

Prazo: 26/11/2026 23:30.

> Implementar (ou testar a implementação) de uma AVL que armazene nomes de bichos: inserir, consultar e remover.

## Como compilar

```sh
gcc -Wall -Wextra -std=c99 -o avl tdes/16-avl-bichos.c
./avl
```

## Trabalhos

Os trabalhos de implementação ficam em repositórios próprios:

- [aed-trabalho-lista-de-impressoras](https://github.com/phpfc/aed-trabalho-lista-de-impressoras)
- [aed-trabalho-esportes-atletas](https://github.com/phpfc/aed-trabalho-esportes-atletas)
