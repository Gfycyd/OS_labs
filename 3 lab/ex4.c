#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE(a) (sizeof(a)/sizeof(*a))
//
// Created by katukha on 05.09.18.
//
void swap(int *a, int *b){
    int  temp = *a;
    *a = *b;
    *b = temp;
}
void print_arr(int arr [], int size){
  for ( int i = 0; i< size; i++){
      printf("%d    ", arr[i]);
  }
  printf("\n");
}
int partion(int arr [], int i, int j){
    int pivot = arr[j];
    int low = (i - 1);
    for ( int h = i; h <= j- 1; h ++){
        if (arr[h] <= pivot ){
            low++;
            swap(&arr[low], &arr[h]);
        }
    }
    swap (&arr[low+1], &arr[j]);

    return low + 1;
}
void quick_sorting(int arr [], int i, int j){
    if (i < j) {


        int pivot = partion(arr, i, j);
        quick_sorting(arr, i, pivot - 1);
        quick_sorting(arr, pivot + 1, j);
    }
}
void quick_sort(int arr [], int size){
    int low = 0;
    int high = size - 1;
    quick_sorting(arr,low,high);
}
int main(){
   int arr [] = {17,2,10,3,9,18};
    int high = ARR_SIZE(arr);
    quick_sort(arr,high);
    print_arr(arr,high);
    return 0;
}