#include <stdio.h>
#include <stdlib.h>
#include "Stack5.h"
int main()
{
    Stack pilha;
    inicializar(&pilha);
    int num;
    printf("Digite o número:\n");
    scanf("%d", &num);
    getchar();
    while(num != 0){
        int valor = num%2;
        push(&pilha, valor);
        num = num /2;
    }
    
    while(isEmpty(pilha) == 0){
        printf("%d", pop(&pilha));
    }
    printf("\n");
    return 0;
}