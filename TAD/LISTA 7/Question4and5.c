#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
void exibirOpcoes () {
    printf ("Opcoes \n");
    printf ("1 - Empilhar \n");
    printf ("2 - Desempilhar \n");
    printf ("3 - Ver topo \n");
    printf ("0 - Encerrar programa \n");
    printf ("Informe a opcao desejada: ");
}

int main () {
    Queue fila;
    char *c = (char*) malloc(sizeof(char));
    int op = -1;

    inicializar(&fila);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        getchar();
        switch (op) {
            case 1:
                printf ("Informe o valor a ser empilhado: ");
                fgets(c, sizeof(c), stdin);
                Enqueue (&fila,c);
                break;
            case 2: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        *c = Dequeue (&fila);
                        printf ("Valor desempilhado: %c\n", *c);
                    }
                    break;
            case 3: if (isEmpty (&fila) == 1) {
                        printf ("Stack empty! \n");
                    }
                    else {
                        *c = head (&fila);
                        printf ("Valor no topo da pilha: %c \n", *c);
                    }
                    break;
            case 0: printf ("Bye bye\n");
                    break;
            default: printf ("Opção inválida \n");
        }
    } while (op != 0);
    return 0;
}