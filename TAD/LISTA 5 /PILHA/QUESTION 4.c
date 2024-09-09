#include <stdio.h>
#include <stdlib.h>
#include "POXA.h"


int main () {
    POXA *f;
    inicializar(f);
    int num;
    printf("Put one number: ");
    scanf("%d", &num);
    enQueue(f,num);
    printf("%d", head(f));
    return 0;
}