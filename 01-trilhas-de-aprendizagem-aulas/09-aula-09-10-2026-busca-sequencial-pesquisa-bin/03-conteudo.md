# Conteúdo

Tipo: Página

**Noções básicas de complexidade de algoritmos:**

[Arquivo: Funções de complexidade de algoritmos](arquivos/complexidadebasicaapresentacao.pdf)

**Pesquisa binária (<https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria>)**

**Exemplo não recursivo:**

int PesquisaBinaria (int vet[], int chave, int Tam) {  
int inf = 0; // limite inferior (o primeiro índice de vetor em C é zero )  
int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)  
int meio;  
while (inf <= sup)  
{  
meio = (inf + sup)/2;  
if (chave == vet[meio])  
return meio;  
if (chave < vet[meio])  
sup = meio-1;  
else  
inf = meio+1;  
}  
return -1; // não encontrado  
}

**Exemplo recursivo:**

// x => chave | v[] => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)  
int PesquisaBinaria (int x, int v[], int e, int d) {  
int meio = (e + d)/2;  
if (v[meio] == x)  
return meio;  
if (e >= d)  
return -1; // não encontrado  
else  
if (v[meio] < x)  
return PesquisaBinaria(x, v, meio+1, d);  
else  
return PesquisaBinaria(x, v, e, meio-1);  
}

**Pesquisa binária poderia ser executada em listas encadeadas? Por quê?**

Site interativo para execução de pesquisa binária: <https://yongdanielliang.github.io/animation/web/BinarySearchNew.html>

**Tabelas Hash (pesquisa por cálculo de endereço)**

Na computação, uma tabela de dispersão (também conhecida por tabela de espalhamento ou tabela hash, do inglês hash) é uma estrutura de dados especial, que associa chaves de pesquisa a valores. Seu objetivo é, a partir de uma chave simples, calcular a localização do valor associado, e assim obter rapidamente o valor desejado.

<https://en.wikipedia.org/wiki/Hash_table>

Exemplos de cálculos que podem ser utilizados para funções hash, aplicadas a números inteiros: <https://en.wikipedia.org/wiki/Hash_function#Hashing_integer_data_types>

[Arquivo: Conteúdo.pdf](arquivos/conteudo.pdf)

Sites com simuladores de tabelas hash:

<https://opendsa-server.cs.vt.edu/ODSA/AV/Development/hashAV.html>

<http://users.csc.calpoly.edu/~jdalbey/103/Lectures/HashtableCalc.html>
