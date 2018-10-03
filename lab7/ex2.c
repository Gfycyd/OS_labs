//
// Created by Катя on 03.10.2018.
//

#include <stdio.h>
#include <unistd.h>
#include "stdlib.h"
void main(){
    int N;
    scanf("%d", &N);
    int *array = calloc(N, N*sizeof(int));

    for (int i = 1; i < N; i ++){
        array[i] = array[i-1] + 1;
    }
    for ( int i = 0; i < N; i++){
        printf("%d", array[i]);
    }
    if (array != NULL){
        free(array);
    }

}
