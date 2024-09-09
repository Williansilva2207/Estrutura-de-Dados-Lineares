#include <stdlib.h>

typedef struct stackNode {
    int info;
    struct stackNode* prox;
} StackNode;

typedef StackNode* Stack;

void inicializar (Stack* s) {
    *s = NULL;
}

int isEmpty (Stack s) {
    if (s == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull (Stack s) {
    return 0;
}

void push (Stack* s, int valor) {
    StackNode* novo;
    novo = (StackNode*) malloc (sizeof(StackNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*s) == 1) {
        *s = novo;
    }
    else {
        novo->prox = *s;
        *s = novo;
    }
}

int pop (Stack* s) {
    StackNode* aux = *s;
    int valor;
    *s = (*s)->prox;
    valor = aux->info;
    free(aux);
    return valor;
}

int top (Stack s) {
    return s->info;
}
