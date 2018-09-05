//
// Created by katukha on 05.09.18.
//

//exercise 2
#include <stdio.h>
#define ARR_SIZE(a) (sizeof(a)/sizeof(*a)) // size of variable
void swap( int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int n){
    for ( int i = 0; i < n; i ++){
        for ( int j = 0; j < n - i - 1; j ++){
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j+1]);
        }
    }
}
void print_arr(int arr [], int size){
    for ( int i = 0; i < size; i ++){
        printf("%d", arr[i]);
    }
}
int main(){
    int a [] = {7,6,5,4,3,2,1};

    int size = ARR_SIZE(a);
    bubble_sort(a,size);
    print_arr(a,size);
    return 0;
}