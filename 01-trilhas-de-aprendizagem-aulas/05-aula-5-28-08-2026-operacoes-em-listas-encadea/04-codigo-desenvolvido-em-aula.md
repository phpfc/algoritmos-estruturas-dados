# Código desenvolvido em aula:

Tipo: Página

#include <stdio.h>

#include <stdlib.h>

struct elemento2 {  
int info;  
struct elemento2 *prox, *ant;  
};  
typedef struct elemento2 Elemento2;

void insereordenado(Elemento2 **ini,int valor){  
Elemento2 *novo,*aux=*ini,*ant;  
novo = (Elemento2*) malloc(sizeof(Elemento2));  
novo->info = valor;  
novo->prox = NULL;  
novo->ant = NULL;  

if(*ini==NULL){  
*ini=novo;  
return;  
}  
if(valor<=aux->info){  
novo->prox=*ini;  
(*ini)->ant=novo;  
*ini=novo;  
return;  
}  
ant=*ini;  
while(aux!=NULL && aux->info<valor){  
ant=aux;  
aux=aux->prox;  
}  
if(aux==NULL){  
ant->prox=novo;  
novo->ant=ant;  
return;  
}  
novo->prox=aux;  
novo->ant=ant;  
ant->prox=novo;  
aux->ant=novo;  
}

void remove(Elemento2 **ini,int valor){  
Elemento2 *aux=*ini;   
if(aux!=NULL){  
if(aux->info==valor){  
*ini=(*ini)->prox;  
if(*ini!=NULL)  
(*ini)->ant=NULL;  
free(aux);  
return;  
}  
while(aux!=NULL && aux->info!=valor)  
aux=aux->prox;  
if(aux!=NULL){  
(aux->ant)->prox=aux->prox;  
if(aux->prox!=NULL)  
(aux->prox)->ant=aux->ant;  
free(aux);  
}  
}  
}

void escreve(Elemento2 *ini){  
Elemento2 *aux=ini;  
printf("\n\nLista:\n");  
while(aux!=NULL){  
printf("%d ",aux->info);  
aux=aux->prox;  
}   
}

int main(){  
Elemento2 *inicio=NULL;  

insereordenado(&inicio,3);  
escreve(inicio);  
insereordenado(&inicio,5);  
escreve(inicio);  
insereordenado(&inicio,2);  
escreve(inicio);  
insereordenado(&inicio,4);  
escreve(inicio);  
printf("\n\nremove:\n");  
remove(&inicio,4);  
escreve(inicio);  
remove(&inicio,2);  
escreve(inicio);  
remove(&inicio,5);  
escreve(inicio);  
remove(&inicio,3);  
escreve(inicio);  
}
