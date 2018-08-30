
#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[])
{
	int a,b;
	void swap(int * , int * );
	scanf("%d",&a);
    scanf("%d",&b);
    printf("Before Swap: %d   %d \n",a, b );
	swap(&a, &b);
	
	printf("After swap: %d   %d", a, b);
	return 0;
}
void swap(int * a, int * b){
	int c = *a;
	*a = *b;
	*b = c;
	
}
