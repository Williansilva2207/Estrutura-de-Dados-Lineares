#include <stdlib.h>

typedef struct stackNode StackNode;

typedef StackNode* Stack;

void inicializar (Stack* s);

int isEmpty (Stack s);

int isFull (Stack s);

void push (Stack* s, int valor);
int pop (Stack* s);

int top (Stack s);
