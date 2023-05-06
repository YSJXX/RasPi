#include <stdio.h>
#include <stdlib.h>
#include "cui.h"

CuiData cui(){ // Wellcom Print
    CuiData cuiData;

    for(int count=0;count<10;++count){
        system("clear");
        printf("\n");
        printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf("\t\t\t┃ Mode selection (Input num) ┃ \n");
        printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ \n\n\n");
        printf("\t\t\t  1. online \t 2. offline \n\n");
        printf("\t\t\t input (1 or 2): ");
        scanf("%d",&cuiData.select);
        if(cuiData.select == 1 || cuiData.select == 2) break;
    }
    return cuiData;
}