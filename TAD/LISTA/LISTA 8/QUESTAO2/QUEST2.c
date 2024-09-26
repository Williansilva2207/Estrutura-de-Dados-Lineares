#include <stdio.h>
#include <stdlib.h>
#include "LSE1.h"

int main(){
    LSE original;
    LSE copia;
    inicializar(&original);
    inicializar(&copia);
    inserirFinal(&original, 1);
    inserirFinal(&original, 2);
    inserirFinal(&original, 3);
    inserirFinal(&original, 4);
    inserirFinal(&original, 5);
    copiar(original, &copia);
    list(copia);
    return 0;
}