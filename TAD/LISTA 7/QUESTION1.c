#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
#define TAM 100
typedef struct{
    char nome[TAM];
} Nome;
Nome *alocar(int v );
void liberar(Nome *p);

int main(){
    Queue fila;
    inicializar(&fila);
    Nome *p;
    p = alocar(TAM);
    printf("Digite um nome:\n");
    fgets(p->nome,TAM, stdin);
    Enqueue(&fila, p->nome);
    
    char *nomeNaFila = head(&fila);
    if (nomeNaFila != NULL) {
        printf("Nome na cabeça da fila: %s\n", nomeNaFila);
    } else {
        printf("A fila está vazia.\n");
    }
    liberar(p);
    return 0;
}

Nome *alocar(int v ){
    Nome *c = (Nome*) malloc(sizeof(Nome)*v);
    if(c != NULL){
        return c;
    }
}
void liberar(Nome *p){
    free(p);
}