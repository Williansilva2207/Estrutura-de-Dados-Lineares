#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"
#define TAM 20

int main(){
    Queue pilha;
    inicializar(&pilha);
    srand(time(NULL));
    int decision;
    while(decision != 0){
        printf("O que você deseja:\nDigite 1: Gerar Senha\nDigite 2: Mostrar Senha\nDigite 0: Encerrar\n");
        scanf("%d", &decision);
        getchar();
        switch (decision){
        case 1:{
            int senha = (int) (1 + (rand()%21));
            Enqueue(&pilha, senha);
            printf("A sua senha é: %d\n\n", senha);
       
            break;
        }
        case 2:
            printf("SENHA: %d\n", Dequeue(&pilha));
            break;
            

        case 0:
        printf("Encerrando!...");
            exit(1);
            
        default:
            break;
        }
    }    
    return 0;
}