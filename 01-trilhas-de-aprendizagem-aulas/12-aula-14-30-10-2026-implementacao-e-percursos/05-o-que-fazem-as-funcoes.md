# O que fazem as funções?

Tipo: Página

**O que fazem as funções (func1 e func2) a seguir?**

func1 (Nodo n) { <br>  if (n != null) { <br>  empilha(n); <br>  while (!pilha_vazia()) { <br>  n = desempilha(); <br>  escreve(n->valor); <br>  if (n->dir != null) <br>  empilha(n->dir); <br>  if (n->esq != null) <br>  empilha(n->esq); <br>  } <br>  } <br> } | func2 (Nodo n) { <br>  if (n != null) { <br>  enfileira(n); <br>  while (!fila_vazia()) { <br>  n = desenfileira(); <br>  escreve(n->valor); <br>  if (n->esq != null) <br>  enfileira(n->esq); <br>  if (n->dir != null) <br>  enfileira(n->dir); <br>  } <br>  } <br> }  
---|---
