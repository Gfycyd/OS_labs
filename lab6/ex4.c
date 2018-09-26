#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
#include <signal.h>

void handler_kill(int sig){
			printf("         It is a SIgKILL         ");
		exit(0);
}
void handler_stop(int sig){
			printf("         It is a SIGSTOP      ");
	exit(0);
}
void handler_usr(int sig){

			printf("         It is a SIGUSR1       ");
	exit(0);
}
 int main(){
	signal(SIGKILL, handler_kill);
	signal(SIGSTOP, handler_stop);
	signal(SIGUSR1, handler_usr);
	// when kill -SIGUSR1 then using handler upper, in other cases nothing happen just kill process
	while(1);
	return 0;
}

