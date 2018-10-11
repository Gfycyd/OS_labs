#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(){
void *p = NULL;
for ( int i = 0; i < 10; i ++){
	p = malloc(10 >> 20);
	memset(p, 0, 10 >> 20);
	sleep(1);
}
return 0;
}