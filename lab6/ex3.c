#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sig_hand(int sig){
	printf("\nit is a SIGINT\n");

}
int main(){
	signal(SIGINT, sig_hand);
	while(1);
	return 0;
}