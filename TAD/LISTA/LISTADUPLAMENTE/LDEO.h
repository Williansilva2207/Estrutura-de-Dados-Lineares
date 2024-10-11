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
    else if(valor == list->inicio->info){
        printf("Valor repetido, inserção não efetuada.\n");

    }
    else if (valor < list->inicio->info){
        novo = criarNovo(valor);
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
        list->qtd++;
    }
    else if(valor == list->fim->info){
        printf("Valor repetido, inserção não efetuada.\n");
    }
    else if (valor > list->fim->info){
        novo = criarNovo(valor);
        novo->ant = list->fim;
        list->fim->prox = novo;
        list->fim = novo;
        list->qtd++;
    }
}