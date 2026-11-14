# Conteúdo

Tipo: Página

Para percorrer uma árvore, é preciso usar um método que consiga passar por todos os elementos da árvore, sem esquecer nenhum e sem repetir nodos. Para tanto, usa-se os **percursos (ou caminhamentos, ou enumerações)** , métodos que percorrem os elementos da árvore em largura (nível a nível) ou em profundidade (para cada nodo, segue-se os caminhos em direção às folhas).

[Arquivo: Árvores binárias_ caminhamentos.pdf](arquivos/arvores-binarias-caminhamentos.pdf)

Os percursos em profundidade percorrem os elementos das árvores em alguma ordem, entre várias possíveis:

**\- pré-ordem (ou ordem pré-fixada)**

**\- central (ou em ordem)**

**\- pós-ordem (ou ordem pós-fixada)**

**Exemplos em C:**

typedef struct noA{  
char info;  
struct noA *esq;  
struct noA *dir;  
} TNoA;

void posOrdem(TNoA* a){  
if (a!= NULL){  
posOrdem(a->esq);  
posOrdem(a->dir);  
printf("%c\n",a->info);  
}  
}

void central(TNoA* a){  
if (a!= NULL){  
central(a->esq);  
printf("%c\n",a->info);  
central(a->dir);  
}  
}

void preordem(TNoA* a){  
if (a!= NULL){  
printf("%c\n",a->info);  
preordem(a->esq);  
preordem(a->dir);  
}  
}

TNoA *criaNo(char ch) {  
TNoA *novo;  
novo = (TNoA *) malloc(sizeof(TNoA));  
novo->info = ch;  
novo->esq = NULL;  
novo->dir = NULL;  
return novo;  
}

int main(void) {  
TNoA *raiz;  
raiz = criaNo('A');  
raiz->esq = criaNo('B');  
raiz->dir = criaNo('C');  
raiz->dir->esq = criaNo('D');  
raiz->dir->dir = criaNo('E');  
};  

**Aplicações de árvores binárias: ABPs**

**Árvores binárias de pesquisa (ABPs):**

As ABPs apresentam regras específicas para inserção de dados na árvore binária. Essas regras de inserção possibilitam a utilização das ABPs como estruturas que ordenam dados. Pode-se então obter uma enumeração ordenada dos dados, o que ocorre a partir de um caminhamento (ou percurso) central na ABP. Pode-se também pesquisar mais rapidamente os dados, pois a pesquisa passa a ser uma pesquisa binária.

[Arquivo: Aplicações de árvores binárias](arquivos/arvoresabpeaplicacoes.pdf)
