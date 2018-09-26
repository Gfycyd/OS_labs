#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
#include <signal.h>

int main(){
pid_t child;
child =  fork();
if (child == 0){
	
	while(1) {

		printf("I am alive\n");
		fflush(stdout);
			sleep(1);
}
}
else if (child > 0 ){
	sleep(10);
	kill(child, SIGTERM);
}
return 0;
}