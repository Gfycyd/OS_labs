#include <stdio.h>
#include <printf.h>
#include <stdlib.h>
#include <signal.h>
//SIGSTOP doesn't change the state of 2 process, so parent never go after waitpid, but SIGKILL change it
int main(){
	int fd[2];
	pipe(fd);
	pid_t   process;
	pid_t p2;
	process = fork();
	if (process) {
		printf("parent\n");
		p2 = fork();
			if (p2) { //parent
				printf("parent write PID of 2 process\n");
				close(fd[0]);
				write(fd[1], &p2, sizeof(p2));
				close(fd[1]);
				int status;
				waitpid(p2,&status, WUNTRACED);
				printf("Parent now can start to work after 2nd finished with status %d\n", status);
				}
			else {
				printf("Now it is a 2nd process\n");
				while(1);
				
//2 child
				}
	}
	else // 1st child
	{	close(fd[1]);
		pid_t id;
		read(fd[0],&id, sizeof(id));
		close(fd[0]);
		printf("1st process send 2nd go to sleep in 2-3 sec\n");
		for ( int i = 0; i <2; i ++){
			printf("sleep....\n");
			sleep(1);
		}
		//printf("%d", id);
		kill(id, SIGKILL);
		printf("kill 2nd process by PID\n");
		exit(0);
	}	
	return 0;
}