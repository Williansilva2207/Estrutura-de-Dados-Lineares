#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TAM 100

typedef struct information{
    char nome[100];
    int mat;
    double media; 
    int falta;
}Information;

typedef struct ldenode{
    struct ldenode *ant;
    struct ldenode *prox;
    Information *info;
}LDENode;

typedef struct ldecirc{
    LDENode *inicio;
    LDENode *fim;
    int qtd;
}LDECirc;

void inicializar(LDECirc *list){
    list->inicio = NULL;
    list->fim = NULL;
    list->qtd = 0;
}

int isEmpty(LDECirc list){
    if(list.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

LDENode *criarNo(char name[], int matricula, double media, int faltas){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->prox = NULL;
    novo->ant = NULL;
    strcpy(novo->info->nome, name);
    novo->info->mat = matricula;
    novo->info->media = media;
    novo->info->falta = faltas;
    return novo;
}

void inserirOrdenado(char name[],int matricula, double media, int faltas, LDECirc *list){
    LDENode *novo;
    if(isEmpty(*list)==TRUE){
        novo = criarNo(name, matricula, media, faltas);
        list->inicio = novo;
        list->fim = novo;
        novo->prox = novo;
        novo->ant = novo;
        list->qtd = 1;
    }else if(strcmp(name,list->inicio->info->nome) == 0){
        printf("Aluno ja esta registrado.\n");
    }else if(strcmp(name,list->inicio->info->nome) < 0){
        novo = criarNo(name, matricula, media, faltas);
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
        list->fim->prox = list->inicio;
        list->inicio->ant = list->fim;
        list->qtd ++;
    }else if(strcmp(name,list->fim->info->nome) == 0){
        printf("Aluno ja esta registrado.\n");
    }else if(strcmp(name,list->fim->info->nome) > 0){
        novo = criarNo(name, matricula, media, faltas);
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
        list->fim->prox = list->inicio;
        list->inicio->ant = list->fim;
        list->qtd ++;
    }else{
        LDENode *aux;
        LDENode *bef;
        aux = list->inicio->prox;
        while(TRUE){
            if(strcmp(name, aux->info->nome)==0){
                printf("Aluno ja esta registrado.\n");
                return;
            }else if(strcmp(name, aux->info->nome) < 0){
                novo = criarNo(name, matricula, media, faltas);
                bef = aux->ant;
                novo->prox = aux;
                aux->ant = novo;
                bef->prox = novo;
                novo->ant = bef;
                list->qtd ++;
                return;
            }else{
                aux = aux->prox;
            }
        }
    }
}