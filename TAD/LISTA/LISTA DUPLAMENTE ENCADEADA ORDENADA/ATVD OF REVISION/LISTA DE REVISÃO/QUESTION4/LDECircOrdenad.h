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