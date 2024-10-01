#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct ldenode{
    struct ldenode* ant;
    int info;
    struct ldenode* prox;    
    
}LDENode;

typedef struct lde{
    LDENode *inicio;
    LDENode *fim;
    int qtd; 
} LDE;

void inicializar(LDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDE l){
    if(l.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void inserirInicio(LDE *l, int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    if(isEmpty(*l) == TRUE){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void lista(LDE l){

}