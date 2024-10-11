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

LDENode* criarNovo ( int valor){
    LDENode* aux;
    aux = (LDENode*) malloc (sizeof(LDENode));
    aux->info = valor;
    aux->ant = NULL; 
    aux->prox = NULL;

}

void inserir (LDE *list, int valor){
    LDENode*novo, *aux;

    if(isEmpty(*list)==TRUE){
        novo = criarNovo(valor);
        list->inicio = novo;
        list->fim = novo;
        list->qtd++;
    }
}