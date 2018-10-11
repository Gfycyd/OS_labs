#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <stdlib.h>
int main(){
void *p = NULL;


for ( int i = 0; i < 100; i ++){
	p = malloc(10 >> 20);
	memset(p, 0, 10 >> 20);
	 struct rusage help;
        getrusage(RUSAGE_SELF, &help);
        printf("%lu \n", help.ru_maxrss);
	sleep(1);
}
return 0;
}