#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QUESTION2.h"
#define TAM 20

int main(){
    Queue pilha;
    inicializar(&pilha);
    srand(time(NULL));
    int decision;
    while(pilha.tamanho != 21){
        printf("O que você deseja:\nDigite 1: Gerar Senha\nDigite 2: Mostrar Senha\nDigite 0: Encerrar\n");
        scanf("%d", &decision);
        getchar();
        switch (decision){
        case 1:
            if(isFull(&pilha) == 1){
                printf("Infelizmente a senha esgotou, volte em outro momento.\n");
            }
            else{
                int senha = 1 + (rand()%21);
                Enqueue(&pilha, senha);
                printf("A sua senha é: %d\n\n", senha);

            }
            
            break;
        case 2:
            printf("SENHA: %d\n", Dequeue(&pilha));
        case 0:
        printf("Encerrando!...");
            exit(1);
            
        default:
            break;
        }
    }    
    return 0;
}