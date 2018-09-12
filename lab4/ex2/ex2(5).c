

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void main(){
for ( int i = 0; i < 5; i ++){
	fork();
//sleep(5);
}
sleep(5);
	printf("Hello\n");
}
