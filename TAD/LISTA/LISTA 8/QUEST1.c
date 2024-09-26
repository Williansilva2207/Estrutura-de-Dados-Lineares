#include <stdio.h>
#include <stdlib.h>
#include "LSE1.h"

int main(){
    LSE original;
    LSE list2;
    LSE list3;
    inicializar(&original);
    inicializar(&list2);
    inicializar(&list3);
    inserirFinal(&original, 1);
    inserirFinal(&original, 2);
    inserirFinal(&original, 3);
    inserirFinal(&original, 4);
    inserirFinal(&original, 5);
    inserirFinal(&list2, 10);
    inserirFinal(&list2, 12);
    inserirFinal(&list2, 13);
    inserirFinal(&list2, 14);
    inserirFinal(&list2, 15);
    somar(original, list2, &list3);
    list(list3);
    return 0;
}