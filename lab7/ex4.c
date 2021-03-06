//
// Created by Катя on 03.10.2018.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time.h"

void my_realloc(void * ptrmem, size_t size){
    typeof(ptrmem) * ptr = (typeof(ptrmem) *) ptrmem;
    if  (ptrmem == NULL) {
        ptrmem = malloc(size);
        return;
    }
    if (size == 0){
        free(ptrmem);
        return;
    }
    int * ptr2 = calloc(size/ sizeof(*ptrmem), size);
    ptr2 = memcpy(ptr2,ptr,size);

    ptr = malloc(size);
    ptr = memcpy(ptr, ptr2,size);

    free(ptr2);

}

int main(){
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = calloc(n1, n1* sizeof(int));/* Fill in*/
    int i;
    for(i=0; i<n1; i++){
        //Set each value in a1 to 100
        /*Fill in*/
        a1[i] =100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]/*Fill in*/ );
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size:");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    my_realloc(a1,n2* sizeof(int));
   // if (n2 > n1){
    //    for ( int i = 0; i < n2; i++){
      //      a1[i] = 0;
        //}
    //}
    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    /*
    Fill
    In
    */


    for(i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ",a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}